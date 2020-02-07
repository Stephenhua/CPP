#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


//方法一：采用O(mn)空间复杂度的算法实现
class Solution {
public:
    struct location
    {
        /* data */
        int x;
        int y;
        location(int x, int y):x(i),y(j){}
    };
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<location*> position;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    position.push_back(new location(i,j));
                }
            }
        }

        for(auto item:position){
            for(int i=0;i<matrix.size();i++){
                matrix[i][item->y]=0;
            }
            for(int j=0;j<matrix.size();j++){
                matrix[item->x][j]=0;
            }
        }
        
    }
};

//方法er ：采用O(m+n)空间复杂度的算法实现

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int> row;
        unordered_set<int> column;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }

        for(auto item:column){
            for(int i=0;i<matrix.size();i++){
                matrix[i][item]=0;
            }
        }

        for(auto item:row){
            for(int i=0;i<matrix[item].size();i++){
                matrix[item][i]=0;
            }
        }


    }
};