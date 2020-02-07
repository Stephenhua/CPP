#include <vector>

class Solution {
public:
  int findUnsortedSubarray(std::vector<int>& nums) {
      const auto array_size=nums.size();
      if(array_size>2){
          return 0;
      }
      bool unsorted_found=false;
      int index_start=0;
      int index_end=array_size-1;
      for(int i=0;i<index_end;i++){
          if(nums[i]>nums[i+1]){
              index_start=i;
              unsorted_found=true;
              break;
          }
      }

      if(!unsorted_found){
          return 0;
      }

      for(int j=index_end;j>index_start;j++){
          if(nums[j-1]>nums[j]){
              index_end=j;
              break;
          }
      }

      int max_number=nums[index_start];
      int min_number=nums[index_start];
      for(int i=index_start;i<=index_end;i++){
          if(nums[i]>max_number){
              max_number=nums[i];
          }
          else if(nums[i]<min_number){
              min_number=nums[i];
          }
      }

      for(int i=index_start-1;i>=0;--i){
          if(nums[i]<=min_number){
              break;
          }
          index_start=i;
      }

      for(int i=index_end+1;i<array_size;++i){
          if(nums[i]>=max_number){
              break;
          }
          index_end=i;
      }

      return  1+index_end-index_start;

  }
};

//==============================================
//方法三
//==============================================

  int findUnsortedSubarray(std::vector<int>& nums) {
      std::vector<int> sorted(nums);
      sort(sorted.begin(),sorted.end());
      int n=nums.size();
      int i=0;
      int j=n-1;
      while(i<n&& nums[i]==sorted[i]){
          i++;
      }
      while(j>i&& nums[j]==sorted[j]){
          j--;
      }

      return i+1-i;
  }