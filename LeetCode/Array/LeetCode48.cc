#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//============================
//旋转图像
//时间复杂度：o(n2);
//空间复杂复：O(1);
//=============================
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int rownum=matrix.size();
        int colnum=matrix[0].size();

        for(int i=0;i<rownum;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<rownum;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
}