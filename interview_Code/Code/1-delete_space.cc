#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
#include <assert.h>
using namespace std;

/*
用熟悉的语言写一个函数，把字符串里面的空格全部去掉，并返回删除的空格的个数，
要求空间复杂度 O(1)，函数原型：int delete_space(char *str)
*/

int  SetValue( char *str){

    assert(str);

    char* pTemp = str;
    int count = 0 ;

    while(*pTemp != '\0'){
        while( *pTemp == ' '){
            count++;
            pTemp++;
        }

        *str = *pTemp;//将pTemp指针指向的元素进行复制；

        if(*str == '\0'){
            cout<<"Space count："<<count <<endl;
            return count;
        }else{
            str++;
        }
        pTemp++;
    }
    *str  = '\0';

    cout <<" space count"<< count <<endl;

    return count ;
}


int main( int argc ,char * argv[]){

    char str[] = " hello world, xx yy";
    cout<<str<<" len :"<<strlen(str)<<endl;

    int result =SetValue(str);
    
    system("pause");
    return 0;
}