#include "StringHelper.h"

System::String^ StringHelper::toSystemString(std::string str) {
	return msclr::interop::marshal_as<System::String^>(str);
}

std::string StringHelper::toStdString(System::String^ str) {
	return msclr::interop::marshal_as<std::string>(str);
}
