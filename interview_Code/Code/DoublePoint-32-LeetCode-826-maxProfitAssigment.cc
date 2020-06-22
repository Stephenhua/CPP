#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
826. 安排工作以达到最大收益
有一些工作：difficulty[i] 表示第i个工作的难度，profit[i]表示第i个工作的收益。

现在我们有一些工人。worker[i]是第i个工人的能力，即该工人只能完成难度小于等于worker[i]的工作。

每一个工人都最多只能安排一个工作，但是一个工作可以完成多次。

举个例子，如果3个工人都尝试完成一份报酬为1的同样工作，那么总收益为 $3。如果一个工人不能完成任何工作，他的收益为 $0 。

我们能得到的最大收益是多少？

示例：

输入: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
输出: 100 
解释: 工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。
提示:

1 <= difficulty.length = profit.length <= 10000
1 <= worker.length <= 10000
difficulty[i], profit[i], worker[i]  的范围是 [1, 10^5]

*/

/*
方法一：进行排序，困难程序，worker, 计算最大的收益是多少；

*/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> diifProfit;
        int res = 0 ;
        for(int i = 0 ;i < difficulty.size() ;i++){
            diifProfit.push_back({difficulty[i],profit[i]});
        }

        sort( diifProfit.begin() ,diifProfit.end());

        sort( worker.begin() ,worker.end());

        int j = 0;
        int maxProfit = 0;

        for( int i= 0 ; i <worker.size() ;i++){
            while( j < diifProfit.size() &&  diifProfit[j][0] <= worker[i]){
                maxProfit = max( maxProfit,diifProfit[j][1]);//一直存储之前的最大利润值，直接进行比较既可以；
                j++;
            }
            res +=maxProfit;
        }
        return res;
    }
};