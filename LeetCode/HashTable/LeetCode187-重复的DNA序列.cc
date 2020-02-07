
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

  vector<string> 
    std::vector<std::string> ret;
    std::unordered_map<std::string, int> sequences;
    for (int i = 0; i + 9 < s.size(); ++i) {
      if (2 == ++sequences[std::string(s.begin() + i, s.begin() + i + 10)]) {
        ret.emplace_back(s.begin() + i, s.begin() + i + 10);
      }
    }
    return ret;
  }

//方法一：时间复杂度O(n)，空间复杂度o(n)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {     
        int s_length=s.size();
        vector<string> result;
        unordered_map<string ,int> temp_result;

        for(int i=0;i<s_length-9;++i){
            if(++temp_result[string(s.begin()+i,s.begin()+i+10)]==2){
                result.emplace_back(s.begin()+i,s.begin()+i+10);
            }
        }
        return result;

        
    }
};

//方法二：采用字符串的形式进行

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {     
        unordered_set<string >  res;
        unordered_set<string>  st;
        int cur=0;
        for(int j=0;i<9;i++){
            //十个字符分别向左移动3位，然后分别
            cur=cur<<3|(s[i]&7);
        }
        for(int i=9;i<s.size();i++){
            cur=((cur&0x7fffffff)<<3)|(s[i]&7);
            if(st.count(cur)){
                res.insert(s.substr(i-9,10));
            }else{
                st.insert(cur);
            }
            
        }
        return vector<string>(res.begin(), res.end());
 
    }

};