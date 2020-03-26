#define CRTDBG_MAP_ALLOC  //放在程序最前
#include <iostream>
#include <stdlib.h>    
#include <crtdbg.h> 
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{  
    int *p=(int*)malloc(sizeof(int));
    *p=6;
    cout<<*p<<endl;
    free(p);
    p=nullptr;
    _CrtCheckMemory();//注意这条语句的摆放位置，因为这会直接影响到你的判断结果
    system("pause");
    return 0; 
}