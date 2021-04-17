#include <exception> 
#include <cstring>
#include <string>
#include <iostream>

class EqualPointException : public std::exception {
public:
    EqualPointException(std::string const &msg) : _msg(msg){}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }

private:
    std::string _msg;
};