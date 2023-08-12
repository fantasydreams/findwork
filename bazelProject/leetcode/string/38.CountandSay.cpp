#include "38.CountandSay.h"

string countAndSay(int n) {
    if(n <= 0 || n > 300) {
        return "";
    }

    std::string ans = "1";
    for(int i = 1; i < n; ++i) {
        std::string tmp = "";
        int iSameCnt = 1;
        char cur = ans[0];
        for(int k = 1; k <= ans.size(); ++k) {
            if(k != ans.size() && cur == ans[k]) {
                ++iSameCnt;
            }else {
                tmp += iSameCnt + '0';
                tmp += cur;
                iSameCnt = 1;
                if(k != ans.size()) {
                    cur = ans[k];
                }
            }
        }

        ans = tmp;
        tmp.clear();
    }

    return ans;
}


string countAndSay1(int n) {
    std::string ans = "1";

    for(int i = 1; i < n; ++i) {
        char curCh = ans[0];
        int iSameCnt = 1;
        std::string sTmp;
        for(int j = 1; j < ans.size(); ++j) {
            if(curCh == ans[j]) {
                ++iSameCnt;
            }else {
                sTmp += iSameCnt + '0';
                sTmp += curCh;
                iSameCnt = 1;
                curCh = ans[j];
            }
        }

        sTmp += iSameCnt + '0';
        sTmp += curCh;
        swap(ans, sTmp);
        sTmp.clear();
    }

    return ans;
}