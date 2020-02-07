#include <vector>
#include <iostream>
using namespace std;

//======================================
//广度优先算法
//======================================
//Vs:启点；
//Vd :终点
struct Node{
    int x;
    int y;
}
bool BFS(Node &Vs, Node & Vd){
    queue<Node> Q;
    Node Vn,Vw;
    int i;
    //用于标记颜色，当visit为true时，说明节点访问过了，也就是黑色；
    bool visited[MAXL][MAXL];
    
    //四个方向
    int dir[][2]={{0,1},{0,-1},{-1,0},{1,0}};

    //将初始状态压入队列
    Q.push(Vs)；
    visited[Vs.x][Vy.y]=true;

    while(!Q.empty()){//队列不为空，继续搜索

        Vn=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            Vw=Node(Vn.x+dir[i][0],Vn.y+dir[i][1]);
            if(Vw==Vd){
                //找到重点，记录路径，
                return true;//返回
            }

            if(isValid(Vw)&&!visit[Vw.x][Vw.y]){
                Q.push(Vw);//加入队列Q；
                visit[Vw.x][Vw.y]=true;//设置节点颜色
            }
        }
    }
    return false;//无色
}