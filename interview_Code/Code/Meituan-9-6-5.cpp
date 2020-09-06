#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;


/*
题目：输入一个数组是点名的编号，点到谁就将其放到队列的首位，然后进行输出；
采用倒叙的形式进行数组的输出，对于重复的数字，直接进行跳过；如果没有出现的数字，进行输入即可；
*/
int main(int argc,char* argv[]){
    int n ;
    cin >> n;
    vector<int> nums;
    for (size_t i = 0; i < n; i++)
    {
        cin >>nums[i];
    }

    unordered_set<int> It;
    for(int i = n-1 ;i >= 0 ;i--){
        if( It.count(nums[i])){
            continue;
        }
        cout << nums[i]<<endl;
        It.insert(nums[i]);
    }

    return  0 ;
    
}