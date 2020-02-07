#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//=============================================
//伪代码
//=============================================

bool DFS(Node n,int d){
    if(isEnd(n,d)){// 一旦到达深度的结束装态，就返回true装态
        return true;
    }

    for(Node nexNode in n){//遍历相邻的节点NextNode
        if(!visited[nextNode]){
            visited[nextNode]=true;//在下一步的搜索过程中，nextNode不能再次出现
            if(DFS(nextNode ,d+1)){//如果搜索出有解的话，那直接进入到下一个环节
                return true;
            }
            visited[nextNode ]=false;//将其设置为false，因为它有坑出向在下一次额搜索的别的路径中；

        }

    }
    return false ; //本次搜索无解
}


void dfs()//参数用来表示状态  
{  
    if(到达终点状态)  
    {  
        ...//根据题意添加  
        return;  
    }  
    if(越界或者是不合法状态)  
        return;  
    if(特殊状态)//剪枝
        return ;
    for(扩展方式)  
    {  
        if(扩展方式所达到状态合法)  
        {  
            修改操作;//根据题意来添加  
            标记；  
            dfs（）；  
            (还原标记)；  
            //是否还原标记根据题意  
            //如果加上（还原标记）就是 回溯法  
        }  
 
    }  
}  


//=============================================
//全排列
//=============================================

int p[10]={0};
bool vis[10]={0};
int n;

void dfs(int x){
    if(x=n+1){
        for(int i=1;i<=n;i++){
            cout<<p[i]<<" ";
            cout<<endl;
            return ;
        }
    }

    for(int i=1;j<=n;i++){
        if(vis[i]==false&&i>p[i]){//实现了剪枝运算；
            p[x]=i;
            vis[i]=true;
            dfs(x+1);
            vis[i]=false;
        }
    }
}
int main(){
    while(cin>>n){
        dfs(1);
    }
    return 0;
}

//=============================================
//查找素数
//=============================================

bool isprime(int n){//判断素数
    if(n<=1){
        return false;
    }

    for(int n=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;

}


vide dfs(int index){
    if(index==n+1){
        if(isprime(sum)){
            ans++;
        }
        for(int i=1;i<=index-1;i++){
            cout<<p[i]<<" ";
            cout<<endl;
            return ;
        }
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==false && i>p[index-1]){
            p[index]=i;
            vis[i]=true;
            sum+=a[i];
            dfs(index+1);
            vis[i]=false;
            sum-=a[i];
        }
    }
}


int main()
{
	memset(b,0,sizeof(b));
	memset(vis,0,sizeof(vis));
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	cin>>a[i],p[i]=i;//一开始要从第一个排列填好  才开始遍历 ，这与传统的dfs全排列做了点变化 
	
	ans=0;
	
	dfs(1);
	cout<<ans<<endl;
	
	return 0;


/*
该DFS 框架以2D 坐标范围为例，来体现DFS 算法的实现思想。
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=100;
bool vst[maxn][maxn]; // 访问标记
int map[maxn][maxn]; // 坐标范围
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // 方向向量，(x,y)周围的四个方向

bool CheckEdge(int x,int y) // 边界条件和约束条件的判断
{
    if(!vst[x][y] && ...) // 满足条件
        return 1;
    else // 与约束条件冲突
        return 0;
}

void dfs(int x,int y)
{
    vst[x][y]=1; // 标记该节点被访问过
    if(map[x][y]==G) // 出现目标态G
    {
        ...... // 做相应处理
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(CheckEdge(x+dir[i][0],y+dir[i][1])) // 按照规则生成下一个节点
        dfs(x+dir[i][0],y+dir[i][1]);
    }
    return; // 没有下层搜索节点，回溯
}
int main()
{
......
return 0;
}
