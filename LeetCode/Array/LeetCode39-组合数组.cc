#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
//解法一：首先对目标值进行遍历，然后得到1..target的值；
//然后将目标数组进行遍历
//分为两种情况
//1、对于相等的数，直接加入到列表中
//2、对于小于数组的数，直接进行比较；比较每一个数组中的vector.从而进行dp[j-*it]的内部遍历

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        map<int, set<vector<int> > > dpkv;
        set<vector<int>> avectorset;
        for(int i=1;i<=target ;i++){
            dpkv[i]=avectorset;
        }

        for(int j=1;j<=target ;j++){
            for(vector<int>::iterator it=candidates.begin();it!=candidates.end();it++){
                if(j==*it){
                    vector<int> v_only;
                    v_only.push_back(*it);
                    dpkv[j].insert(v_only);
                }else if(j>*it){
                    for(set<vector<int>>::iterator its=dpkv[j-*it].begin();its!=dpkv[j-*it].end();its++){
                        vector<int> the_cvector;
                        the_cvector.push_back(*it);
                        std::sort(the_cvector.begin(),the_cvector.end());
                        dpkv[j].insert(the_cvector);
                    }
                }
            }
        }
        vector<vector<int>> target_v;
        for(set<vector<int> >::iterator its = dpkv[target].begin(); its != dpkv[target].end(); its++){
            target_v.push_back(*its);
        }
        return target_v;
    }
}; 

//解法二：采用回溯算法进行求解
//时间：4ms ,
//
//
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort( candidates.begin(), candidates.end());
        if( candidates.empty() || candidates[0] > target)
            return res;
        
        this->target = target;
        vector<int> tmp;
        findCombinationSum( candidates, 0, 0, tmp);
        
        return res;
    }
private:
    int target;
    vector< vector<int> > res;
    
    void findCombinationSum( const vector<int>& candidates, int pt, int sum, vector<int>& tmp) {
        
        if( sum == target) {
            res.push_back( tmp);
            return;
        }
        
        for( int i=pt; i<candidates.size(); ++i) {
            if( sum + candidates[i]> target)
                break;
            else { // sum + candidates[i] <= target
                tmp.push_back( candidates[i]);
                findCombinationSum( candidates, i, sum + candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};
//解法二：采用深度优先算法进行求解
//时间：4ms ,
//
class Solution {
public:
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> result{};
        vector<vector<int>> results{};
         sort(candidates.begin(),candidates.end());
         dfs(results, result ,candidates,target ,0);
         return results;       

     }
        void dfs(vector<vector<int>>& results,vector<int>& result,vector<int>& candidates, int target ,int level){
            //边界条件
            if(target==0){
                results.push_back(result);
                return;
            }
            
            //查找
            for(int i=level;i<candidates.size()&&target-candidates[i]>=0;++i){
                result.push_back(candidates[i]);
                dfs(results,result, candidates,target-candidates[i],i);
                result.pop_back();
                
            }
        }
};