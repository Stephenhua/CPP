#include <iostream>
#include <vector>
#include <unordered_map>

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
分两种情况进行讨论：通过画图的形式就可以得出；
1）相交；
2）不想交；

*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int size1 = A.size();
        int size2 = B.size();

        int i = 0 ;
        int j = 0;

        while ( i < size1 && j < size2 )
        {
            int a1 = A[i][0];
            int a2 = A[i][1];
            int b1 = B[i][0];
            int b2 = B[i][1];
            int start = max(a1,b1);
            int end = min(a2,b2);

            if( start <= end ){
                res.push_back({start,end});
            }
            if( A[i][1] < B[j][1] ){
                i++;
            }{
                j++;
            }
        }
        

        return res;

    }

};