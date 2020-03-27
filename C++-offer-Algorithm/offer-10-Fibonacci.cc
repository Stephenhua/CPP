#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
//斐波那契数列采用递归的形式进行求解；
// 
long long Fibonacci(int n){
    if(n<0)
    {
        return 0;
    }
    if(n==1){
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

//采用正序的形式进行

long long Fibnacci1(int n){
    if(n<0)
    {
        return 0;
    }
    if(n==1){
        return 1;
    }

    int FinMinus1=0;
    int FinMinus2=1;
    int FibN=0;
    for(int i=2;i<=n;i++){
        FibN=FinMinus1+FinMinus2;
        FinMinus1=FinMinus2;
        FinMinus2=FibN;
    }
    return FibN;
}

void Test(int n,int expected){
    if(Fibonacci(n)==expected){
        printf("Test for %d in solution1 passed.\n",n);
    }else{
        printf("Test for %d in solution1 failed.\n",n);
    }

    if(Fibnacci1(n)==expected){
         printf("Test for %d in solution1 passed.\n",n);
    }else{
        printf("Test for %d in solution1 failed.\n",n);
    }
}

int main(int argc ,char*argv[]){
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);
    system("pause");
    return 0;
}