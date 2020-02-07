class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numsSort) {
        vector<vector<int>> nums;
        sort(numsSort.begin(),numsSort.end());
        
        int length=numsSort.size()-1;
        for(int i=0;i<length-1;i++){
          
            if(numsSort[i]>0){
                break;
            }
            if(i>0&&numsSort[i]==numsSort[i-1]){
               continue;
            }
              int Length=length;
              int j=i+1;
            while(j<Length){
                    
                    int sum=numsSort[i]+numsSort[j]+numsSort[Length];
                    if(sum<0){
                        ++j;
                    }else if(sum>0){
                       --Length;
                    }else{
                         
                        nums.push_back({numsSort[i],numsSort[j],numsSort[Length]});
                        while (j < Length && numsSort[j] == numsSort[++j]);
                        while (j < Length && numsSort[Length] == numsSort[--Length]);
                    }                    
            }
           
        }
         return nums;
    }
};