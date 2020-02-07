#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


//方法以：通过哈希映射的方法进行求解，并且将交集元素放入到两个数组中的一个，这样可以有助于节省空间
/*
*时间复杂度：O(n+m)其中 nn，mm 分别代表了数组的大小。
* 空间复杂度：O(min(n,m))，我们对较小的数组进行哈希映射使用的空间。
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size()){
            return intersect(nums2,nums1);
        }
        //vector<>
        unordered_map<int,int > m;
        //记录num1中的元素个数
        for(auto num:nums1){
            ++m[num];
        }

        int k=0;
        for(auto n:nums2){
            auto it = m.find(n);
            if(it!=m.end()&& --it->second>=0){//判断num1中的元素是否在num2中的元素存在，如果元素存在，则存入到num1列表中
                nums1[k++]=n;
            }
        }
        return vector(nums1.begin(),nums1.begin()+k);
        
    }
};

// 方法二：排序，当输入数据是有序的，推荐使用此方法。在这里，我们对两个数组进行排序，并且使用两个指针在一次扫面找出公共的数字。
//时间复杂度：\mathcal{O}(n\log{n} + m\log{m})O(nlogn+mlogm)。其中 nn，mm 分别代表了数组的大小。我们对数组进行了排序然后进行了线性扫描。
//空间复杂度：O(1)，我们忽略存储答案所使用的空间，因为它对算法本身并不重要

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0;
        int j=0;
        int k=0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i]<nums2[j]){
                ++i;
            }else if(nums1[i]>nums2[j]){
                ++j;
            }else{
                nums1[k++]=nums2[i++];
                ++j;
            }
        }
        return vector(nums1.begin(),nums1.begin()+k);
    }
};

//方法三：这类似于方法 2。我们不使用两个指针进行迭代，而是使用内置函数来查找公共元素。在 C++ 中，我们可以使用 set_intersection 来排序数组（或 multisets）。

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    nums1.erase(set_intersection(begin(nums1), end(nums1), 
        begin(nums2), end(nums2), begin(nums1)), end(nums1));
    return nums1;
}

