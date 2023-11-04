#include "spinlook.h"
#include "gtest/gtest.h"
#include <functional>
#include <thread>

int f1(std::string & sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    printf("core num = %d\n", num);
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(1 % num, &mask);// 设置亲和力值
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    sleep(1);
    SpinLock oLock;
    oLock.Lock();
    sStr.append("LockSucc1");
    oLock.UnLock();
    sStr.append("UnLockSucc1");
    return 0;
}

int f2(std::string& sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(2 % num, &mask);// 设置亲和力值
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    SpinLock oLock;
    oLock.Lock();
    sStr.append("LockSucc2");
    sleep(2);
    oLock.UnLock();
    sStr.append("UnLockSucc2");
    return 0;
}

int f3(std::string & sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    printf("core num = %d\n", num);
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(1 % num, &mask);// 设置亲和力值
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    sleep(1);
    SpinLockAtomic oLock;
    oLock.Lock();
    sStr.append("LockSucc1");
    oLock.UnLock();
    sStr.append("UnLockSucc1");
    return 0;
}

int f4(std::string& sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(2 % num, &mask);// 设置亲和力值, 绑核心这里要取余
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    SpinLockAtomic oLock;
    oLock.Lock();
    sStr.append("LockSucc2");
    sleep(2);
    oLock.UnLock();
    sStr.append("UnLockSucc2");
    return 0;
}


int f5(std::string & sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    printf("core num = %d\n", num);
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(1 % num, &mask);// 设置亲和力值
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    sleep(1);
    SpinLockAtomic oLock;
    ScopeSpinLockAtomic oLockHandle(oLock);
    sStr.append("LockSucc1");
    sStr.append("UnLockSucc1");
    return 0;
}

int f6(std::string& sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(2 % num, &mask);// 设置亲和力值
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    SpinLock oLock;
    oLock.Lock();
    sStr.append("LockSucc2");
    sleep(2);
    oLock.UnLock();
    sStr.append("UnLockSucc2");
    return 0;
}

int f7(std::string & sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    printf("core num = %d\n", num);
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(1 % num, &mask);// 设置亲和力值
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    sleep(1);
    SpinLockAtomic oLock;
    ScopeSpinLockAtomic oLockHandle(oLock);
    sStr.append("LockSucc1");
    sStr.append("UnLockSucc1");
    return 0;
}

int f8(std::string& sStr) {

#ifndef __APPLE__
    int num = sysconf(_SC_NPROCESSORS_CONF);// 获取核数
    cpu_set_t mask;// cpu核的集合
    cpu_set_t get;// 获取在集合中的cpu
    CPU_ZERO(&mask);// 将集合置为空集
    CPU_SET(2 % num, &mask);// 设置亲和力值, 绑核心这里要取余
    
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&mask)==-1)// 设置线程cpu亲和力
    {
        printf("warning: could not set CPU affinity, continuing...\n");
    }
#endif

    SpinLockAtomic oLock;
    oLock.Lock();
    sStr.append("LockSucc2");
    sleep(2);
    oLock.UnLock();
    sStr.append("UnLockSucc2");
    return 0;
}

TEST(case_1, content) {
    std::string sAns = "LockSucc2UnLockSucc2LockSucc1UnLockSucc1";
    std::string str;
    std::thread t1(f1, std::ref(str));
    std::thread t2(f2, std::ref(str));

    t1.join();
    t2.join();
}

TEST(case_2, content) {
    std::string sAns = "LockSucc2UnLockSucc2LockSucc1UnLockSucc1";
    std::string str;
    std::thread t1(f3, std::ref(str));
    std::thread t2(f4, std::ref(str));

    t1.join();
    t2.join();
}

TEST(case_3, content) {
    std::string sAns = "LockSucc2UnLockSucc2LockSucc1UnLockSucc1";
    std::string str;
    std::thread t1(f1, std::ref(str));
    std::thread t2(f2, std::ref(str));

    t1.join();
    t2.join();
}

TEST(case_4, content) {
    std::string sAns = "LockSucc2UnLockSucc2LockSucc1UnLockSucc1";
    std::string str;
    std::thread t1(f3, std::ref(str));
    std::thread t2(f4, std::ref(str));

    t1.join();
    t2.join();
}