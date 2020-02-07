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
滑动窗口算法的思路是这样：

1、我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引闭区间 [left, right] 称为一个「窗口」。

2、我们先不断地增加 right 指针扩大窗口 [left, right]，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。

3、此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right]，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。

4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。

这个思路其实也不难，第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动。


*/

//上述的伪代码是：
string s,t;
int left=0,right=0;
string res=s;

while(right<res.size()){
    windows.add[res[rignt]];
    right++;

    while(window 符合要求){
        //如果窗口的字串更短，则更新res;
        res=minLen(res,windows);
        windows.remove(s[left]);
        left++;
    }
}
return res;

/*
现在就剩下一个比较棘手的问题：如何判断 window 即子串 s[left...right] 是否符合要求，是否包含 t 的所有字符呢？

可以用两个哈希表当作计数器解决。用一个哈希表 needs 记录字符串 t 中包含的字符及出现次数，用另一个哈希表 window 记录当前「窗口」中包含的字符及出现的次数，如果 window 包含所有 needs 中的键，且这些键对应的值都大于等于 needs 中的值，那么就可以知道当前「窗口」符合要求了，可以开始移动 left 指针了。
*/


//最小覆盖子串
string minWindow(string s, string t) {

    int start=0,min_Len=INT_MAX;
    int left= 0,right =0;

    unordered_map<char ,int > windows;
    unordered_map<char ,int > needs;
    for(auto c:s){
        needs[c]++;
    }
    // 记录 window 中已经有多少字符符合要求了
    int match=0;

    while(right<s.size()){
        char c1=s[right];
        if(needs.count(c1)){
            windows[c1]++;
            // 字符 c1 的出现次数符合要求了
            if(windows[c1]==needs[c1]){
                match++;
            }
        }
        right++;
        while(match==needs.size()){
            if(right-left<min_Len){
                start =left;
                min_Len=right-left;
            }
            char c2=s[right];
            if(needs.count(c2)){
                windows[c2]--;
                if(windows[c2]<needs[c2]){
                    match--;
                }
                
            }
            left++;

        }
    }
    return min_Len==INT_MAX?" ":s.substr(start,min_Len);

}


//二、找到字符串中所有字母异位词

vector<int> findAnagrams(string s, string t) {
    vector<int > res;
    int left=0;
    int right=0;

    unordered_map<char ,int > needs ;
    unordered_map<char ,int > windows;

    for(auto c:t){
        needs[c]++;
    }
    int match=0;
    
    while(right<s.size()){
        char c1=s[right];
        if(needs.count(c1)){
            windows[c1]++;
            if(windows[c1]==needs[c1]){
                match++;
            }
        }
        //继续向右进行探寻；
        right++;

        //如果探寻的相匹配
        while(match==needs.size()){
            //缩小范围
            if(right-left==t.size()){
                res.push_back(left);
            }
            char c2=s[left];
            if(needs.count(c2)){
                windows[c2]--;
                if(windows[c2]<needs[c2]){
                    match--;
                }
            }
            left++;
        }
        
    }
    return res;
}


//方法三：无重复字符的最长字串
//我们要求的是最长子串，所以需要在每次移动 right 增大窗口时更新 res，而不是像之前的题目在移动 left 缩小窗口时更新 res。

int lengthOfLongestSubstring(string s) {
    int left=0;
    int right=0;
    unordered_map<char,int> windows;
    int res=0;
    while(right<s.size()){
        char c1=s[right];
        windows[c1]++;
        right++;
        while(windows[c1]>1){
            char c2= s[left];
            windows[c2]--;
            left++;
        }

        res=max(res,right-left);
    }

    return res;
}

//滑动窗口算法的抽象思想：

class MoveWindow{
    void movewindows(string s ){
        unordered_map<char ,int> temp_windows;
        int left=0;
        int right=0;
        while(right<s.size()){
            char c1=s[right];
            temp_windows[c1]++;
            while(vaild )//实时进行更新条件,只需要对其进行更新即可以实现；
            {
                temp_windows[c1]--;
                left++;
            }


        }
    }

};