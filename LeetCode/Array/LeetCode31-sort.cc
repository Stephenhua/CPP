class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        int len=nums.size();
        for(;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i!=-1){
            for(int j=len-1;j>i;j--){
                if(nums[j]>nums[i]){
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j] =temp;
                    break;
                }
            }
        }
        for(int j=1;j<=(len-i-1)/2;j++){
            int temp=nums[j+i];
            nums[j+i]=nums[len-j];
            nums[len-j]=temp;
        }
        
    }
    
};