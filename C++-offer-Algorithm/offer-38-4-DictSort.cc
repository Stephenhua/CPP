//========================================================
//字典树算法实现全排：用有效的方法将所有可能的全排列无重复无遗漏地枚举出来。
//链接：https://www.jianshu.com/p/50a27d7d2972
//https://blog.csdn.net/zhutulang/article/details/7763810
//定义：对于一个序列a1,a2,a3,a4,a5....an的两个排列b1,b2,b3,b4,b5...bn和c1,c2,c3,c4,c5...cn, 
//关键点在于：该算法的关键在于，找到紧跟在某一个排列后面的字典序。
//
//========================================================

/*
字典序法的描述如下：
      1）从排列的右端开始，找出第一个比右边字符小的字符的序号j（j从左端开始计算），即 j=max{i|pi<pi+1}
      2）在pj的右边的字符中，找出所有比pj大的字符中最小的字符pk，即
      k=max{i|pi>pj}（右边的字符从右至左是递增的，因此k是所有大于pj的字符中序号最大者）
      3）对换pj，pk
      4）再将pj+1......pk-1pkpk+1pn倒转得到排列p''=p1p2.....pj-1pjpn.....pk+1pkpk-1.....pj+1，这就是排列p的下一个下一个排列。
      
例如839647521是数字1～9的一个排列。从它生成下一个排列的步骤如下：
自右至左找出排列中第一个比右边数字小的数字4 839647521
在该数字后的数字中找出比4大的数中最小的一个5 839647521
将5与4交换 839657421
将7421倒转 839651247
所以839647521的下一个排列是839651247。
839651247的下一个排列是839651274。

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

void Permutation(vector<int>& arr){
    int n=arr.size();
    int num=1;
    //计算多种情况，就循环多少次
    for(int i=n;i>0;i--){
        num*=i;
    }
    int cur=0;
    int be=0;

    while(num--){
        //打印情况
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
        //从右往左，找出第一个左边小于右边的数，设为arr[i];
        for(int i=n-1;i>=0;--i){
            if(arr[i]>arr[i-1]){
                cur=i-1;
                break;
            }
        }
        //从右往左，找出第一个大于arr[cur]的数，设为list[b]
        for(int i=n-1;i>cur;--i){
            if(arr[i]>arr[cur]){
                be=i;
                break;
            }
        }

        swap(arr[be],arr[cur]);
        sort(arr.begin()+cur+1,arr.end());
    }

    return ;

}


int main(int argc,char* argv[]){
    vector<int> test1={1,2,3};

    Permutation(test1);

    system("pause");
    return 0;
}