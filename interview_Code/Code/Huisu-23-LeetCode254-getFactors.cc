#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;


/*
254. 因子的组合
整数可以被看作是其因子的乘积。

例如：

8 = 2 x 2 x 2;
  = 2 x 4.
请实现一个函数，该函数接收一个整数 n 并返回该整数所有的因子组合。

注意：

你可以假定 n 为永远为正数。
因子必须大于 1 并且小于 n。
示例 1：

输入: 1
输出: []
示例 2：

输入: 37
输出: []
示例 3：

输入: 12
输出:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
示例 4:

输入: 32
输出:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

*/


/*

方法一：回溯方法
*/


class Solution {
    vector<vector<int>> res;
    void dfs(vector<int> m)
    {
        res.push_back(m);
        for(int i=m[m.size()-2];i<=sqrt(m[m.size()-1]);++i)
        {
            if(m[m.size()-1]%i==0) 
            {
                vector<int> temp(m.begin(),m.end()-1);
                temp.push_back(i);
                temp.push_back(m[m.size()-1]/i);
                dfs(temp);
            }
        }
         
    }
public:
    vector<vector<int>> getFactors(int n) {
        for(int i=2;i<=sqrt(n);++i)
        {
            if(n%i==0)
            {
                vector<int> temp({i,n/i});
                dfs(temp);
            }
        }
        return res;
    }
};
