#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

Each element in the result must be unique.
The result can be in any order.
 
这道题让我们找两个数组交集的部分（不包含重复数字），
难度不算大，我们可以用个set把nums1都放进去，然后遍历nums2的元素，
如果在set中存在，说明是交集的部分，加入结果的set中，
最后再把结果转为vector的形式即可：

 */

//方法一：采用两个指针法进行求解；
vector<int> intersection1(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    int i=0,j=0;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    while(i<nums1.size()&& j<nums2.size()){
        if(nums1[i]<nums2[j]){
            i++;
        }else if(nums1[i]>nums2[j]){
            j++;
        }else{
            if(res.empty() ||res.back()!=nums1[i]){
                res.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return res;
}

//方法二，采用二分查找法进行求解；是将一个数组排序，
//然后遍历另一个数组，把遍历到的每个数字在排序号的数组中用二分查找法搜索，
//如果能找到则放入结果set中，这里我们用到了set的去重复的特性，
//最后我们将set转为vector即可：

bool binarySearch(vector<int>& arr, int target){
    int left=0;
    int right =arr.size()-1;
    while(left<=right){
        int mid=left+((right-left)>>1);
        if(arr[mid]==target){
            return true;
        }else if(arr[mid]>target){
            right=mid-1;
        }else {
            left=mid+1;
        }
    }
    return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    set<int> res;
    /*
    if((nums1.empty() && !nums2.empty())||(nums2.empty() && !nums1.empty())){
         return vector<int>(res.begin(),res.end());
    }*/
    sort(nums2.begin(),nums2.end());
    for(int i=0;i<nums1.size();i++){
        if(binarySearch(nums2,nums1[i])){
            res.insert(nums1[i]);
        }
    }
    return vector<int>(res.begin(),res.end());
}




// ====================测试代码====================
void Test(vector<int>& arr, vector<int>&arr2,vector<int>& target)
{   
    vector<int> result=intersection(arr,arr2);
    if(result.size()!=target.size()){
        cout<<"Failed"<<endl;
    }else{
        sort(target.begin(),target.end());
        int number=0;
        for(int i=0;i<target.size();i++){
            if(target[i]=result[i]){
                number++;
            }
        }
        if(number==target.size()){
            cout<<"Passed"<<endl;
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> array1={ 3, 4, 5, 1, 2 };
    vector<int> array11={3,4};
    vector<int> array12={3,4};
    Test(array1,array11,array12);

    vector<int> array21={ 3, 4, 5, 1, 2 };
    vector<int> array22={3};
    vector<int> array23={3};
    Test(array21,array22,array23);

    vector<int> array31={ 3, 4, 5, 1, 2 };
    vector<int> array32={};
    vector<int> array33={};
    Test(array31,array32,array33);


     vector<int> array41={ 3, 4, 5, 1, 2 };
    vector<int> array42={ 3, 4, 5, 1, 2 };
    vector<int> array43={ 3, 4, 5, 1, 2 };
    Test(array41,array42,array43);

    system("pause");

    return 0;
}