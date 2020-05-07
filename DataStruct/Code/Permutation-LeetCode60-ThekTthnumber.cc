 #include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;


//阶梯思路：根据n可以确定总共有多少个数，由于每一个数不相同，确定求解第n位时，后面的n-1位进行全排列；
/*

n个数字的排列中，根据手动排列的习惯，先固定第一个位置的数字，还剩下最多(n-1)!种排列，
再由放到第一个位置的数字原先的位置i(从左往右第i个)的不同，表示跳过了i(n-1)种排列。要找到第k个排列，
先由i = k/(n-1)得出应该移到第一个位置的数字索引，并由k = k%(n - 1)更新k.*

作者：fu-guang
链接：https://leetcode-cn.com/problems/permutation-sequence/solution/c-ji-bai-100-3-xing-dai-ma-shi-xian-by-fu-guang/
来源：力扣（LeetCode）

*/

int getNum(int num){
        int result = 1;
        for(int i = num ;i >0 ;i--){
            result *= i;
         }
    return result ;
}
string getPermutation(int n ,int k){

    string res;

    string s =string("123456789").substr(0,n);

    --k;
    while( k >0 ){
        int a = getNum(n-1);

        int i = k / a;

        res.push_back(s[i]);

        s.erase(s.begin()+i);

        k %= a;
        --n;
    }
    return res+s;//此处的s表示string中剩余的最后一个数；
}

//方法二：进行依次列举；找到第k个数

string getPermutation(int n ,int k){
    string s = string("123456789").substr(0,n);
    for(int i =1 ;i< k;i++){
        next_permutation(s.begin() , s.end()) ;
    }

    return s;
}
//方法三：利用

string getPermutation(int n ,int k){

    if( n == 1){
        return "1";
    }

    string s = "";
    bool * visited = new bool [n]();

    int * dp = new int[n]();

    dp[0] = 1;

    dp[1] = 1;

    for(int i =2 ;i< n;i++){
        d[i] = i* dp[i-1];
    }

    k--;

    for(int i = 0 ;i< n  ;i++){

        int  num = k /dp[n-1-i];

        k = k % dp[n-1-i];

        for(int j = 0 ;j < n ; j++){

            if( !visited[j]){
                if( num == 0){
                    s += j-'0';
                    visited[j] = true;
                    break;
                }else if ( num>0 ){
                    num--;
                }
            }
        }
    }

    delete[] visited ;
    delete[] dp;
    return s;
    
}