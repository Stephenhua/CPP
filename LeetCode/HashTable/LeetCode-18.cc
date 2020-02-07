#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        if(nums.size()<4){
            return result;
        }

        //对数组进行排序
        sort(nums.begin(),nums.end());

        int length=nums.size();
        int i=0;
        for( i=0;i<length-3;i++){
            if( i >0 && nums[i]=nums[i-1]){
                continue;
            }

            int num1 =nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
            if(num1>target){
                break;
            }
            int max1=nums[i]+nums[length-1]+nums[length-2]+nums[length-3];
            if(num1<target){
                continue;
            }

            for(int j=i+1;j<length-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }

                int k=i+1;

                int h=length-1;

                int min=nums[k]+nums[i]+nums[j]+nums[k+1];
                
                if(min>target){
                    continue;
                }
                int max= nums[i]+nums[j]+nums[h-1]+nums[h];
                if(max<target){
                    continue;
                }

                while(k<h){
                    int curr =nums[i]+nums[j]+nums[k]+nums[h];
                   
                    if(curr==target){
                        result.push_back({nums[i],nums[j],nums[k],nums[h]});
                        
                        k++;
                        
                        while(k<h&&nums[k]==nums[k-1]){
                            k++;
                        }

                        h--;
                        
                        while (j<h&&k<h&&nums[h]==nums[h+1])
                        {
                            h--;
                            /* code */
                        }
                        
                    }else if(curr>target){
                        h--;
                    }
                    else{
                        k++;
                    }
                }
            }


        }
        return result;

}

//方法二：
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

    if(nums.size()<4)
    {
        return;
    }
    sort(nums.begin(),nums.end());
    int N=nums.size();

    int maxSum3=nums[N-3]+nums[N-2]+nums[N-1];
    int maxSum2=nums[N-2]+nums[N-1];
    vector<vector<int>> res;
    for(int i=0;i<N-3;i++){
        if(4*nums[i]<target){
            break;
        }
        if(i>0&&nums[i]==nums[i+1])
        {
            continue;
        }

        if(nums[i]+maxSum3<target){
            continue;
        }
        for(int j=i+1;j<N-2;j++){
            if(2*(nums[i]+nums[j])>target){
                break;
            }
            if(j>i+1&&nums[j-1]==nums[j]){
                continue;
            }
            if(nums[i]+nums[j]+maxSum2<target){
                continue;
            }
            int t=target-nums[i]-nums[j];
            int l=j+1;
            int r=N-1;
            while(l<r){
                if(nums[l]+nums[r]>t){
                    --r;
                }else if(nums[l]+nums[r]<t){
                    ++l;
                }else{
                    res.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[++l]);
                    while(l<r&&nums[r]==nums[--r]);
                }
            }
        }

    }

    
    
    
    }



}；