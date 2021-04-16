#include <exception> 
#include <cstring>
#include <string>

class EqualPointException : public std::exception {

std::string _msg;
public:
    EqualPointException(std::string const &msg) : _msg(msg){}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }

};