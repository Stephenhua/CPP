/*
题目：
硬币组合问题之最少硬币个数


问题：如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？

思路：使用动态规划

假设d(i)为凑够i元所需最少硬币数，则
d(0) = 0 　　　　　　　　理所当然


d(1) = 1 　　　　　　　　要凑够1元，需要从面值小于等于1元的硬币中选择，目前只有面值为1元的硬币
　　　　　　　　　　　　此时d(1) = d(0) + 1


d(2) = d(2 - 1) + 1 = 2， 从面值小于等于2元的硬币中选择，符合要求的硬币面值为：1元。
　　　　　　　　　　　　此时d(2) = d(2-1) + 1


d(3) = d(3 - 3) + 1 = 1， 从面值小于等于3元的硬币中选择，符合要求的硬币面值为：1元，3元。
　　　　　　　　　　　　此时有有两种选择：是否选择含有面值3元的硬币
　　　　　　　　　　　　含有3元硬币：d(3) = d(3 - 3) + 1 = 1
　　　　　　　　　　　　不含3元硬币：d(3) = d(3 - 1) + 1 = d(2) + 1 = 3
　　　　　　　　　　　　自然是选择二者中较小值

那这里我们加上的是哪个硬币呢。嗯，其实很简单，把每个硬币试一下就行了：
假设最后加上的是 1 元硬币，那 d(i) = d(j) + 1 = d(i - 1) + 1。
假设最后加上的是 3 元硬币，那 d(i) = d(j) + 1 = d(i - 3) + 1。
假设最后加上的是 5 元硬币，那 d(i) = d(j) + 1 = d(i - 5) + 1。
我们分别计算出 d(i - 1) + 1，d(i - 3) + 1，d(i - 5) + 1 的值，取其中的最小值，即为最优解，也就是 d(i)
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

void  CoinsMinNum(int target , vector<int>& coins){
    vector<int> dp(target+1);
    vector<int> value;
    dp[0]=0;
    map<int,int> res;

    if(target==0 || coins.empty()){
        return ;
    }
    for(int i=1;i<=target;i++){
        
        dp[i]=INT_MAX-10000;
    }
    for(int i =1 ;i<=target ; i++){

        int min = i ;

        cout<<min<<endl ;

        for(int coin:coins){

            if(i>=coin && (dp[i-coin]+1 < min)){
                min = dp[i-coin]+1;
                cout <<"min"<<min <<endl;
                res[coin]++;                
            }
        }

        dp[i] = min ;

    }

    cout << "target" << dp[target] <<endl;

    map<int,int>::iterator Itor;

    for(Itor = res.begin(); Itor!=res.end();Itor++){
        cout<<"Coins: "<<Itor->first <<" NUm: "<<Itor->second << endl;
    }

}

int main( int argc ,char* argv[]){

    vector<int> coins={1,3,5};

    int target =1;

    int target2 = 5 ;

    int target3 =11;

    //CoinsMinNum(target , coins);

    CoinsMinNum( target2 ,coins) ;
    cout<<"================================"<<endl;
   CoinsMinNum( target3 ,coins);

    system("pause");

    return 0;
}



