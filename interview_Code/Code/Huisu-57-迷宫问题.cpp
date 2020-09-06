#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc
链接：https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc
来源：牛客网

定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示： 


int maze[5][5] = {


        0, 1, 0, 0, 0,


        0, 1, 0, 1, 0,


        0, 0, 0, 0, 0,


        0, 1, 1, 1, 0,


        0, 0, 0, 1, 0,


};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一空格是可以走的路。

Input

一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

Output

左上角到右下角的最短路径，格式如样例所示。

Sample Input

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

Sample Output

(0, 0)

(1, 0)

(2, 0)

(2, 1)

(2, 2)

(2, 3)

(2, 4)

(3, 4)

(4, 4)

输入描述:
输入两个整数，分别表示二位数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述:
左上角到右下角的最短路径，格式如样例所示。

示例1
输入
5 5

0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)

*/


/*
方法：动态规划进行求解；
1）设置当前节点加入路径，并且设置为已经走过；
2）判断当前路径为最终出口，如果是，则直接输出路径，保存结果；
3）如果不是的话，摸索前后左右的四个方向，然后进行递归；
4）如果是最佳路径，则直接设置为可走；
*/
int N,M;
vector<vector<int>> maze(N,vector<int>(M,0));//行走的迷宫；
vector<vector<int>> path_temp ;//存储当前路径；
vector<vector<int>> path_best;// 存储最佳路径；

void Core(int i ,int j ){


    maze[i][j] =1 ;
    path_temp.push_back({i,j});
    //终止条件
    if( i == N-1 && j == M-1 ){
        if( path_best.empty() || path_temp.size() < path_best.size() ){
            path_best = path_temp;
        }
    }
    
    if( i-1 >= 0 && maze[i-1][j] == 0){
        Core(i-1,j);//向上走；
    }

    if(i+1< N && maze[i+1][j] == 0 ){
        Core(i+1,j);//向下走；
    }

    if(j-1 >=0 && maze[i][j-1] == 0){
        Core(i,j-1);//向左走；
    }

    if(j+1 <M && maze[i][j+1] == 0){
        Core(i,j+1);//向右走；
    }

    path_temp.pop_back();
    maze[i][j]=0;
}

int main(int argc, char* argv[]){
    while(cin >>N >> M){
        path_temp.clear();
        path_best.clear();
        for(auto & i : maze){
            for(auto & j: i){
                cin >> j;
            }
        }

        Core(0,0);
        for( auto  i : path_best){
            cout <<"("<<i[0]<<","<<i[1]<<")"<<endl;
        }
        
    }

    system("pause");
    return;
}

