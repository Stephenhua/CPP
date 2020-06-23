#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
1093. 大样本统计
我们对 0 到 255 之间的整数进行采样，并将结果存储在数组 count 中：count[k] 就是整数 k 的采样个数。

我们以 浮点数 数组的形式，分别返回样本的最小值、最大值、平均值、中位数和众数。其中，众数是保证唯一的。

我们先来回顾一下中位数的知识：

如果样本中的元素有序，并且元素数量为奇数时，中位数为最中间的那个元素；
如果样本中的元素有序，并且元素数量为偶数时，中位数为中间的两个元素的平均值。
 

示例 1：

输入：count = [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
输出：[1.00000,3.00000,2.37500,2.50000,3.00000]
示例 2：

输入：count = [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
输出：[1.00000,4.00000,2.18182,2.00000,1.00000]
 

提示：

count.length == 256
1 <= sum(count) <= 10^9
计数表示的众数是唯一的
答案与真实值误差在 10^-5 以内就会被视为正确答案

*/

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {

    }
};

typedef long long ll;
typedef double db;
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n=count.size();
        ll sum=0;
        int cnt=0,maxx=0,temp=0;
        int half=-1,halfcount=0;
        vector<int>res;
        res.reserve(256);
        for(int i=0;i<n;i++){
            //将 0 跳出去；
            if(count[i]==0)continue;
            //res中存储的数据；
            res.push_back(i);
            //求解和；
            sum+=count[i]*i;
            //求解数的个数；
            cnt+=count[i];
            //求解众数
            if(count[i]>temp){
                temp=count[i];
                maxx=i;
            }
            while(halfcount==0||cnt/2>halfcount){
                half++;
                halfcount+=count[res[half]];//halfcount表式的含义是拥有多少个数据
            }
        }
        //下面是判断中位数的，因为上面的while操作，所以我们再进行中位数的判断会非常的容易。。。
        db med;
        if(cnt/2==halfcount){//这个表示的是，我们拥有偶数个数据
            med=(db)0.5*(res[half]+res[half+1]);
        }else{
            med=(db)res[half];
        }
        vector<db>ans;
        ans.push_back(1.0*res[0]);
        ans.push_back(1.0*res.back());
        ans.push_back(1.0*sum/cnt);
        ans.push_back(med);
        ans.push_back(1.0*maxx);
        return ans;
    }
};

//方法二：
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res = { 255, 0, 0, 0, 0 };
        int sum_all = accumulate(begin(count), end(count), 0), m_cnt = 0;
        int l = sum_all / 2, r = l + (sum_all & 1 ? 0 : 1);
        for (int i = 0, cnt = 0; i < count.size(); cnt += count[i++]) 
        {
            res[0] = count[i] ? min((int)res[0], i) : res[0];
            res[1] = count[i] ? i : res[1];
            res[2] += (double)i * count[i] / sum_all;

            if (cnt < l && cnt + count[i] >= l) res[3] += (double)i / 2;
            if (cnt < r && cnt + count[i] >= r) res[3] += (double)i / 2;

            res[4] = m_cnt < count[i] ? i : res[4];
            m_cnt = max(m_cnt, count[i]);
        }
        return res;
    }
};