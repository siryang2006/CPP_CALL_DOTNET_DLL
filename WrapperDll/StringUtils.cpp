#include "pch.h"
#include "StringUtils.h"
#include <msclr/marshal_cppstd.h>

System::String^ StringUtils::ConvertToDotNetString(std::string value)
{
	System::String^ result = msclr::interop::marshal_as<System::String^>(value);
	return result;
}

std::string StringUtils::ConvertToCPPString(System::String^ value)
{
	std::string result = msclr::interop::marshal_as<std::string>(value->ToString());
	return result;
}