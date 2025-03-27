#pragma once

#include <exception>
#include <string>


class BadInput : public std::exception
{
	std::string		_msg;
	public:
		BadInput(std::string msg) : _msg(msg) {}

	const char * what () const throw ()
	{
		return _msg.c_str();
	}
	std::string	viewError () const throw ()
	{
		return ("Bad input: " + _msg).c_str();
	}
};