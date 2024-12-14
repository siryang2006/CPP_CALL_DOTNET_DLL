#pragma once

#include <string>

ref class StringUtils
{
public:
	static System::String^ ConvertToDotNetString(std::string value);
	static std::string ConvertToCPPString(System::String^ value);
};