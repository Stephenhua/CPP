#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

/*

算法：计算pow(x,n)函数；
方法一：采用二分思想，复杂度是对数级的；
*/

//方法一：采用二分思想+递归思想进行处理；时间复杂度：longn ;空间复杂度为long n;
/*
使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘，
如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。
还有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可。
我们让i初始化为n，然后看i是否是2的倍数，是的话x乘以自己，否则res乘以x，i每次循环缩小一半，直到为0停止循环。
最后看n的正负，如果为负，返回其倒数。
*/
class Solutions {
    public:
        double myPow(double x,int n){
            if(n==0){
                return 1;
            }
            if(n==1){
                return x;
            }
            if(n==-1){
                return 1/x;
            }

            double half=myPow(x,n/2);
            double rest=myPow(x,n%2);
            return rest*half*half ;

        }

};


//采用递归的形式进行求解，然后需要区分奇偶幂次；

class Solutions{
    public:

        double claculate(double x,long n){
            if(n==0){
                return 1;
            }else{
                return claculate(x*x,n/2)*(n%2?x:1);;
            }
        }
        double myPow(double x,int n){
            if(x==1.0) return x;
            if(n==0) return 1;
            if(n>0) return claculate(x,n);
            else
            {
                return 1/claculate(x,-long(n));
            }
        
        }
};

//采用快速幂算法（循环）https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode/

class solutions_3{
     public:
      double myPow(double x,int n){
          long long N=n;//需要进行类型转换

          //当出现n<0的时候，该如何进行操作；
          if(N<0){
              x=1/x;
              N=-N;
          }

          double ans=1;
          double current_product=x;

          for(int i=N;i;i/=2){
              if(i%2==1){
                  ans=ans*current_product;
              }//区分就幂次的时候进行求解；
              current_product=current_product*current_product;
          }
          return ans;
      }

};



