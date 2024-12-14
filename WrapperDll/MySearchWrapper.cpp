#include "MySearchWrapper.h"
#using <System.dll>
#using <D:\\project\\demos\\CallNetDemo\\DLL\\bin\\Debug\\net8.0\\DLL.dll>
//using namespace System;
using namespace DLL;  // 引入你的 C# 类库
#include "StringUtils.h"
#include <msclr/marshal.h>

public ref class MySearchWrapper
{
public:
	MySearchWrapper()
	{
		search = gcnew MySearch();  // 创建 MySearch 实例
	}

	bool Init()
	{
		return search->init();  // 调用 C# 类的 Init 方法
	}

	System::String^ SearchText(System::String^ txt)
	{
		return search->SearchText(txt);  // 调用 C# 类的 GetText 方法
	}

private:
	MySearch^ search;  // 持有 MySearch 类的实例
};



gcroot<MySearchWrapper^> handler = nullptr;

Search::Search() {
	handler = gcnew MySearchWrapper();
}

bool Search::init() {
	return handler->Init();
}

Search::~Search() {}

std::string Search::SearchText(std::string text) {
	return StringUtils::ConvertToCPPString(handler->SearchText(StringUtils::ConvertToDotNetString(text)));
}