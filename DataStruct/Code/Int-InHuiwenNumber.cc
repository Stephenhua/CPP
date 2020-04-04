#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include "BinaryTreeNode.h"
using  namespace std;

/*
判断一个整数是否为回文数
*/

//思路一：将整数改为字符创类型，然后采用前后指针法进行求解；

//思路二：将整数进行余数除，然后压入到vector中，然后进行求解，

//上述两种方法都空间复杂度为 o(n ),时间复杂为O(n)

//方法三：采用折中查找的方法进行求解；时间复杂度为O(long n) ,空间复杂度为O(1)

bool isPalindrom(int x){
    
    int sum=0;
    
    if(x<0 || (x/10!=0 && x%10 == 0)){
        return false;
    }else{
        while(x>sum){
            sum=sum*10+x%10;
            x=x/10;
        }
    }

    /*如果整数位偶数，如下*/

    if(sum ==x ){
        return true;
    }
    /*如果为奇数，则发生新的变化*/

    if((sum/10)==x){
        return ture;
    }

    return false ;
}