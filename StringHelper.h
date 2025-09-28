#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>

static class StringHelper {
public:
	static System::String^ toSystemString(std::string str);
	static std::string toStdString(System::String^ str);
};

