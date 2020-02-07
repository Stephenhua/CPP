#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;


//方法一：采用map进行统计每次出现的次数，在利用sort排序，时间复杂度O（nlogn);
class Solution {
public:
    auto comp=[](pair<int,int > a, pair<int ,int >b){ return a.second>b.second;}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int > result;
        map<int ,int > count;
        for(auto num:nums){
            count[num]++;
        }
        vector<pair<int,int>> temp(count.begin(),count.end());
        //vector<pair<int,int>> temp(count);
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second > b.second; });
        
        auto a=temp.begin();
        for(int i=0;i<k;i++){
            result.push_back(a->first);
            a++;
        }
        return result;
        
    }
};

//方法二：采用map进行统计每次出现的次数，在利用优先队列建立小顶堆，时间复杂度O（nlogk);
class Solution {
public:
struct  cmp
{
    bool operator()(pair<int,int > &a, pair<int,int>&b){
        return a.second>b.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> reslut;
    unordered_map<int,int> temp_value;
    for(auto num:nums){
        temp_value[num]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int> > ,cmp> freq;
    for(auto num:temp_value){
        freq.push(num);
        if(freq.size()>k){
            freq.pop();
        }
    }
    while(!freq.empty()){
        result.push_back(freq.top().first);
        freq.pop();
    }
    return result;
}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        int temp = (int)map.size() - k;
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            //if(pq.size() > temp){
            //    res.push_back(pq.top().second);
            //    pq.pop();
            //}
        }
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};