#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

/*
1122. 数组的相对排序
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中


*/


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int size1 = arr1.size();
        int size2 = arr2.size();

        if(size1 == 0){
            return res;
        }

        if( size2 == 0 ){
            sort(arr1.begin(),arr1.end() );
            return arr1;
        }
        //temp和i保持一致；
        int temp = 0 ;

        for(int i = 0 ; i< size2 ; i++){
            for(int j = 0 ; j<size1 ; j++){
                if( arr1[j] == arr2[i]){
                    swap( arr1[j] , arr1[temp]);
                    temp++;
                }
            }

        }
        sort( arr1.begin()+temp, arr1.end());
        return arr1;
    }
};



class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> count(1001,0);
        for(int num:arr1){
            count[num]++;
        }

        int i = 0 ;
        for(int num2 : arr2 ){
            while(count[num2]){
                arr1[i++] = num2;
                count[num2]--;
            }
        }

        for( int num1 = 0 ; num1 < count.size() ; num1++ ){
            while( count[num1]){
                arr1[i++] = num1;
                count[num1]--;
            }
        }

        return arr1;
    }

};