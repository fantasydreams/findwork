#include "stringlib.h"
#include <algorithm>

namespace stringlib
{
    std::string str_trim(const std::string & str, const std::string & trim_list)
    {
        if(str.size() == 0 || trim_list.size() == 0){
            return str;
        }

        std::string res;
        size_t start = 0;
        size_t end = 0;
        for(size_t idx = 0; idx < str.size(); ++idx)
        {
            if(trim_list.find(str[idx]) != std::string::npos)
            {
                end = idx;
                res += str.substr(start, end - start);
                start = end + 1;
            }
        }

        if(start < str.size() ) {
            res += str.substr(start, str.size() - start);
        }

        return res;
    }

    std::vector<std::string> str_split(const std::string &str,
        const std::string & split,
        const std::string & trim,
        bool caseSensitive)
    {
        std::vector<std::string> list;
        if(str.size() == 0 || split.size() == 0){
            return list;
        }
        std::string _split = split;
        if(!caseSensitive){
            std::transform(_split.begin(), _split.end(), _split.begin(), ::tolower);
        }

        size_t start = 0, end = 0;
        for(int idx = 0; idx < str.size(); ++idx)
        {
            int64_t pos = std::string::npos;
            if(caseSensitive){
                pos = _split.find(str[idx]);
            }else{
                pos = _split.find(std::tolower(str[idx]));
            }

            if( pos != std::string::npos)
            {
                end = idx;
                std::string fragment = str_trim(str.substr(start, end - start), trim);
                start = idx + 1;
                if(fragment.size()){
                    list.emplace_back(fragment);
                }
            }
        }
        if(start < str.size()) {
            list.emplace_back(str_trim(str.substr(start, str.size() - start), trim));
        }

        return list;
    }
}
