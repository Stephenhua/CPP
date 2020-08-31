#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
31. 下一个排列
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
*/

//方法一：采用字典序的方法进行
/*
标准的“下一个排列”算法可以描述为：

从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、「大数」
将 A[i] 与 A[k] 交换
可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4

作者：imageslr
链接：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/
void nextPermutation(vector<int>& nums) {
    
    int n =nums.size();
    int i=0,j =0 ;

    //从后往前找到第一个【相邻升序对】，即A[i]<A[i+1]。此时A[i+1,end)为降序。
    for(i = n-2 ;i>= 0 ;--i){
        if( nums[i] < nums[i+1]){
            break;
        }
    }
    //无相邻升序对，必定为非递减序列
    if( i ==-1){
        reverse(nums.begin() ,nums.end());
    }else{
        //从后往前【i+1，end}找到第一个大于num[i+1]的值；
        for( j= n-1 ; j>i ;--j){

            if( nums[j] > nums[i]){

                swap( nums[i],nums[j]);//交换二者；

                reverse( nums.begin()+i+1 ,nums.end());//翻转【i+1，end)，变为升序；此处和sort的功能是相同的；

                break;
            }
        }
    }
    
}

void nextPermutation1(vector<int>& nums) {
    int n = nums.size();
    int i = 0 ;
    int j = 0 ;
    
    for( i = n-2 ; i >=0 ; i--){
        if(nums[i] < nums[i+1]){
            break;
        }
    }

    if( i == -1){
        reverse(nums.begin() , nums.end());
    }else{

        for( j = n-1 ; j > i ; j--){
            if( nums[j] > nums[i] ){
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());
            }
        }
    }
} 

//方法二：直接使用STL库中的函数进行使用；
void nextPermutation(vector<int>& nums)
{
    next_permutation(nums.begin(),nums.end()); // STL功能和题目描述一致
}

//方法三：可以省略中间一步；

 void nextPermutation(vector<int>& nums) {
       int pos=nums.size()-1;
       while(pos>0&&nums[pos]<=nums[pos-1])
            pos--;
       reverse(nums.begin()+pos,nums.end());//先进行翻转；

       if(pos>0){//判断边界条件；

           for(int i=pos;i<nums.size();i++){

                if(nums[i]>nums[pos-1]){
                    swap(nums[i],nums[pos-1]);
                    break;
                }
           } 
       }
 }