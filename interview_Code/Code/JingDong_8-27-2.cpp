#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

/*
LeetCode : 377
https://leetcode-cn.com/problems/combination-sum-iv/

给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。
进阶：
如果给定的数组中含有负数会怎么样？
问题会产生什么变化？
我们需要在题目中添加什么限制来允许负数的出现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main(int argc, char* argv[]){
    int n , m;
    cin >> n >> m;
    const int mod = 100000000007;
    vector<long long > nums;

    long long temp;

    while( n--){
        cin >> temp;
        if( temp > m ){
            continue;
        }
        nums.emplace_back(temp);
    }

    vector<long long > ans( m+1, 0);
    ans[0] = 1;
    for(int j = 1 ; j<= m ;j++){
        for(int i = 0; i< nums.size() ;i++){
            if( j < nums[i]){
                continue;
            }ans[j] +=ans[j-nums[i]] %mod;
        }
    }

    long long res = ans[m] % mod;
    cout << res << endl;
    return 0;
}
