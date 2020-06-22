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
904. 水果成篮
在一排树中，第 i 棵树产生 tree[i] 型的水果。
你可以从你选择的任何树开始，然后重复执行以下步骤：

把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
用这个程序你能收集的水果总量是多少？

 

示例 1：

输入：[1,2,1]
输出：3
解释：我们可以收集 [1,2,1]。
示例 2：

输入：[0,1,2,2]
输出：3
解释：我们可以收集 [1,2,2].
如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
示例 3：

输入：[1,2,3,2,2]
输出：4
解释：我们可以收集 [2,3,2,2].
如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
示例 4：

输入：[3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：我们可以收集 [1,2,1,1,2].
如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 个水果。

*/
/*
直接进行指针移动既可以实现；
核心思路：
1）当篮子中种类数<=2时，右指针移动
2）当篮子个数>2时，左指针移动
3）通过left和right来计算滑窗的最大值
4）用map来统计不同果子个数和果子种类

*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {

        int size = tree.size();
        int res = 0 ;
        unordered_map<int,int> num;

        int left = 0 ;

        for( int i = 0 ;i <size ;i++){

            num[tree[i]]++;
            while( num.size() >2){
                num[tree[left]]--;

                if( num[tree[left]] == 0){
                    num.erase(tree[left]);
                }

                left++;
            }
            res= max(res,i-left+1);
        }
        return res;

    }
};


//方法二：
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, cur = 0, cntB = 0, a = 0, b = 0;
        for (int fruit : tree) {
            cur = (fruit == a || fruit == b) ? cur + 1 : cntB + 1;
            cntB = (fruit == b) ? cntB + 1 : 1;
            if (b != fruit) {
                a = b; b = fruit;
            }
            res = max(res, cur);
        }
        return res;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int a = -1, b = -1, max = 0, count = 0;

        //挨个进行遍历；
        for (int i = 0; i < tree.size(); i++) {
            //刚开始的时候，那么直接令 a 为0 ；
            if (i == 0) {
                a = 0;
                count = 1;
            } else if(tree[i] == tree[i - 1]) {//如果当前元素和之前的元素相同，那么直接count++；
                count++;
            } else if (b == -1) {//此时b为空，直接令b 为i；
                b = i;
                count++;
            } else if (tree[i] == tree[a] || tree[i] == tree[b]) {//存在的相等的话，那么更新下标值；
                a = b;
                b = i;
                count++;
            } else {
                a = b;//不停的更新坐标，为了在面对不不同的数时候，进行更新；
                b = i;
                count = i - a + 1;
            }
            if (count > max)
                max = count;
            // cout << "value = " << tree[i] << " a = " << a << " b = " << b << " i = " << i << " max = " << max << " count = " << count << endl;
        }
        return max;
    }
};