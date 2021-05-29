#ifndef _VECTORLENGHTEXCEPTION_H
#define _VECTORLENGHTEXCEPTION_H
#include <iostream>
#include <exception>
#include "Vector.h"
class VectorLengthException :public std::exception {
public:
	VectorLengthException(std::string const& msg) : _msg(msg) {}
	virtual const char* what() const noexcept override { return _msg.c_str(); }
private:
	std::string _msg;
};
#endif
