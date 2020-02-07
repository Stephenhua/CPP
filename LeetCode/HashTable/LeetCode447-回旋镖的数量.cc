#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


//方法一：该方法的效率比较低，并不一是最好的方法；
class Solution {
    public:
     int dis(const vector<int> p1, vector<int> p2){
         return  (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])(p1[1]-p2[1]);
     }

     int numberOfBoomerangs(vector<vector<int>>&points){

         int res=0;
         for(int i=0;i<points.size();i++){
             unordered_map<int ,int > imap;
             for(int j=0;j<points.size();j++){
                 if(j!=i){
                     imap[dis(points[j],points[i])]++;
                 }
             }

             for(unordered_map<int,int>::iterator it=imap.begin();it!=imap.end();it++){
                 if(it->second>=2){
                     res+=it->second*(it->second-1);
                 }

             }
         }
         return res;
     }
};


//方法二：采用优化后的方法进行求解：采用数组的形式进行求解。
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<long, int> group(points.size());
            for (int j = 0; j < points.size(); j++) {
                if (j == i) {
                    continue;
                }
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int key = dy * dy;
                key += dx * dx;
                group[key]++;
            }
            
            for (auto& p : group) {
                if (p.second > 1) {
                    res += p.second * (p.second - 1);
                }
            }
        }
        return res;
    }
};

