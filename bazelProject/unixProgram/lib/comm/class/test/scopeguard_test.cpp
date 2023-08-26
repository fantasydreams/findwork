#include "lib/comm/class/scopeguard.h"
#include "gtest/gtest.h"
#include <string>
#include <type_traits>

TEST(case_1, content)
{
    std::string str = "test not zero";   
    {
        comm::ScopeGuard oGuard([&](){str.clear();});
    }

    EXPECT_EQ(str.empty(), true);
}

TEST(case_2, content)
{
    std::string str = "test not zero";   
    {
        comm::ScopeGuard oGuard([&](){str.clear();}, []() {return false;});
    }

    EXPECT_EQ(str, "test not zero");
}

TEST(case_3, content)
{
    std::string str = "test not zero";   
    {
        ON_SCOPT_EXIT {
            str.clear();
        };
    }
    EXPECT_EQ(str.empty(), true);
}

TEST(case_4, content)
{
    std::string str = "test not zero";   
    {
        auto oScopeGuard = ON_SCOPE_EXIT_WITH_RETURN {
            str.clear();
        };

        auto oNext = std::move(oScopeGuard);
    }

    EXPECT_EQ(str.empty(), true);
}

