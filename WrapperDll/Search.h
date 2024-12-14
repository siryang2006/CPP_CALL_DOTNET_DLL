#pragma once
#include <string>

class Search;
#ifdef SEARCH_DLL_EXPORT
#define _SH_DLL_EXPORT __declspec(dllexport)
#else
#define _SH_DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // ���� C �ӿ�����ʼ�� MySearchWrapper �ͻ�ȡ�ı�
    _SH_DLL_EXPORT void* Create_Search();
    _SH_DLL_EXPORT void Destroy_Search(void* obj);
    _SH_DLL_EXPORT bool Init_Search(void* obj);
    _SH_DLL_EXPORT const char* SearchText_Search(void* obj, const char* text);

#ifdef __cplusplus
}
#endif
