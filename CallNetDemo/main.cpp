// MySearchWrapper.h
#pragma once
#include <iostream>
#include <string>
#include "../WrapperDll/Search.h"
#pragma comment(lib, "..\\DLL\\bin\\Debug\\net8.0\\WrapperDll.lib")

int main() {
    void* search = Create_Search();
    bool ret = Init_Search(search);
    std::string result = SearchText_Search(search, "test");
    return 0;
}
