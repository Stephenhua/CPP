#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

/*
回溯算法：
解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

1、路径：也就是已经做出的选择。path;

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

*/
class Solution {
public:
vector<vector<int>> res;
vector<int> temp;

void Core( int k ,int n,int cnt){

    if( k==0 && n==0 ){
        res.push_back( temp);
        return;
    }

    for( int i= cnt ; i<=9  ; i++){

        //当出现负数的时候直接退出；

        if( i > n){
            return;
        }

        temp.push_back(i);
        Core(k-1,n-i,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {

        Core(k,n,1);
        return res;
    }
};

//题目：n =100 ,k = 6; 范围1-33；

class Solution2 {
public:
vector<vector<int>> res;
vector<int> temp;

void Core( int k ,int n,int cnt){

    if( k==0 && n==0 ){
        res.push_back( temp);
        return;
    }

    for( int i= cnt ; i<=33  ; i++){

        //当出现负数的时候直接退出；

        if( i > n){
            return;
        }

        temp.push_back(i);
        Core(k-1,n-i,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {

        Core(6,100,1);
        return res;
    }
};

int main( int argc, char* argv[]){

    Solution2 s;
    vector<vector<int>> res;

    res = s.combinationSum3(6,100);

    for( int i =0 ;i <res.size() ;i++){
        for( int j = 0 ;j <res[0].size() ;j++){
            cout<< res[i][j] <<" ";
        }
        cout <<endl;
    }

    system("pause");
    return 0 ;
}