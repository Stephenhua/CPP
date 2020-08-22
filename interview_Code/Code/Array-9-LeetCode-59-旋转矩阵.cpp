#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/spiral-matrix-ii/
59. 螺旋矩阵 II
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

//方法一：由于是矩形所以会直接使用；

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int left = 0 ,right =n-1;
        int up = 0 ,down = n-1 ;

        for( int begin = 0 ,end = n-1 ,m=1; begin <= end ; begin++,end--){

            for(int i = begin ; i<= end ;i++){
                res[begin][i] = m++;
            }
            for(int i = begin+1; i<= end ;i++){
                res[i][end] = m++;
            }

            for(int i = end-1 ; i>= begin ; i--){
                res[end][i] = m++;
            }
            for(int i = end -1 ; i>= begin+1; i--){
                res[i][begin] = m++;
            }
        }

        return res;
    }
};

//方法二：直接套用旋转公式进行求解；

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int left = 0 ;
        int right =n-1;
        int up =0 ;
        int down = n-1;
        int m =1 ;
        while(true){

            for(int i = left ;i <= right ;i++){
                res[up][i]=m++;
            }

            if( up++ > down ){
                break;
            }

            for(int i = up ;i <= down ; i++){
                res[i][right] =m++;
            }

            if( right-- < left ){
                break;
            }

            for(int i = right ; i>= left ; i--){
                res[down][i] = m++;
            }

            if( down--  < up ){
                break;
            }

            for(int i= down ; i >= up ;i--){
                res[i][left] = m++;
            }

            if(left++ > right ){
                break;
            }
        }

        return res;
    }
};