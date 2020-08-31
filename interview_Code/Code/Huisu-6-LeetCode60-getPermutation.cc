#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
60. 第k个排列
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"

*/

int  getMul( int n){
    int res = 1;
    for( int i=2 ;i<=n ;i++){
        res *= i;
    }
    return res;
}
string getPermutation(int n, int k) {

    string res = "";

    vector<int> nums;

    for( int i=1 ;i<=n ;i++){
        nums.push_back(i);
    }

    for( int j = 0 ; j < n ; j++){

        int len = nums.size();


        for( int i = 1 ; i <= len ; i++){

            int n = getMul( len-1);

            if( (( i-1) * n < k ) && (k<= i*n)){

                char c = '0' + nums[i-1];

                res += c;

                nums.erase(nums.begin()+(i-1));

                k -= (i-1) * n;
                break;

            }
        }

    }

    return res;
    
}

//根据节点固定的位置进行选择求解；
/*
我们可以从左往右遍历原先字符串的最小排列，每一次找到应该放在左边第一个位置的数字，将其添加到结果字符串中，并从原字符串中删除，然后对剩下的字符串重复这一操作，直到k==0。此外由于字符串最初的状态就是第１个排列，所以要将输入的k先减一。
*/
vector<int> fac = {0,1,2,6,24,120,720,5040,40320,362880,3628800};

string getPermutation(int n, int k) {
    string res;
    string s = string("123456789").substr(0,n);

    --k;

    while( k > 0 ){
        int i = k /fac[n-1];//表示在这个字符之前的个数都是小于K的；
        res.push_back(s[i]);
        s.erase(s.begin()+i);//减枝操作；去掉当前存在的元素；
        k %= fac[n-1];
        --n;
    }

    return res+s;
}