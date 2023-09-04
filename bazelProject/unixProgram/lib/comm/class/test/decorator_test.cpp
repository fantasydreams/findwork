#include "lib/comm/class/mode/decorator.h"
#include "gtest/gtest.h"
#include <memory>
#include <type_traits>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "lib/comm/class/scopeguard.h"


TEST(case_1, content)
{
    context oCtx;
    Essence oEssence(666);
    HalfDecorator oHalfDeco(&oEssence);
    DoubleDecorator oDoubleDeco(&oHalfDeco);
    EXPECT_EQ(oHalfDeco.Handle(oCtx), 333);
    EXPECT_EQ(oDoubleDeco.Handle(oCtx), 666);
}


TEST(case_2, content)
{
    context oCtx;
    Essence oEssence(666);
    DoubleDecorator oDoubleDeco(&oEssence);
    HalfDecorator oHalfDeco(&oDoubleDeco);
    EXPECT_EQ(oHalfDeco.Handle(oCtx), 666);
    EXPECT_EQ(oDoubleDeco.Handle(oCtx), 1332);
}