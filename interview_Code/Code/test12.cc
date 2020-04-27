#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

/*
题目：
给定两个相同规模的点集合（大小为n），计算集合间的最低距离。这里的距离是欧式距离，然后暴力枚举的，通过60%。希望AC的朋友指点下本弱鸡，之后会更新AC答案的，感谢~
输入样例：
第一行输入集合规模n，然后输入集合A和B的点坐标，每行是点的横坐标和纵坐标，先输入A再输入B
例如:
4
0 1
1 1
1 0
1 1
2 2
2 3
3 2
3 3
输出样例：两个集合间的最短距离
例如：上样例中，集合A的[1,1]和集合B的[2,2]距离最短，距离是1.414(保留三位小数)
*/

//方法一：暴力解法；
float distance( int x1, int y1, int x2, int y2){
    float result = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return result;
}

int main(){
    int n ;
    cin >>n ;

    for(int i=0 ;i<n ;i++){
        int num ;
        cin>>num;

        vector<pair<int,int>> temp_A;
        vector<pair<int,int>> temp_B ;
        for(int i = 0 ;i<num; i++){
            int x,y;
            cin >>x >>y;
            pair<int,int> temp_xy ;
            temp_xy.first =x; 
            temp_xy.second = y ;
            temp_A.push_back(temp_xy);
        }
        for(int i =0 ;i<num ;i++){
            
            int x,y;
            cin >>x >>y;
            pair<int,int> temp_xy ;
            temp_xy.first =x; 
            temp_xy.second = y ;
            temp_B.push_back(temp_xy);
        }

        double dist = distance(temp_A[0].first, temp_A[0].second, temp_B[0].first, temp_B[0].second);

        for(int i= 0 ;i = temp_A.size() ; i++){
            for( int j =0 ; temp_B.size() ; j++){
                double temp = distance(temp_A[i].first,temp_A[i].second,temp_B[i].first, temp_B[i].second);
                if(temp < dist){
                    dist =temp ;
                }
            }
        }
    
            printf("%.3f",dist);

   }

    system("pause");
    return 0;
}

//方法二：
/*
方法：分治，和经典最近点对一样，以x坐标排序，划中线分成两堆，递归求每堆的最近距离d，然后对两堆之
间横坐标为 x[mid] - d 和 x[mid] + d 之间的点暴力看是否有比 d 小的距离

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL ;

const LL INF = 1000000000000;
const int N = 100010;

struct Node{
    LL x, y ;
    int id ;
    
    Node( LL x= 0,LL y =0, int id =0 ):x(x),y(y),id(id){}
    const bool operator <(const Node A) const{
        return x==A.x ? y<A.y : x< A.x;
    }
}no[2*N];

int n;

double dis(int a, int b ){
    return sqrt((double)((no[a].x - no[b].x)*(no[a].x - no[b].x)) +(no[a].y-no[b].y)*(no[a].y-no[b].y));
}

double slove (int left ,int right){

    if( left == right){
        return INF;
    }
    int mid = (left +right) >>1 ;
    double a = slove( 1, mid ) ;
    double b = slove( mid+1 , right);

    double d = min(a,b);
    

    for(int i=mid ;i>=1; i--){

        if( no[mid].x- no[i].x > d){
            break ;
        }

        for(int j = mid+1 ;j <=right; j++){
            
            if( no[j].x - no[i].x >d ){
                break;
            }
            double temp = dis(i,j);

            if( no[i].id !=no[j].id && temp < d){
                d = temp ;
            }
        }
    }

    return d;
}

int main() {
    int t;
    cin  >>t ;
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &no[i].x, &no[i].y);
            no[i].id = 1;
        }

        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &no[i + n].x, &no[i + n].y);
            no[i + n].id = 2;
        }

        //更具x进行比较大小；

        sort(no, no + 2 * n);

        double ans = slove(0, 2 * n - 1);

        printf("%.3lf\n", ans);
    }
}