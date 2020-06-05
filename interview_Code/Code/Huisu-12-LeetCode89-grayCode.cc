#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
89. 格雷编码
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。

格雷编码序列必须以 0 开头。

 

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。
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

vector<int> grayCode(int n) {

    vector<int> res;

    int  shift = 1 ;

    while( n >=0){

        if( res.size() == 0){

            res.push_back(0);

        }else{

            for( int i = shift-1 ; i>=0 ;--i){

                res.push_back( res[i]+shift);

            }

            shift *= 2;
        }
        --n ;
    }
    return res;
}

//方法二：采用格雷码的性质进行判断；
vector<int> grayCode( int n ){
    vector<int> ans; 

    for( int i = 0 ; i <  1<<n ;i++){
        ans.push_back( i^(i>>1));
    }
    return ans;
}