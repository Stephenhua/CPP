#include <iostream>
#include <stdlib.h>    
#include <crtdbg.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <vector>

using namespace std;

int main(){
    int a=10;
    void *b=&a;
    cout<<"int a="<<a<<endl;
    cout<<"void (int *)b="<<*(int *)b<<endl;
    cout<<"void (double *) ="<<*(double *)b<<endl;//由于void* 已经进行了一次转移，所以其不能再进行第二次转移；
    system("pause");
    return 0;
}