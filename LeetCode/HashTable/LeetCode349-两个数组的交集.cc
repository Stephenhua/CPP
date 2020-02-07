#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> u;
        for(auto num:nums){
            u.insert(num);
        }

        for(auto num:nums){
            auto a=u.find(num);
            if(a!=nums.end()){
                result.push_back(num);
            }
            u.erase(a);
        }
        return result;
        
    }
};

//方法二：采用unordered_set的形式进行计算，同时利用指针进行遍历查找
//时间复杂度：O(n+m);
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1 = unordered_set<int>(nums1.begin(), nums1.end());
        unordered_set<int> set2 = unordered_set<int>(nums2.begin(), nums2.end());
        
        unordered_set<int>* small;
        unordered_set<int>* large;
        
        if (set1.size() < set2.size()) {
            small = &set1;
            large = &set2;
        } else {
            small = &set2;
            large = &set1;
        }
        
        vector<int> intsect;
        for (auto v : *small) {//遍历最小的即可；这样的话
            if (large->find(v) != large->end()) {
                intsect.push_back(v);
            }
        }

        return intsect;
    }
};