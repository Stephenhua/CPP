#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <Windows.h>
using namespace std;

/*
题目：作业调度；
https://blog.csdn.net/liufeng_king/article/details/8740572

*/

typedef pair<int,int> Pair;
int cmp( const Pair &x, const Pair& y){
    return x.second> y.second;
}

int cmpSmall( const Pair &x, const Pair &y){
    return x.second < y.second;
}

void  Schedule( map<int,int> work ,int machine){

    map<int, int> machineMap;
    map<int,vector<int> > machineNUm;
    //初始化机器的数量和时间
    for(int i = 1 ;i <=machine ;i++){
        
        machineMap[i]=0;

    }
    cout <<"Machine"<<machineMap.size()<<endl;
    //对work中的作业进行排序；
    vector<pair<int,int>> temp_work (work.begin(),work.end());
    sort(temp_work.begin(), temp_work.end(),cmp);

    vector<pair<int,int>> temp_machine( machineMap.begin(),machineMap.end());
    cout<<"temp_machine"<< temp_machine.size() <<endl;

    if( machine >= work.size()){
        for(int i=0;i < work.size();i++){
            machineNUm[i].push_back(temp_work[i].first);
        }
    }else{
        for(int i = 0;i < work.size(); i++){
            sort(temp_machine.begin(),temp_machine.end(), cmpSmall);
            temp_machine.front().second += temp_work[i].second;
            cout <<"temp_machine"<<temp_machine.front().first <<"Score"<<temp_machine.front().second<<endl;
            machineNUm[temp_machine.front().first].push_back(temp_work[i].first);
        }
    }

    for(int i=0;i<machine;i++){
        cout<<"Machine"<<temp_machine[i].first<<"  ";
        cout<<"Machine Score"<<temp_machine[i].second<<endl;
        for(int j=0;j<machineNUm[temp_machine[i].first].size();j++){
            cout<<"Work number"<<machineNUm[temp_machine[i].first][j]<<endl;
        }
    }
}

int main ( int argc, char* argv[]){
    map<int,int> result;
    vector<int> value = {4,6,3,7,9,1,2,5,10,8};
    for(int i=0;i<10;i++){
        result[i]=value[i];
    }
    int num =3;
    Schedule(result,num);

    system("pause");
    return 0;

}