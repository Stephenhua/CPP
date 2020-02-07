#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//方法一：使用“快慢指针”思想找出循环：“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期。此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。
class Solution {
public:
     int  bitSquareSum(int n){
        int sum=0;
        while(n>0){
            int bit =n%10;
            sum+=bit*bit;
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow =n,fast =n;

        do{
            slow =bitSquareSum(slow);
            fast =bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while (slow!=fast);
        return slow==1;
    }

};

//方法二：采用循环的方式进行求解

class Solution {
public:
     int  bitSquareSum(int n){
         unordered_set<int> seen;
         while(n!=1){
             int current=n;
             int sum=0;
             while(current!=0){
                 sum+=(current%10)*(current%10);
                 current=current/10;
             }
             if(seen.find(n)!=seen.end()){
                 return false;
             }

             seen.insert(n);
             n=sum;
         }
         return true;

     }
};
