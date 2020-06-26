#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>

using namespace std;


/*
高考成绩2000万数据，分数0-750，如何快速知道你的排名，如何知道任一分数排名 --->桶排序 （3）

*/

/*
算法描述：
1） 设置一个定量的数组当做空桶；
2）遍历输入数组，将数据放入对应的桶中；
3）对每个不是空的桶进行排序；
4）从不是空的桶中将数据进行拼接；
*/


map<int,vector<int>> BucketSort( vector<int>& nums){
    int maxValue = INT_MIN;
    int minValue = INT_MAX;

    for( int i = 0  ;i < nums.size() ;i++){
        maxValue = max( maxValue ,nums[i]);
        minValue = min( minValue ,nums[i]);
    }

    int bucketNum = 751;
    map<int,vector<int>> res(751);

    for( int i = 0 ;i < nums.size() ;i++){
        res[i].push_back(nums[i]);
    }

    for(int i = 0 ;i < res.size() ;i++){
        sort( res[i].begin(),res[i].end());
    }

    return res;
}