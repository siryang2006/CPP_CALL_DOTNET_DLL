#include "MySearchWrapper.h"
#using <System.dll>
#using <D:\\project\\demos\\CallNetDemo\\DLL\\bin\\Debug\\net8.0\\DLL.dll>
//using namespace System;
using namespace DLL;  // ������� C# ���
#include "StringUtils.h"
#include <msclr/marshal.h>

public ref class MySearchWrapper
{
public:
	MySearchWrapper()
	{
		search = gcnew MySearch();  // ���� MySearch ʵ��
	}

	bool Init()
	{
		return search->init();  // ���� C# ��� Init ����
	}

	System::String^ SearchText(System::String^ txt)
	{
		return search->SearchText(txt);  // ���� C# ��� GetText ����
	}

private:
	MySearch^ search;  // ���� MySearch ���ʵ��
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