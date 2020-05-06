 #include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;
/*
题目：
全排列
*/
vector<vector<int>> permute0(vector<int>& nums) {
     vector<vector<int>> result ;
    //计算多种情况，就循环多少次
    int num =1;
    for(int i=n;i>0;i--){
        num*=i;
    }
    int cur=0;
    int be=0;

    while(num--){

        result.push_back(nums);

        //从右往左，找出第一个左边小于右边的数，设为arr[i];
        for(int i=n-1;i>0;--i){
            if(nums[i]>nums[i-1]){
                cur=i-1;
                break;
            }
        }

        if( cur < 1 ){

            reverse( nums.begin() ,nums.end());

        }else{
            //从右往左，找出第一个大于arr[cur]的数，设为list[b]
            for(int i=n-1;i>cur;--i){
                if(nums[i]>nums[cur]){
                    be=i;
                    break;
                }
            }

            swap(nums[be],nums[cur]);
            
            //然后进行从cur+1到末尾进行递增排序即可
            sort(nums.begin()+cur+1,nums.end());
        }
    }
    return result ;

 }

vector<vector<int>> permute1(vector<int>& nums) {

    vector<vector<int>> result ;
    //求解循环次数

    int n = factorial( nums.size());
    for( int i =0;i< n ;i++){
        result.push_back(nums);

        //用于求解下一个相邻的值；
        nextPermutation( nums);
    }


    return result ;

}


int factorial(int num ){
    int res =1;
    while( num>1){
        res *= num--;
    }
    return res; 

}

void nextPermutation( vector<int>& nums){
    int n = nums.size() , i, j;

    for( i = n-2 ; i>=0 ;i--){
        if( nums[i] < nums[i+1]){
            break;
        }
    }

    if( i < 0 ){

        reverse( nums.begin() ,nums.end());

    }else{
        for( j = n-1 ; j> i;j--){
            if( nums[i] < nums[j]){
                break;
            }
        }

        swap( nums[i] , nums[j]);

        reverse( nums.begin()+1+i, nums.end());
    }
}


//方法二：采用递归的形式进行求解；

vector<vector<int>> permute2(vector<int>& nums) {
    vector<vector<int>> result; 
    vector<int> out ,visited(nums.size() , 0 );
    //visited用来标记是否已经被访问过；
    premuteDFS(nums, 0 ,visited, out, result);
    return result;
    
} 

void premuteDFS( vector<int>& nums, int level ,vector<int>& visited , vector<int>& out ,vector<vector<int>>& res){

    if( level == nums.size()){
        res.push_back(out);
    }
    for(int i =0 ;i< nums.size() ;i++){

        if( visited[i] == 1){
            continue;
        }
        visited[i] = 1;

        out.push_back(nums[i]);

        premuteDFS( nums ,level+1, visited , out ,res);

        out.pop_back();
        visited[i] = 0;
    }

 }


//方法三：进行递归在此求解；
vector<vector<int>> permute2(vector<int>& nums) {
    vector<vector<int>> result; 

    premuteDFS1(nums, 0 ，result);
    return result;
    
} 


void premuteDFS1( vector<int>& nums, int level ,vector<vector<int>>& res){

    if( level == nums.size()){
        res.push_back(nums);
    }
    for(int i =level ;i< nums.size() ;i++){

        swap( nums[level] , nums[i]);

        premuteDFS( nums ,level+1,res);

        swap( nums[level] , nums[i]);
    }

 }



 int main(int argc,char* argv[]){
    vector<int> test1={};

    vector<vector<int>> result = permute2(test1);

    for(int i = 0 ;i<result.size() ; i++ ){

        for(int j = 0; j<result[i].size() ;j++){
            cout <<result[i][j];
        }
        cout <<endl;
    }

    system("pause");
    return 0;
}