#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
/*

1、路径：也就是已经做出的选择。

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

回溯方法框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
          做选择
            将该选择从选择列表移除
            路径.add(选择)

        backtrack(路径, 选择列表)
        # 撤销选择
            路径.remove(选择)
            将该选择再加入选择列表

路径：temp ;
选择列表：从 begin到n结束；
结束条件： temp.size() == k ;

*/

vector<vector<int>> res;
void Core( int & n , int & k ,int begin ,vector<int>& temp){
    
    if( temp.size() == k){
        res.push_back(temp);
        return;
    }
//此处还需要进行剪枝，
/*
多写几遍（发现 max(i) 是我们倒着写出来），我么就可以发现 max(i) 与 接下来要选择的元素貌似有一点关系，很容易知道：
max(i) + 接下来要选择的元素个数 - 1 = n，其中， 接下来要选择的元素个数 = k - pre.size()，整理得到：
max(i) = n - (k - pre.size()) + 1
所以，我们的剪枝过程就是：把 i <= n 改成 i <= n - (k - pre.size()) + 1 ：

*/
    for( int i = begin ;i<=(n-(k-temp.size())+1) ;i++){

        temp.push_back(i);
        Core( n,k, i+1, temp);
        temp.pop_back();
    }

}
vector<vector<int>> combine(int n, int k) {


    if( n<= 0 || k <= 0 || n <k){
        return res;
    }
    vector<int> temp;
    Core( n,k,1 ,temp);
    return res;
}