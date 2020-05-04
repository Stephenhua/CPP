#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int >> dir ={{0,1},{1,0},{-1,0},{0,-1}};

void bfs( int i,int j, vector<vector<int>>& nums, int&res){

    queue<pair<int,int>> Q;
    Q.push({ i , j});

    nums[i][j]  = -1;

    int m = nums.size(), n =nums[0].size();
    bool sign = i==0 || i==m-1 || j==0 || j==n-1;

    while( !Q.empty()){

        int s =Q.size();
        int idx = 0 ;
        while( idx <s){
            
            auto  p = Q.front();

            Q.pop();

            for( auto d :dir){
                
                int x = p.first + d.first;
                int y = p.second + d.second;

                if( x>=0 && x< m && y>=0 && y<n){
                    if( nums[x][y] == 1 ){
                        nums[x][y] = -1;
                        if( x==0 || x==m-1 || y==0 || y == n-1){
                            sign = true;
                        }
                        Q.push({x,y});
                    } 
                }
            }
        }
    }
    res +=(sign ==false);

}

int main (){

    int m,n;
    cin >> m >> n;

    vector<vector<int>> nums(m,vector<int>(n,0));

    for(int i= 0 ;i<m ;i++){
        for(int j= 0 ;j <n ;j++){
            cin >>nums[i][j];
        }
    }

    int res = 0;

    for(int i=0 ;i<m ;i++){
        for(int j=0 ;j<n ;j++){

            if(nums[i][j]==1){
                bfs(i,j,nums,res);
            }
        }
    }

    cout <<res <<endl;

    system("pause");
    return 0;
    

}