#include <iostream>
#include <algorithm>
#include <cstdio>
//本题思路，https://blog.csdn.net/darlingwood2013/article/details/90243937
//首先将整个字符串分为两部分，第一个字符为第一部分，第二部分为剩余的部分，
//然后在此基础上，将第一个字符与它后面的字符进行交换，从而得到第二个字符

void Permutation(char * pStr, char * pBegin);

void Permutation(char * pStr){
    if(pStr==nullptr){
        return ;
    }

    Permutation(pStr,pStr);
}

void Permutation(char* pStr ,char* pBegin){
    if(*pBegin=='\0'){
        printf("%s\n",pStr);
    }else{
        for(char* pCh =pBegin;*pCh!='\0';++pCh){
            char temp=*pCh;
            *pCh=*pBegin;
            *pBegin=temp;

            Permutation(pStr,pBegin+1);
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

    Permutation(pStr);

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

    return 0;
}
