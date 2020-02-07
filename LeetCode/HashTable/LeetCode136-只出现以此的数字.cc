
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//方法一：采用set方法进行插入，如果里面存在值，则就直接删除，最后只剩下一个数，该数就是所要求的的值
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> temp_value;
        for(int num:nums){
            if(temp_value.count(num)){
                temp_value.erase(num);
            }else{
                temp_value.insert(num);
            }
        }
        return *temp_value.begin();        
    }
};

//方法二：采用二进制的方法进行求解，直接进行相与运算，相同的为0 ，不相同的为1 ，最后就剩下一个值
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto num:nums){
            res^=num;
        }
        return res;
    }

};


//方法三：依旧采用二进制的形式进行，只不过循环的方式发生改变
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};
