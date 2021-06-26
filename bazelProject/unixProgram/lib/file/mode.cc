
#include "mode.h"
#include <map>
#include <string>
#include "lib/string/stringlib.h"
#include <vector>
namespace filelib
{
    static std::map<std::string, mode_t> mode_map = 
    {
        {"O_RDONLY", O_RDONLY},
        {"O_WRONLY", O_WRONLY},
        {"O_RDWR"  , O_RDWR},
        {"O_ACCMODE", O_ACCMODE},
    #if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
        {"FREAD", FREAD},
        {"FWRITE", FWRITE},
    #endif
        {"O_NONBLOCK", O_NONBLOCK},
        {"O_APPEND"  , O_APPEND  },

    #if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
        {"O_SHLOCK", O_SHLOCK},
        {"O_EXLOCK", O_EXLOCK},  /* open with exclusive file lock */
        {"O_ASYNC",  O_ASYNC },  /* signal pgrp when data ready */
        {"O_FSYNC",  O_FSYNC},
        {"O_SYNC" ,  O_SYNC},    /* source compatibility: do not use */
        {"O_NOFOLLOW", O_NOFOLLOW},  /* don't follow symlinks */
    #endif /* (_POSIX_C_SOURCE && !_DARWIN_C_SOURCE) */

        {"O_CREAT", O_CREAT},   /* create if nonexistant */
        {"O_TRUNC", O_TRUNC},   /* truncate to zero length */
        {"O_EXCL" , O_EXCL },   /* error if already exists */

        {"S_IRWXU", S_IRWXU},   /* [XSI] RWX mask for owner */
        {"S_IRUSR", S_IRUSR},   /* [XSI] R for owner */
        {"S_IWUSR", S_IWUSR},   /* [XSI] W for owner */
        {"S_IXUSR", S_IXUSR},   /* [XSI] X for owner */
        /* Read, write, execute/search by group */
        {"S_IRWXG", S_IRWXG},   /* [XSI] RWX mask for group */
        {"S_IRGRP", S_IRGRP},   /* [XSI] R for group */
        {"S_IWGRP", S_IWGRP},   /* [XSI] W for group */
        {"S_IXGRP", S_IXGRP},   /* [XSI] X for group */
        /* Read, write, execute/search by others */
        {"S_IRWXO", S_IRWXO},   /* [XSI] RWX mask for other */
        {"S_IROTH", S_IROTH},   /* [XSI] R for other */
        {"S_IWOTH", S_IWOTH},   /* [XSI] W for other */
        {"S_IXOTH", S_IXOTH},   /* [XSI] X for other */

        {"S_ISUID", S_ISUID},   /* [XSI] set user id on execution */
        {"S_ISGID", S_ISGID},   /* [XSI] set group id on execution */
        {"S_ISVTX", S_ISVTX},   /* [XSI] directory restrcted delete */

    #if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
        {"S_ISTXT", S_ISVTX},   /* sticky bit: not supported */
        {"S_IREAD", S_IRUSR},   /* backward compatability */
        {"S_IWRITE", S_IWUSR},  /* backward compatability */
        {"S_IEXEC", S_IXUSR},   /* backward compatability */
    #endif  /* !S_IFMT */

    };


    bool get_mode(const std::string & mode_list, mode_t & mode)
    {
        std::vector<std::string> list = stringlib::str_split(mode_list, "|", " ", true);
        if(list.size() == 0){
            return false;
        }

        mode = 0;
        for(size_t idx = 0; idx < list.size(); ++idx)
        {
            if(mode_map.find(list[idx]) != mode_map.end()){
                mode |= mode_map[list[idx]];
            }
            else{
                return false;
            }
        }
        return true;
    }
}