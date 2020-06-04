#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
题目：78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<vector<int>> res;
void getSubSetCore( vector<int>& nums, int start,vector<int>& rs){

    res.push_back( rs);
    for( int i=0 ;i<rs.size() ;i++){
        cout<<rs[i];
    }
    cout<<endl;

    for( int i = start ;i<nums.size() ;i++){
        
        rs.push_back( nums[i]);
        getSubSetCore( nums,i+1, rs);
        rs.pop_back();        
    }
}

void getSubSet( vector<int>& nums ){

    if( nums.size() == 0){
        return ;
    }

    int size = nums.size();
    vector<int> rs;

    getSubSetCore( nums,0 ,rs);
     
}

//方法二：进行回溯算法实现；

/*
路径：记录到中；
选择列表：nums中不存在于track中的值；
结束条件：每一个sub_set都是；

*/
void dfsFind( vector<vector<int>>& sub_sets ,vector<int>& sub_set, vector<int> & nums, int pos){

    sub_sets.push_back(sub_set);

    //这里面的循环是破pos表示选择列表；
    
    for( size_t i = pos ; i<nums.size() ;i++){
        sub_set.push_back(nums[i]);
        dfsFind(sub_sets ,sub_set,nums, i+1);
        sub_set.pop_back();
    }
}

vector<vector<int>> subsets( vector<int>& nums){

    sort( nums.begin() ,nums.end());

    vector<vector<int>> sub_sets;

    vector<int> sub_set;

    dfsFind( sub_sets,sub_set,nums,0);

    return sub_sets;
}



int main ( int argc ,char* argv[]){

    vector<int> nums = { 1,2,3};
    getSubSet(nums);

    for(int i=0 ;i<res.size() ;i++){
        for( int j = 0 ;j< res[i].size() ;j++){
            cout<<res[i][j];
        }
        cout <<endl;

    }
    system("pause");
    return 0 ;
}