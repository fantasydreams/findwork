#include "241.DifferentWaystoAddParentheses.h"
#include <unordered_map>
#include <sstream>

bool isNumber(const std::string & sStr, int iPos)
{
    assert(iPos < sStr.size());
    return (sStr[iPos] >= '0' && sStr[iPos] <= '9');
}

struct expressionElem
{
    int m_iValue;
    bool m_bNumber;
    char m_cOp;

    expressionElem(bool bNumber, char cOp) : m_bNumber(bNumber), m_iValue(0), m_cOp(cOp) {}
    expressionElem(bool bNumber, int iVal) : m_bNumber(bNumber), m_iValue(iVal), m_cOp(' ') {}
};

struct pair_hash {
    std::size_t operator()(const std::pair<int, int> &p) const {
        return p.first * 100 + p.second;
    }
};

void getExpiresionAns(const std::vector<expressionElem> & vecExpr, int iStart, int iEnd, std::unordered_map<std::pair<int, int>, std::vector<int>, pair_hash> & memo)
{
    while(iStart < iEnd && (!vecExpr[iStart].m_bNumber || !vecExpr[iEnd].m_bNumber)) {
        if(!vecExpr[iStart].m_bNumber) {
            ++iStart;
        }
        if(!vecExpr[iEnd].m_bNumber) {
            --iEnd;
        }
    }

    if(iStart > iEnd) {
        return;
    }

    if(iStart == iEnd) {
        if(memo[{iStart, iEnd}].size() == 0) {
            memo[{iStart, iEnd}].push_back(vecExpr[iStart].m_iValue);
        }
        return;
    }
    
    
    for(int i = iStart; i <= iEnd; ++i)
    {
        if(!vecExpr[i].m_bNumber)
        {
            if(memo[{iStart, i - 1}].size() == 0) {
                getExpiresionAns(vecExpr, iStart, i - 1,memo); //这里一定要注意因为可能会重复使用，所以拿取的时候要看看是否已经计算完了
            }
            if(memo[{i + 1, iEnd}].size() == 0) {
                getExpiresionAns(vecExpr, i + 1, iEnd,memo);
            }
            auto & vecLeft = memo[{iStart, i - 1}];
            auto & vecRight = memo[{i + 1, iEnd}];
            auto & vecEntire = memo[{iStart, iEnd}];
            for(auto & numL : vecLeft) {
                for(auto & numR : vecRight) {
                    switch(vecExpr[i].m_cOp){
                        case '-':
                            vecEntire.push_back(numL - numR);
                            break;
                        case '+':
                            vecEntire.push_back(numL + numR);
                            break;
                        case '*':
                            vecEntire.push_back(numL * numR);
                            break;
                    }
                }
            }
        }
    }
}

vector<int> diffWaysToCompute(string expression)
{
    if(expression.empty()) {
        return {};
    }

    std::vector<expressionElem> vecExpr;
    for(int i = 0; i < expression.size();) 
    {
        int pos = i;
        if(isNumber(expression, i)) {
            int iVal = expression[i] - '0';
            ++i;
            while(i < expression.size() && isNumber(expression, i))  {
                iVal = iVal * 10 + expression[i] - '0';
                ++i;
            }
            vecExpr.emplace_back(expressionElem(true, iVal));
        }else {
            vecExpr.emplace_back(expressionElem(false, expression[i]));
            ++i;
        }
    }

    // for(const auto & obj : vecExpr) {
    //     printf("isbumber: %d  value : %d op %c \n", obj.m_bNumber, obj.m_iValue, obj.m_cOp);
    // }

    std::unordered_map<std::pair<int, int>, std::vector<int>, pair_hash> memo;
    getExpiresionAns(vecExpr, 0, vecExpr.size() - 1, memo);

    return memo[{0, vecExpr.size() - 1}];
}


// 直接递归 + 分治
vector<int> diffWaysToCompute1(string expression)
{
    std::vector<int> ways;
    for(int i = 0; i < expression.size(); ++i) {
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
            std::vector<int> vecLeft = diffWaysToCompute1(expression.substr(0, i));
            std::vector<int> vecRight = diffWaysToCompute1(expression.substr(i + 1));
            for(auto & numLeft : vecLeft) {
                for(auto & numRight : vecRight) {
                    switch(expression[i]) {
                        case '-':
                            ways.push_back(numLeft - numRight);
                            break;
                        case '+':
                            ways.push_back(numLeft + numRight);
                            break;
                        case '*':
                            ways.push_back(numLeft * numRight);
                            break;
                    }
                }
            }
        }
    }

    if(ways.empty()) {
        ways.push_back(atoi(expression.c_str()));
    }
    return ways;
}



vector<int> diffWaysToCompute2(string expression)
{
    if(expression.size() == 0) {
        return {};
    }

    expression += "+";
    std::vector<int> vecNums;
    std::vector<char> vecOp;
    std::stringstream sStrs(expression);
    int num; char op;
    while(sStrs >> num && sStrs >> op) {
        vecNums.push_back(num);
        vecOp.push_back(op);
    }

    int n = vecNums.size();
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>()));
    for(int i = 0; i < n; ++i){
        for(int j = i; j >= 0; --j) {
            if(i == j) {
                dp[j][i].push_back(vecNums[i]);
            }else {
                for(int k = j; k < i; ++k) {
                    for(const auto & numL : dp[j][k]) {
                        for(const auto & numR : dp[k + 1][i]) {
                            auto & desVec = dp[j][i];
                            switch(vecOp[k]) {
                                case '-':
                                    desVec.push_back(numL - numR);
                                    break;
                                case '+':
                                    desVec.push_back(numL + numR);
                                    break;
                                case '*':
                                    desVec.push_back(numL * numR);
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }

    return dp[0][n-1];
}