#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


//采用深度优先的算法进
class Solution {
    private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
      int nr=grid.size();
      int nc= grid[0].size();
      grid[r][c]='0';

      if(r-1>=0 &&grid[r-1][c]=='1') dfs(grid, r-1, c);
      
      if(r+1<nr && grid[r+1][c]=='1') dfs(grid, r+1,c);

      if(c-1>=0 && grid[r][c-1]=='1') dfs(grid ,r,c-1);

      if(c+1<nc && grid[r][c+1]=='1') dfs(grid, r, c+1);
  }

  public:
  int numIslands(vector<vector<char>>& grid){
      int nr= grid.size();
     if(!nr){
          return 0;
      }
      int nc= grid[0].size();
      

      int nums_lands=0;
      for(int i=0;i<nr;i++){
          for(int j=0;j<nc;j++){
              if(grid[i][j]=='1'){
                  ++nums_lands;
                  dfs(grid,i,j);
              }
          }
      }
      return nums_lands;
      }
};

//解法二：采用深度优先的方法进行扫描网格，然后将节点包含1作为根节点，启动广度优先所搜的方法进行，将其投放入到队列中，并将值设置为0,标记为访问过该节点，迭代的搜索队列中的每个节点

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
      int  nr= grid.size();
      if(!nr){
          return 0;
      }

      int nc=grid[0].size();

      int numsland=0;
      for(int r=0;r<nr;r++){
          for(int c=0;c<nc;c++){
              if(grid[r][c]=='1'){
                  ++numsland;
                  gird[r][c]='0';
                  queue<pair<int,int>> temp_queue;
                  temp_queue.push({r,c});
                  while(!temp_queue.empty()){
                      auto rc=temp_queue.front();
                      temp_queue.pop();
                      int row= rc.first;
                      int col= rc.second;
                      if(row-1>=0&&grid[row-1][col]=='1'){
                          temp_queue.push({row-1,col});
                          grid[row-1][col]='0';
                      }
                      if(row+1<nr&&grid[row+1][col]=='1'){
                          temp_queue.push({row+1,col});
                          grid[row+1][col]='0';
                      }

                      if(col-1>=0&& gird[row][col-1]=='1'){
                          temp_queue.push({row,col-1});
                          grid[row][col-1]='0';
                      }
                      if(col+1<nc&&grid[row][col+1]=='1'){
                          temp_queue.push({row,col+1});
                          grid[row][col+1]='0';
                      }
                  }
              }
          }
      }
      return numsland;
  }
};

//解法三，深度优先，采用组合的方式进行周边搜索，这样的好处可以降低一个等级的复杂度

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        if(m < 0 || n < 0)
        {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int sr , int sc)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        grid[sr][sc] = '0';
        for(int i = 0; i < 4; i++)
        {
            int x = sr + dx[i];
            int y = sc + dy[i];
            if(x >= 0 && x < m && y >=0 && y < n)
            {
                if(grid[x][y] == '1')
                {
                    dfs(grid,x,y);
                }
            }
        }
    }
};