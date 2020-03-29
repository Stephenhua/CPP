#include <iostream>
#include<algorithm>
//#include <cmath>
#include <cstdlib>
#include <string.h>
//#include <set>
using namespace std;

//打印数字进行显示；
void PrintNumber(char *number){
    bool isBegining0=true;
    int n=strlen(number);
    
    for(int i=0;i<n;++i){
        if(isBegining0 && number[i]!='0'){
            isBegining0=false;
        }
        if(!isBegining0){
            cout<<number[i];
        }
    }
    cout<<endl;
    
}

//方法一：采用传统的方法进行求解；

bool Increment(char* number){
    bool isOverFlow=false;
    int nTakeOver=0;
    int nLength=strlen(number);
    for(int i=nLength-1;i>=0;i--){
        int nSum=number[i]-'0'+nTakeOver;

        if(i==nLength-1){
            nSum++;
        }

        if(nSum>=10){
            if(i==0){
                isOverFlow=true;
            }else{
                nSum-=10;
                nTakeOver=1;
                number[i]='0'+nSum;
            }
        }else{
            number[i]='0'+nSum;
            break;
        }
    }
    return isOverFlow;
}

void PrintToMaxOfDigit(int n){
    if(n<=0){
        return ;
    }

    char *number=new char[n+1];
    memset(number,'-0',n);
    number[n]='\0';
    while(!Increment(number)){
        PrintNumber(number);
    }
    delete[] number;
}

//方法二：采用数字排列的形式进行求解；

void PrintCore(char* number ,int lenght ,int index){
    if(index==lenght-1){
        PrintNumber(number);
        return ;
    }

    for(int i=0;i<10;i++){
        number[index+1]=i+'0';
        PrintCore(number,lenght,index+1);
    }
}
void PrintToMaxOfDigit_2(int n){
    if(n<=0){
        return ;
    }

    char *number= new char[n+1];
    number[n]='\0';

    for(int i=0;i<10;i++){
        number[0]=i;//位于高位
        PrintCore(number,n,0);
    }
}


// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    PrintToMaxOfDigit(n);
    PrintToMaxOfDigit_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    system("pause");
    return 0;
}