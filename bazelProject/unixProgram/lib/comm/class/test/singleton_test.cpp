#include "lib/comm/class/singleton.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>

class A : public comm::Singleton<A, int, int> {
    public:
    A(int numm, int numb) : m_num(numm), m_numb(numb){};
    ~A() = default;
    int Get() {
        return m_num;
    }

    int GetB() {
        return m_numb;
    }
    
    private:
    int m_num, m_numb;
};

class B : public comm::SingletonMutex<B, int, int> {
    public:
    B(int numm, int numb) : m_num(numm), m_numb(numb){};
    ~B() = default;
    int Get() {
        return m_num;
    }

    int GetB() {
        return m_numb;
    }
    
    private:
    int m_num, m_numb;
};

class C : public comm::SingletonStatic<C> {
    public:
    private:
};

class D : public comm::SingletonStatic1<D> {
    public:
    private:
};

TEST(case_1, content)
{
    auto pOject = A::GetInstance(123, 321);
    EXPECT_EQ(pOject->Get(), 123);
    EXPECT_EQ(pOject->GetB(), 321);

    auto pOject1 = A::GetInstance(124,123);
    EXPECT_EQ(pOject1->Get(), 123);
    EXPECT_EQ(pOject1->GetB(), 321);
    EXPECT_EQ((uint64_t)pOject1, (uint64_t)pOject1);

    A::Destory();
}

TEST(case_2, content)
{
    auto pOject = B::GetInstance(123, 321);
    EXPECT_EQ(pOject->Get(), 123);
    EXPECT_EQ(pOject->GetB(), 321);

    auto pOject1 = B::GetInstance(124,123);
    EXPECT_EQ(pOject1->Get(), 123);
    EXPECT_EQ(pOject1->GetB(), 321);
    EXPECT_EQ((uint64_t)pOject1, (uint64_t)pOject1);

    B::Destory();
}


TEST(case_3, content)
{
    auto pOject = C::GetInstance();
    auto pOject1 = C::GetInstance();
    EXPECT_EQ((uint64_t)pOject1, (uint64_t)pOject1);
}


// TEST(case_4, content)
// {
//     auto pOject = D::GetInstance();
//     auto pOject1 = D::GetInstance();
//     EXPECT_EQ((uint64_t)pOject1, (uint64_t)pOject1);
// }