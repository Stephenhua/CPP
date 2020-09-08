#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main(int argc,char*atgv[]){
    int n ,m ;
    cin >>n >>m;
    //n表示人，m表示小组；
    unordered_map<int,vector<int>> mp;
    unordered_map<int,int> flag;
    for(int i = 0 ;i < m ;i++){
        int temp;
        cin >>temp;
        vector<int> group(temp,0);
        for(int i= 0;i <temp;i++){
            cin>>group[i];
        }
        flag[i] =0;
        mp[i]=group;
    }

    unordered_map<int,vector<int>> pep;
    for(int i = 0 ;i <mp.size();i++){
        for(int j = 0 ;j <mp[i].size() ;j++){
            int temp = mp[i][j];
            pep[temp].push_back(i);
        }
    }
    int res = 1;
    vector<int> first = pep[0];
    for(int i =0 ;i < first.size();i++){
        if(flag[i]==1){
            continue;
        }else{
             res += mp[first[i]].size();
        }
    }
    int size=  mp.size();
    vector<int> flag(size,0);
    vector<int> temp;

    for(int i = 0 ;i < size;i++){

        vector<int>::iterator it;
        it = find(mp[i].begin(),mp[i].end(),0);
        if(it != mp[i].end()){
            flag[i] = 1;
            temp =mp[i];
            res += 1;

        }
    }

}