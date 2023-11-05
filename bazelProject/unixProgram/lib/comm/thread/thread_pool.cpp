#include "thread_pool.h"
#include <cassert>
#include <mutex>

ThreadPool::ThreadPool(int iThreadCnt) : m_iThreadCnt(iThreadCnt), m_bStop(false) {
    assert(iThreadCnt > 0);
    for(int i = 0; i < iThreadCnt; ++i) {
        // m_vecWorkers.emplace_back([this]() {
        //     for(;;) {
        //         std::function<void()> oTask; {
        //             std::unique_lock<std::mutex> oLock(this->m_oQueMutex);
        //             this->m_oCondition.wait(oLock, [this]() {
        //                 return this->m_bStop || !this->m_queTasks.empty(); // 线程池停止或者有任务的时候唤醒
        //             });

        //             if(this->m_bStop && this->m_queTasks.empty()) { // 停止且没有任务的时候，此worker终止生命周期
        //                 return;
        //             }

        //             oTask = std::move(this->m_queTasks.front());
        //             this->m_queTasks.pop();
        //         }

        //         oTask();
        //     }
        // });

        m_vecWorkers.emplace_back(&ThreadPool::ThreadWokerMain, this);
    }
}

void ThreadPool::ThreadWokerMain(){
    for(;;) {
        std::function<void()> oTask; {
            std::unique_lock<std::mutex> oLock(this->m_oQueMutex);
            this->m_oCondition.wait(oLock, [this]() {
                return this->m_bStop || !this->m_queTasks.empty(); // 线程池停止或者有任务的时候唤醒
            });

            if(this->m_bStop && this->m_queTasks.empty()) { // 停止且没有任务的时候，此worker终止生命周期
                return;
            }

            oTask = std::move(this->m_queTasks.front());
            this->m_queTasks.pop();
        }

        oTask();
    }
}

ThreadPool::~ThreadPool(){
    {
        std::unique_lock<std::mutex> oLock(m_oQueMutex);
        this->m_bStop = true;
    }

    m_oCondition.notify_all();
    for(int i = 0; i < m_iThreadCnt; ++i) {
        m_vecWorkers[i].join();
    }
}