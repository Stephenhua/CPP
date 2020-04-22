#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <Windows.h>
using namespace std;

/*
题目：分糖果
已知一些孩子和一些糖果，每个孩子有需求因子g，每个糖果有大小s，当某个糖果的大小s>=某个孩子的需求因子g时，
代表该糖果可以满足该孩子，求使用这些糖果，最多能满足多少孩子（注意，某个孩子最多只能用1个糖果满足）
*/

int findChildMax( vector<int>& s ,vector<int>& g){
    vector<int> temp_s(s.begin(),s.end());
    vector<int> temp_g(g.begin(), g.end() );

    sort(temp_s.begin() , temp_s.end());
    sort( temp_g.begin() , temp_g.end()) ;

    int s_value = 0;
    int g_value = 0 ;

    while(s_value < temp_s.size() && g_value < temp_g.size()){

        if( temp_s[s_value] >= temp_g[g_value]){
            g_value += 1;
        }
        s_value++;
    }
    return g_value ;
}

int main ( int argc ,char * argv[]){
    vector<int> s={6,1,20,3,8};
    vector<int> g= {5,10,2,9,15,9};

    int result = findChildMax( s, g);

    cout <<"result "<< result <<endl;

    system("pause");
    return 0;
}