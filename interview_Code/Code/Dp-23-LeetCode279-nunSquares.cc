#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
279. 完全平方数
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

*/

/*
每一个数字可以进行拆分，不同的数字需要进行不同的方式；

动态规划算法:
1)状态条件
dp[i] 表示 在 i 时，所需要的最小个数；
2）转移方程

dp[i] = min( dp[i] , dp[i-j*j] +1);

3）初始条件
dp[i+1] = 0 ;
dp[i]  = i ;
4） 结果：dp[n];
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0) ;

        for(int i = 1; i<=n ;i++){
            dp[i] = i ;
            for(int j =1 ; i-j*j >=0 ;j++){
                dp[i] = min( dp[i] , dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};


//方法二：采用广度优先的方法进行求解；
class Solution 
{
public:
    int numSquares(int n) 
    {
    	queue<int> Queue;
    	int step=1;
    	Queue.push(n);
    	int i;
    	if(is2(n))
    	{
    		return 1;
    	}
    	while(!Queue.empty())
    	{
    		int _size=Queue.size();

    		for(i=0;i<_size;i++)
    		{
    			int num=Queue.front();
    			Queue.pop();

    			for(int j=1;j*j<=num;j++)
    			{
    				int b;
    				b=num-j*j;
                    //得到一个减去的数；如果直接为0，那么将会加1返回；否则进行判断余数是否可以直接进行开根号，如果可以的话，那么直接加1返回，否则压入到queue中，进行下一次的放回；

    				if(b==0)
    				{
    					cout<<b<<endl;
    					return step;
    				}
    				else
    				{
    					if(is2(b))
    					{
    						cout<<b<<endl;
    						return step+1;
    					}
    					else
    					{
    						Queue.push(b);
    					}
    					
    				}
    			}
    			 

    		}

    		step++;
    	}
    	return -1;


    }
	//采用二分法进行判断是否相同，直接一个平方就可以实现；
 	bool is2(int num) 
 	{
        // binary search
        int i=1;
        int n=(num>>1)+1;
        while(i<=n){
            int mid=i+(n-i)/2;
            long square=(long)mid*mid;
            if(square==(long)num) return true;
            else if(square<(long)num){
                i=mid+1;
            }
            else {
                n=mid-1;
            }
        }
        return false;
    }



};