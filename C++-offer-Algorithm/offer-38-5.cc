#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
//关键字：组合、全排序、字典序列算法、总结 、对面和相等的正方体
//本题思路，https://blog.csdn.net/darlingwood2013/article/details/90243937
//首先将整个字符串分为两部分，第一个字符为第一部分，第二部分为剩余的部分，
//然后在此基础上，将第一个字符与它后面的字符进行交换，从而得到第二个字符

void PermutationCore(char * pStr, char * pBegin ,int & num);

int Permutation(char * pStr){
    if(pStr==nullptr){
        return 0;
    }
    int num= 0;
    PermutationCore(pStr,pStr,num);
    return num;
}

void PermutationCore(char* pStr ,char* pBegin ,int & num){
    if(*pBegin=='\0'){
        printf("%s\n",pStr);
        num++;
    }else{
        for(char* pCh =pBegin;*pCh!='\0';++pCh){
            char temp=*pCh;
            *pCh=*pBegin;
            *pBegin=temp;

            PermutationCore(pStr,pBegin+1,num);
            //这部分的交换是为了复位，防止其他分支交换时受到相应的影响
            temp=*pCh;
            *pCh=*pBegin;
            *pBegin=temp;
        }
    }
}

// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr ==nullptr){
        printf("Test for nullptr begins:\n");
    }else{
        printf("Test for %s begins:\n",pStr);
    }

    int reuslt = Permutation(pStr);

    cout <<"result  " << reuslt <<endl;

    printf("\n");
}


int main(int argc, char *argv[]){
    Test(nullptr);

    char string1[]="";
    Test(string1);

    char string2[]="a";
    Test(string2);

    char string3[]="ab";
    Test(string3);

    char string4[]="abc";
    Test(string4);

    system("pause");
    return 0;
}
