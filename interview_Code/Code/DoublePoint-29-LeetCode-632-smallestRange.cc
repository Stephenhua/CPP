#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
632. 最小区间
你有 k 个升序排列的整数数组。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

示例 1:

输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出: [20,24]
解释: 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
注意:

给定的列表可能包含重复元素，所以在这里升序表示 >= 。
1 <= k <= 3500
-105 <= 元素的值 <= 105
对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。

*/

/*
先进行排序，然后进行滑动窗口进行比较；
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> ordered;

        for( int i = 0 ;i < nums.size() ;i++){
            for( int j= 0 ;j < nums[i].size() ;j++){
                ordered.push_back({nums[i][j], i});
            }
        }
        //进行整体的排序；
        sort( ordered.begin() ,ordered.end());

        int i = 0 , k =0 ;//双指针的初始坐标状态；
        vector<int> rs;
        unordered_map<int ,int > count;
        //根据顺序进行遍历操作；
        for(int j = 0 ; j < ordered.size() ;++j){
            //对于当前状态进行相减；
            if( ! count[ordered[j].second]++) {
                ++k;
            }
            //如果k值和nums.size() 相等，即表明个数等于行数；
            if( k == nums.size()){
                //进行窗口减小；左边界缩小；
                while( count[ordered[i].second] > 1){
                    --count[ordered[i++].second];
                }
                if( rs.empty() || rs[1]-rs[0] > ordered[j].first -ordered[i].first){
                    rs = vector<int>{ ordered[i].first ,ordered[j].first};
                }
            }


        }
        return rs;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> result(2);
        result[0]=-100000-1;
        result[1]= 100000+1;
        //
        int K=nums.size();
        vector<int> nums_size(K);
        bool flag=true;
        //维护动态区间[a,b]
        int a=-100000, b=a;
        vector<int> idx(K,0);//每个列表中大于等于result[0]的最小值的id
        bool end=false;
        while(!end)
        {
            //a move forward
            int tem=100000;
            for(int k=0;k<K;k++)
            {
                if(flag) 
                {
                    nums_size[k]=nums[k].size();
                    //b向前移动，保证覆盖所有数组
                    if(nums[k][idx[k]]>b)
                    {
                        b=nums[k][idx[k]];
                    }
                }

                while(idx[k]<nums_size[k]&&nums[k][idx[k]]==a)
                {
                    idx[k]++;
                    //b向前移动，保证覆盖所有数组
                    if(idx[k]<nums_size[k]&&nums[k][idx[k]]>b)
                    {
                        b=nums[k][idx[k]];
                    }
                }
                //cout<<"idx["<<k<<"]="<<idx[k]<<endl;
                if(idx[k]<nums_size[k])
                {
                    tem=tem>nums[k][idx[k]]?nums[k][idx[k]]:tem;
                }
                else
                    end=true;//尾小于区间的新起点
            }
            a=tem;
            //cout<<a<<", "<<b<<endl;
            flag=false;
            //记录
            if(!end&&b-a<result[1]-result[0])
            {
                result[0]=a;
                result[1]=b;
            }
        }
        return result;
    }
};