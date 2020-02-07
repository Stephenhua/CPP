#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up= 0,down=n-1,right=n-1,left=0,value=1;
        while(true){
            for(int j=left;j<=right;++j){
                res[up][j]=value++;
            }
            if(++up>down){
                break;
            }

            for(int j=up;j<=down;++j){
                res[j][right]=value++;
            }
            if(--right<left){
                break;
            }

            for(int j=right;j>=left;--j){
                res[down][j]=value++;
            }
            if(--down<up){
                break;
            }

            for(int j=down;j>=up;--j){
                res[j][left]=value++;
            }
            if(++left>right){
                break;
            }
        }
        return res;
    }
};