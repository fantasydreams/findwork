#include <cstring>
#include <exception>
#include <string>
using std::exception;

class SysCallException : public exception {
public:
    SysCallException(int iErrCode, const std::string && sErrMsg, bool bDetail = true) : m_iErrCode(iErrCode), m_sErrMsg(sErrMsg) {
        if(bDetail) {
            m_sErrMsg.append(", Err Detail: ").append(strerror(errno));
        }
    }

    virtual ~SysCallException() throw() {}
    int GetErrCode() {
        return m_iErrCode;
    }

    std::string GetErrMsg() const throw() {
        return m_sErrMsg;
    }

    virtual const char * what() const throw() {
        return m_sErrMsg.c_str();
    }

protected:
    int m_iErrCode;
    std::string m_sErrMsg;    
};