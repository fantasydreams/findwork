#include <string>
#include <vector>


namespace stringlib
{
    std::string str_trim(const std::string & str, const std::string & trim_list);
    std::vector<std::string> str_split(
            const std::string & str, 
            const std::string & split, 
            const std::string & trim,
            bool caseSensitive);
}
