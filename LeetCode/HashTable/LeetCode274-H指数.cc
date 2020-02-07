#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//找到其中的一个元素，大等元素的个数与其相等；
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
        {
            return 0;
        }

        int n=citations.size();
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            if(citations[i]>=n){
                hash[n]++;
            }else{
                hash[citations[i]]++;
            }
        }
        int paper=0;
        for(int i=n;i>0;i--){
            paper+=hash[i];
            if(paper>=i){
                return i;
            }
        }

        
    }
};

//方法二：

class Solution {
    private:
    static bool cmp(int a ,int b){
        return a>b;
    }
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0){
            return 0;
        }

        sort(citations.begin(),citations.end(),cmp);
        int i;
        for(i=1;i<=citations.size();i++){
            if(i>citations[i-1]){
                break;
            }
        }
        retutn i-1;

    }

};



class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(),citations.end());

        int h=0;

        int counter= citations.size();

        for(int x:citations){
            h+=(x>--counter);
        }
        return h;
    }

};