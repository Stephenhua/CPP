#include<iostream>
#include <cstdio>
#include<vector>
#include "memory.h"
#include "assert.h"
using namespace std;

char *strcpy(char *dst,const char* src){
    assert(dst!=nullptr && src!=nullptr);
    char *ret=dst;
    while((*dst++=*src++)!='\0');
    return ret;

}

//如果出现dst和src内存重叠；
//函数memcpy自带内存重叠检测功能，下面给出memcpy的实现my_memcpy。
char * strcpy(char *dst,const char *src)
{
    assert(dst != NULL && src != NULL);

    char *ret = dst;

    my_memcpy(dst, src, strlen(src)+1);

    return ret;
}

char * my_memcpy(char *dst,const char* src, int cnt){
    assert(dst!=nullptr && src!=nullptr);

    char *ret=dst;

    if(dst>=src && dst<=src+cnt-1){//内存重叠，从高地址开始复制
        dst=dst+cnt-1;
        src=src+cnt-1;
        while(cnt--){
            *dst--=*src--;
        }

    }else{
        while(cnt--){//正常情况，从低地址开始复制
            *dst++=*src++;
        }
    }
    return ret;
}