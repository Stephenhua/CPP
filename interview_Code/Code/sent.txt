
//移动盒子
    int removeBoxes(vector<int>& boxes) {
        if(boxes.empty()) return 0;
        const int N=boxes.size()+1;
        vector<vector<vector<int>>> d(N,
             vector<vector<int>>(N,vector<int>(N,0)));
        for(int len=1;len <= boxes.size();++len){
            for(int x=0;x+len<=boxes.size();++x){
                const int y=x+len-1;
                for(int a=0;a<=x;++a){
                    int& ans=d[x][y][a];
                    //[x,e-1] == A[x]
                    int e;
                    for(e=x+1;e<=y;++e){
                        if(boxes[e] != boxes[x]) break;
                    }
                    ans = max(ans,(a+e-x)*(a+e-x)+d[e][y][0]);
                    int f=e;
                    for(f;f<=y;++f){
                        if(boxes[f] == boxes[x] && boxes[f-1] != boxes[x]){
                            ans=max(ans,d[e][f-1][0]+d[f][y][e-x+a]);
                        }
                    }
                }
            }
        }
        return d[0][boxes.size()-1][0];
    }

作者：jason-2
链接：https://leetcode-cn.com/problems/remove-boxes/solution/liang-chong-jie-fa-by-jason-2-53/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//无重复数字的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
};

作者：powcai
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//图像翻转：
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int dimension=A.size();
        
        for(int row=0;row<A.size();row++){
            for(int col=0;col<(1+dimension)/2;col++){
                
                int temp=A[row][col]^1;
                A[row][col]=A[row][dimension-1-col]^1;
                A[row][dimension-1-col]=temp;
            }
        }
        return A;
    }

//16. 最接近的三数之和
/*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[1]+nums[2]+nums[0],len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++)
        {
            int l=i+1,r=len-1;
            while(l<r)
            {
                int t=nums[i]+nums[r]+nums[l];
                if(t==target)return t;
                if(abs(t-target)<abs(res-target))res=t;
                if(t>target)
                {
                    --r;
                    while(l<r&&nums[r]==nums[r+1])
                    --r;
                }
                else if(t<target)
                {
                    ++l;
                    while(l<r&&nums[l]==nums[l-1])++l;
                }
                while(i<len-2&&nums[i]==nums[i+1])++i;
            }
        }
        return res;
    }
};

//用两个队列实现栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 0; i + 1 < que.size(); i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        que.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
};

作者：sandychen
链接：https://leetcode-cn.com/problems/implement-stack-using-queues/solution/yong-dui-lie-shi-xian-zhan-c-dan-dui-lie-ru-zhan-o/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//910. 最小差值 II
给定一个整数数组 A，对于每个整数 A[i]，我们可以选择 x = -K 或是 x = K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int N = A.size();
        int res = A[N - 1] - A[0];
        for (int i = 0; i < N - 1; ++i) {
            int mx = max(A[N - 1], A[i] + 2 * K);
            int mn = min(A[0] + 2 * K, A[i + 1]);
            res = min(res, mx - mn);
        }
        return res;
    }
};

作者：da-li-wang
链接：https://leetcode-cn.com/problems/smallest-range-ii/solution/c-jian-dan-ti-jie-by-da-li-wang-30/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//翻转列表
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* node = head;
        ListNode* p = NULL;
        ListNode* q = NULL;
        while(node != NULL)
        {
            q = node->next;  //保存下一个节点
            node->next = p;  //将前一个节点赋给当前节点的下一个
            p = node;        //当前节点赋值给p指针
            node = q;        //下一个节点赋值给node指针
        }
        return p;
    }
};

/*
11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max1=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
                int b=(j-i)*(min(height[i],height[j]));
                max1=max(max1,b);
                if(height[i]<height[j])//移动的条件就是谁小谁动。
                i++;
                else
                j--;
        }
        return max1;
    }
};