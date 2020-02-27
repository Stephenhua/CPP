
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include <cstdio>
#include <stdexcept>
#include "Lsit.h"
#include "BinaryTreeNode.h"
//#include <exception>
using namespace std;

/*
题目：n个骰子的点数
思路：
1）递归问题
a）把n个骰子的分为两堆，第一堆只有一个， 另一堆有n-1个，一次类推，知道终止条件n=1时，才会结束


2）动态规划的问题
首先该问题具备DP的两个特征：最优子结构性质和子问题的重叠性。
具体的表现在：(1)n个骰子的点数依赖于n-1个骰子的点数，相当于在n-1个骰子点数的基础上再进行投掷

(2)求父问题的同时，需要多次利用子问题。

由此定义状态转移方程为f(n,k)表示n个骰子点数和为k时出现的次数，于是可得:

f(n,k)=f(n−1,k−1)+f(n−1,k−2)+f(n−1,k−3)+f(n−1,k−4)+f(n−1,k−5)+f(n−1,k−6)

其中 n>0且k<=6n。其中f(n−1,k−i)表示的是第n次掷骰子时，骰子的点数为i对应的情况，所以从k−1到k−6分别对应第n次掷骰子时骰子正面为1到6的情况。而初始状态可以定义为：

f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1
*/

void Probality(int original ,int current,int sum,int * pProbabilities){
    if(current==1){
        pProbabilities[sum-original]++;
    }else{
        for(int i=1;i<=6;++i){
            Probality(original,current-1,i+sum,pProbabilities);
        }
    }
}

void Probability(int number,int * pProbabilities){
    for(int i=1;i<=6;++i){
        Probality(number,number,i,pProbabilities);
    }
}

void PrintProbability(int number){

    if(number<1){
        return ;
    }

    int maxSum=6*number;
    int *pProbabilities= new int[maxSum-number+1];

    for(int i=number ;i<=maxSum ;++i){
        pProbabilities[i-number]=0;
    }

    Probability(number,pProbabilities);

    int total=pow(6,number);

    for(int i=number;i<= maxSum;++i){
        double ratio=(double)pProbabilities[i-number]/total;
        cout<<i<<" : "<<ratio<<endl;
    }

    delete[] pProbabilities;
}


//方法二；动态规划法

void FindSum(int n){
    if(n<=0){
        return ;
    }

    int sum=0;

    int arr[n+1][6*n+1];
    memset(arr,0,sizeof(arr));

    for(int i=1;i<=6;i++){
        arr[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            arr[i][j]+=(arr[i-1][j-1]+arr[i-1][j-2]+arr[i-1][j-3]+arr[i-1][j-4]+arr[i-1][j-5]+arr[i-1][j-6]);

        }
    }

    //输出结果

    for(int i=n;i<=6*n;i++){
        sum+=arr[n][i];
    }

    cout<< n <<" 个骰子总共的次数："<<sum<<endl;

    for(int i=n;i<=6*n ;i++){
        cout<<"骰子的和为"<<i<<"时"<<(arr[n][i]*1.0/sum)<<endl;
    }
}

/*

int main(){
    int n;
    cout<<"请输入骰子数："<<endl;
    cin>>n;
    FindSum(n);
    system("pause");
    return 0;
}

*/
// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    PrintProbability(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);
    system("pause");

    return 0;
}
