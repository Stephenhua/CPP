#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/

/*
采用深度优先进行遍历:
当前左右括号都有大于 00 个可以使用的时候，才产生分支；

产生左分支的时候，只看当前是否还有左括号可以使用；

产生右分支的时候，还受到左分支的限制，右边剩余可以使用的括号数量一定得在严格大于左边剩余的数量的时候，才可以产生分支；

在左边和右边剩余的括号数都等于 00 的时候结算。

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

void dfs( string curStr , int left ,int right , vector<string>& res){

    if( left == 0 && right == 0 ){
        res.push_back(curStr);
        return ;
    }

    if( left >right){
        return;
    }

    if( left >0){
        dfs( curStr +"(" , left -1 ,right ,res);
    }

    if( right > 0){
        dfs( curStr +")" ,left ,right -1 ,res);
    }
}
vector<string> generateParenthesis(int n) {
    
    vector<string> res;

    if( n== 0){
        return res;
    }

    dfs( "" , n ,n ,res);
    return res;
}
//采用回溯的方法进行求解；

void Core( vector<string>& res , string & cur ,int left ,int right ,int n){
    if( left == n && right ==n){
        res.push_back( cur);
        return;
    }

    if( left < n ){
        cur.push_back('(');
        Core( res, cur,left+1, right ,n);
        cur.pop_back();
    }

    if( right < n &&  right < left){
        cur.push_back( ')');
        Core( res, cur,left ,right+1 ,n);
        cur.pop_back();
    }
}


vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    
    Core(res, cur, 0, 0, n);
    return res;
}