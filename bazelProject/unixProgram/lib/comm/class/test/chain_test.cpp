#include "gtest/gtest.h"
#include "lib/comm/class/mode/chain.h"


TEST(case_1, content)
{
    BaseChain* poIns1 = new BaseHandlerExample(1);
    BaseChain* poIns2 = new BaseHandlerExample(2);
    BaseChain* poIns3 = new BaseHandlerExample(4);

    Chain* poChainMange = new Chain();
    poChainMange->AddChain(poIns1).AddChain(poIns2).AddChain(poIns3);

    Context oCtx(0);
    EXPECT_EQ(poChainMange->Handle(&oCtx, poChainMange), 0);
    EXPECT_EQ(oCtx.m_iHandlerValue, 1);

    oCtx.m_iValue = 1; 
    EXPECT_EQ(poChainMange->Handle(&oCtx, poChainMange), 0);
    EXPECT_EQ(oCtx.m_iHandlerValue, 1);

    oCtx.m_iValue = 2;
    EXPECT_EQ(poChainMange->Handle(&oCtx, poChainMange), 0);
    EXPECT_EQ(oCtx.m_iHandlerValue, 2);

    oCtx.m_iValue = 3;
    EXPECT_EQ(poChainMange->Handle(&oCtx, poChainMange), 0);
    EXPECT_EQ(oCtx.m_iHandlerValue, 4);

    oCtx.m_iValue = 5;
    oCtx.m_iHandlerValue = -1;
    EXPECT_EQ(poChainMange->Handle(&oCtx, poChainMange), 0);
    EXPECT_EQ(oCtx.m_iHandlerValue, -1);
}