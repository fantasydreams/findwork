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

// 测试RR
TEST(case_1, content)
{
    auto pOject = A::GetInstance(123, 321);
    EXPECT_EQ(pOject->Get(), 123);
    EXPECT_EQ(pOject->GetB(), 321);

    auto pOject1 = A::GetInstance(124,123);
    EXPECT_EQ(pOject1->Get(), 123);
    EXPECT_EQ(pOject1->GetB(), 321);
    EXPECT_EQ((uint64_t)pOject1, (uint64_t)pOject1);
}