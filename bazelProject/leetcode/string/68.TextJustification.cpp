#include "68.TextJustification.h"
#include <string>

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int num = 0, wordslen = 0;
    int i = 0;
    while(i < words.size()) {
        int k = i + 1;
        wordslen = num = 0;
        num += words[i].length();
        wordslen += words[i].length();
        while(k < words.size() && num + 1 + words[k].length() <= maxWidth) {
            wordslen += words[k].length();
            num += words[k].length() + 1;
            ++k;
        }

        std::string sLine;
        if(i == k - 1) {
            sLine += words[i] + std::string(maxWidth - words[i].length(), ' ');
        }else {
            if(k >= words.size()) {
                sLine += words[i];
                for(int j = i + 1; j < words.size(); ++j) {
                    sLine += ' ';
                    sLine += words[j];
                }
                sLine += std::string(maxWidth - sLine.length(), ' ');
            }else {
                int iBlackSpaceCnt = (maxWidth - wordslen) / (k - i - 1);
                int iExtraCnt =(maxWidth - wordslen) - iBlackSpaceCnt * (k - i - 1);
                for(int j = i; j < k - 1; ++j) {
                    sLine += words[j] + std::string(iBlackSpaceCnt, ' ');
                    if(j - i < iExtraCnt) {
                        sLine += ' ';
                    }
                }
                sLine += words[k - 1];
            }
        }
        ans.emplace_back(sLine);
        i = k;
    }

    return ans;
}