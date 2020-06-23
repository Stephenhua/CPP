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
986. 区间列表的交集
给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。

返回这两个区间列表的交集。

（形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）

 

示例：



输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

提示：

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

*/

/*
思路一：直接使用A 和B的最大开始和最小结束， 进行比较即可，数组中存储的是每个开始和结束的下标号；
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int size1 = A.size();
        int size2 = B.size();
        int i = 0 ;
        int j = 0 ;

        vector<vector<int>> res;
        while( i< A.size() && j < B.size()){
            int start = max( A[i][0],B[j][0]);
            int end = min( A[i][1],B[j][1]);
            if( start <= end){
                res.push_back({start,end});
            }

            if(A[i][1] < B[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }

};
