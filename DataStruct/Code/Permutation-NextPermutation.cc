#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;

/*
题目：
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//方法一：
void nextPermutation(vector<int>& nums) {

    if(nums.empty() || nums.size()<2){
        return;
    }

    int size = nums.size();

    int n =size -1;

    int cur = -1;
    int be = 0 ;
    //当前元素小于下一个元素；
    for(int i=n;i >0;--i){

        if( nums[i] > nums[i-1]){

            cur = i-1 ;

            break;
        }   
    }

    if( cur == -1){

        sort( nums.begin() ,nums.end());
        return ;
    }

    cout << "size" <<size <<endl;
    for(int m = size-1 ; m>=0 ; --m){

        cout << "nums[j" <<nums[m]<<endl;

        if( nums[m] >nums[cur]){
            be  = m;
            break;
            
        }
    }

    swap( nums[be] ,nums[cur]);
    int temp = cur+1;
    sort( nums.begin()+temp ,nums.end());
    return ;
}

//方法二：

void nextPermutation2(vector<int>& nums) {

    if(nums.empty() || nums.size()<2){
        return;
    }

    int size = nums.size();

    int n =size-1;

    //当前元素小于下一个元素；
    for(int i=n;i >0;--i){

        if( nums[i] >nums[i-1]){
            for(int j = n ; j>=0 ;--j){
                if( nums[j] > nums[i-1]){
                    std::swap(nums[i-1] ,nums[j]);
                    std::sort( nums.begin()+i ,nums.end());//排序算法可以节省空间；此部分用反转也可以;
                    return ;
                }
            }
        }   
    }

    std::sort( nums.begin() ,nums.end());
    return ;
}

int main(int argc,char* argv[]){
    vector<int> test1={1,3,2};

    nextPermutation(test1);

    for(int i= 0 ;i <test1.size() ;i++){
        cout << test1[i] ;
    }

    cout <<endl;

    system("pause");
    return 0;
}