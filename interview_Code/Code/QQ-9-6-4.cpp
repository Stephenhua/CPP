#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
int main (int argc, char*argv[]){
    int n ;
    cin >>n;
    vector<int> arr(n,0);
    for(int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int mid = n/2;

    for(int i =0 ;i < n ;i++){
        if(i <mid){
            cout << arr[mid]<<endl;
        }else{
            cout << arr[mid-1]<<endl;
        }
    }
    system("pause");
    return 0 ;
}
*/

int getHeap(vector<int>& nums){
    struct compare
    {
        int operator()(int left ,int right){
            return left >right;
        }
    };

    priority_queue<int,vector<int>,compare> heap;
    int len = (nums.size()+1)/2;
    for(int i = 0 ; i <len ;i++){
        heap.push(nums[i]);
    } 

    for(int i = len ;i< nums.size() ;i++){
        if(nums[i] > heap.top()){
            heap.pop();
            heap.push(nums[i]);
        }
    }

    if(!heap.empty()){
        return heap.top();
    }
}

int main (int argc, char*argv[]){
    int n ;
    cin >>n;
    vector<int> arr(n,0);
    for(int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }
    vector<int>::iterator It;

    vector<int> temp ;

          for(int i = 0 ;i < n ;i++){
              temp = arr;
              temp.erase(temp.begin()+i);
            int res = getHeap(temp);
            cout <<res <<endl;
          }
         
    return 0 ;
}

