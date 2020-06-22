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
925. 长按键入
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
示例 3：

输入：name = "leelee", typed = "lleeelee"
输出：true
示例 4：

输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。
 

提示：

name.length <= 1000
typed.length <= 1000
name 和 typed 的字符都是小写字母。


*/

/*
主要思路：
慢指针i指向name，快指针j指向typed，如果name[i]等于typed[j]，则两个指针都后移一位；如果发现两者不等，慢指针i不动，快指针j后移一位。

特殊情况判断：
1.如果name[0]不等于typed[0]，说明一定false了。原因显然。
2.在name[i]不等于typed[j]的情况下，如果当前的typed[j]不等于i指针前一次指的字母，说明一定false了。
    原因：既然已经出现了不等的情况，那么只有当前一个字母被重复键入，才能true，如果发现typed[j]不是前一个字母的重复键入显然false。
    name中的一个字符对应typd中的多个字符；
3.名字没输完。如果最后比对结束了，i指针都还没有移到name的最后，说明name的末尾没有被type完，直接判false。
4.最后输入多余字符。type完name的最后一个字母后，只允许重复输入name的最后一个字母，
    如果再往下检查剩下的typed发现里面有字母和name的最后一个字母不同，则显然false。

上述四种情况都不满足，则可以判定为true。

作者：luo-zhang-hui-xian
链接：https://leetcode-cn.com/problems/long-pressed-name/solution/chang-jian-an-ru-shuang-zhi-zhen-fang-fa-zhi-xing-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int size = name.size();
        int size2 = typed.size();
        int start = 0;
        int start2 = 0 ;
        if(name[start] != typed[start2]){
            return false;
        }

        while( start < size && start2 < size2){

            if( name[start] == typed[start2]){
                start++;
                start2++;
            }else if( name[start-1] != typed[start2]){
                return false;
            }else{
                start2++;
            }
        }

        if( start != size){
            return false;
        }
        start--;
        start2--;
        while( start2 < size2){
            if( typed[start2] != name[start]){
                return false;
            }
            start2++;
        }
        return true;
    }
};


//方法二：直接比较type中的字符大于等于name中的个数，

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        //判断当前name的空间大小；

        if(name.size()==0&&typed.size()==0)  return true;
        if(name.size()==0||typed.size()==0)  return false;
        //确定当前的下标号；

        int index1=0,index2=0;
        while(index1<name.size()&&index2<typed.size())
        {
            //循环时候
            char c1=name[index1],c2=typed[index2];
            int count1=0,count2=0;
            //判断字符是否相等；不相等直接返回false；
            if(c1!=c2)  return false;
            while(index1<name.size()&&name[index1]==c1)
            {
                ++index1;
                ++count1;
            }
            while(index2<typed.size()&&typed[index2]==c2)
            {
                ++index2;
                ++count2;
            }
            //用于实现count2 《 count1 ，表明输入的字符少于name 的字符；
            if(count2<count1)  return false;
        }
        if(index1!=name.size()||index2!=typed.size())
            return false;
        return true;
    }
};