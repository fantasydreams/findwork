#pragma once

#include <thread>
#include <type_traits>
#include <utility>
#include <vector>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <future>
#include <functional>
#include <stdexcept>
#include <memory>
#include "lib/comm/class/exception.h"

// 初始化线程池
// 销毁线城市
// 任务
// 消费者唤醒调度

class ThreadPool : public std::enable_shared_from_this<ThreadPool> {
public:
    ThreadPool(int iThreadCnt);

    template<class Func, typename... Args>
    auto Enqueue(Func&& f, Args&&... args) -> std::future<typename std::result_of<Func(Args...)>::type> {
        using returnType = typename std::result_of<Func(Args...)>::type;
        auto poTask = std::make_shared<std::packaged_task<returnType()>>(   // 打包任务 packaged_task
            std::bind(std::forward<Func>(f), std::forward<Args>(args)...));
        
        auto oRes = poTask->get_future();
        {
            std::unique_lock<std::mutex> oLock(m_oQueMutex);
            if(m_bStop) {
                throw ThreadException(-1, "thread pool stoped", false);
            }

            m_queTasks.emplace([poTask]() {
                (*poTask)();
            });
        }
        m_oCondition.notify_one();
        return oRes;
    }

    ~ThreadPool();
private:

    // 线程池woker
    void ThreadWokerMain();

    //线程池
    int m_iThreadCnt;
    std::vector<std::thread> m_vecWorkers;
    
    //任务
    std::queue<std::function<void()> > m_queTasks;

    // 同步
    std::mutex m_oQueMutex;
    std::condition_variable m_oCondition;

    //周期
    bool m_bStop;
};