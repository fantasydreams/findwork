#include "68.TextJustification.h"
#include <string>
#include <iostream>

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


vector<string> fullJustify1(vector<string>& words, int maxWidth) {
    std::vector<std::string> vecAns;
    if(words.empty()) {
        return vecAns;
    }
    std::vector<std::pair<std::vector<std::string>, int> > vecTmp(1);
    int iCurLine = 0;
    for(const auto & sWord : words) {
        int iAppendCnt = vecTmp[iCurLine].second == 0 ? sWord.size() : sWord.size() + 1;
        if(iAppendCnt + vecTmp[iCurLine].second <= maxWidth) {
            vecTmp[iCurLine].first.push_back(sWord);
            vecTmp[iCurLine].second += iAppendCnt;
        }else {
            ++iCurLine;
            vecTmp.emplace_back(std::vector<std::string>{sWord}, sWord.size());
        }
    }

    // for(const auto & oPair : vecTmp) {
    //     for(const auto & sWord : oPair.first) {
    //         std::cout << sWord << " ";
    //     }
    //     std::cout << std::endl;
    // }

    for(int i = 0; i < vecTmp.size(); ++i) {
        std::string sLine = vecTmp[i].first[0];
        if(vecTmp[i].first.size() > 1) {
            int Product = (maxWidth - vecTmp[i].second) / (vecTmp[i].first.size() - 1);
            int Remainder = (maxWidth - vecTmp[i].second) % (vecTmp[i].first.size() - 1);
            for(int k = 1; k < vecTmp[i].first.size(); ++k) {
                int iAppendCnt = 1 + ((i + 1 == vecTmp.size()) ? 0 : Product);
                if(Remainder > 0 && i != vecTmp.size() - 1) {
                    iAppendCnt += 1;
                    --Remainder;
                }

                sLine += std::string(iAppendCnt, ' ');
                sLine += vecTmp[i].first[k];
            }

            sLine.append(std::string(maxWidth - sLine.size(), ' '));
        }else {
            sLine.append(std::string(maxWidth - vecTmp[i].second, ' '));
        }

        vecAns.emplace_back(sLine);
    }

    return vecAns;
}