#include "pch.h"
#include "Search.h"

#include "MySearchWrapper.h"

void* Create_Search()
{
    return new Search();
}

void Destroy_Search(void* obj) {
    Search* myWrapper = (Search*)(obj);
    if (myWrapper) {
        delete myWrapper;
    }
}

bool Init_Search(void* obj)
{
    Search* myWrapper = (Search*)(obj);
    return myWrapper->init();
}

const char* SearchText_Search(void* wrapper, const char* text)
{
    Search* myWrapper = (Search*)(wrapper);
    return (const char*)myWrapper->SearchText(std::string(text)).c_str();
}
