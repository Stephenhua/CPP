#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;


/**
*方法一：采用暴力算法进行计算
*验证某个数是否为质数时，将其对每一个比其小的数进行取余运算，并对取余为零的情况进行计数。
由于质数是指在大于 1 的自然数中，除了 1 和它本身以外不再有其他因数的自然数。所以，当计数结果为 1 时，该数为质数。
在实际操作中，由于 1 和任意一个数必然取余为零，所以可以直接排除。并当没有取余为零的情况时，其才为质数。*
*
*/
class Solution {
public:
    int countPrimes(int n) {
        int count =0;
        for(int i=2;i<n;i++){
            bool sign=true;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    sign=false;
                    break;
                }
            }
        }
        if(sign){
            count++;
        }
        return count;
        
    }
};

/*
方法二:优化暴力算法：
如果一个数为9，那么其二分之一后的数都可以不用进行计算，因为肯定是多余的；
对于正整数n,如果用2到根号n之间的多有整数去除，均无法整除，则n为质数。
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<3){
            return 0;
        }
        int count=1;
        for(int i=3;i<n;i++){

            if((i&1)==0){
                continue;
            }

            bool sign=true;
            //利用j*j<i进行排除替换
            for(int j=3;j*j<=i;j+=2){
                if(i%j==0){
                    sign=false;
                    break;
                }
            }
            if(sign){
                count++;
            }

        }
        return count;
    }
};

/*
方法三:优化暴力算法：
如果一个数为9，那么其二分之一后的数都可以不用进行计算，因为肯定是多余的；
对于正整数n,如果用2到根号n之间的多有整数去除，均无法整除，则n为质数。
*/

class Solution {
public:
    int countPrimes(int n) {
        int count =0;

        vector<int> signs(n,true);
        for(int i=2;i<n;i++){
            if(signs[i]){
                count++;
                for(int j=i+i;j<n;j++){
                    //排除不是质数的数
                    signs[j]=false;
                }
            }
        }

        return count;

    }
};

//方法四：采用标记的形式进行求解


class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        memset(prime,true ,sizeof(prime));
        int count =0;
        for(int i=2;i*i<n;i++){
            if(prime[p]==true){
                for(int j=p*p;i<n;i+=p){
                    prime[i]=false;
                }

            }
        }

        for(int i=2;i<n;i++){
            if(prime[i]==true){
                count++;
            }
        }
        return count;
    }
};

