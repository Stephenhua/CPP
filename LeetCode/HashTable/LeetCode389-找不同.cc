#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//首先第一反应的方法就是用哈希表来建立字符和个数之间的映射，如果在遍历t的时候某个映射值小于0了，那么返回该字符即可
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector <int> dic (26,0);   //char用-'a'转换为int, map换为vector
        for(int i=0; i<s.size(); i++)
            dic[s[i]-'a']+=1; 
        for(int i=0;i<t.size();i++){
            if(--dic[t[i]-'a']<0){
                return t[i];
            }
        }
        return 0;
        
    }
};


//方法二：采用异或的性质，相同返回0，这样相同的字符都相互抵消了，剩下的就是后的字符
class Solution {
public:
    char findTheDifference(string s, string t) {
         char res=0;
        for(auto c:s){
            res^=c;
        }

        for(auto c:t){
            res^=c;
        }
        return res;

    }

};

//方法三：可以直接用加和减，相同的字符一减一加也抵消了，剩下的就是后加的那个字符，参见代码如下：

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res -= c;
        for (char c : t) res += c;
        return res;
    }
};