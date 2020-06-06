#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include <unordered_map>

using namespace std;

/*
291. 单词规律 II
给你一种规律 pattern 和一个字符串 str，请你判断 str 是否遵循其相同的规律。

这里我们指的是 完全遵循，例如 pattern 里的每个字母和字符串 str 中每个 非空 单词之间，存在着双向连接的对应规律。

 

示例1:

输入: pattern = "abab", str = "redblueredblue"
输出: true
示例2:

输入: pattern = "aaaa", str = "asdasdasdasd"
输出: true
示例2:

输入: pattern = "aabb", str = "xyzabcxzyabc"
输出: false
 

提示：

你可以默认 pattern 和 str 都只会包含小写字母。

*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char ,string> m ;
       
        return Core( pattern ,str, 0, 0, m);
    }

    bool  Core( string pattern ,string str , int p ,int r ,unordered_map<char,string>& m){
        //终止条件；
        if( p == pattern.size() && r == str.size()){
            return true;
        }

        if( p == pattern.size() || r == str.size()){
            return false;
        }


        //提出pattern中的值作为键值；
        char key = pattern[p];

        //从r开始遍历输入字符串str;
        for(int i = r ;i < str.size() ; i++){

            string value = str.substr(r,i-r+1);
            // 如果哈希表中存在key值且映射值一样,则递归自身,结果为真的话返回true
            if( m.count(key) && m[key] == value){

                if( Core( pattern,str,p+1,i+1,m)){
                    return true;
                }
            }else if( !m.count(key)){
            //如果哈希表中不存在对应的key值，需药判断是否重复映射值；

                bool flag = false;

                for( auto it :m){

                    if( it.second == value){
                        flag = true;
                        break;
                    }
                }
                // 哈希表中不存在该映射值的话则新增该映射值并递归

                if( !flag){
                    m[key] == value;
                    if( Core( pattern, str, p+1, i+1, m)){
                        return true;
                    }
                    m.erase(key);
                }
            } 
            return false;

        }
    }
};

//方法二：
class Solution {
public:
unordered_map<string, bool>m;
    bool wordPatternMatch(string pattern, string str) 
{
	vector<string> hash(26, "");

	return SolveWordPatternMatch(pattern, str, 0, 0, hash);

}
bool SolveWordPatternMatch(string& pattern, string& str, int i, int j,vector<string>&hash)
//i和j是pattern和str起点。hash是匹配表
{
	//终止条件

	//str还没匹配完
	if (i == pattern.size() && j != str.size())
	{
		return false;
	}
	//pattern还没完
	if (i != pattern.size() && j == str.size())
	{
		return false;
	}
	//完美匹配
	if (i == pattern.size() && j == str.size())
	{
		return true;
	}
	//如果pattern[i]在表内，直接判断接下来str是否满足
	//	如果满足，进入下一层
	//如果pattern[i]不在表内
	//循环建立匹配表，进入下一层

	//在表内
	if (hash[pattern[i] - 'a'].size()>0)
	{
		for (int i1 = 0; i1 < hash[pattern[i] - 'a'].size(); i1++)
		{
			if (j + i1 >= str.size()||hash[pattern[i] - 'a'][i1] != str[j + i1])
			{
				return false;
			}
		}
		return SolveWordPatternMatch(pattern, str, i + 1, j + hash[pattern[i] - 'a'].size(), hash);
	}
	//不在表内
	else
	{
        if (str.size() - j < pattern.size() - i)
		{
			return false;
		}
		//i1为长度
		for (int i1 = 1; i1 <= str.size()-j+i+1-pattern.size(); i1++)
		{
			string p = str.substr(j, i1);
			//需要判断p是否与表内其它匹配字符串重叠
			if (m[p])
				//已存在
			{
				continue;
			}
			else
			{
				m[p] = true;
			}
			hash[pattern[i] - 'a'] = p;
			bool res=SolveWordPatternMatch(pattern, str, i + 1, j + i1, hash);
			if (res)
			{
				return res;
			}
			hash[pattern[i] - 'a'] = "";
			m[p] = false;
		}
	}

	return false;

}
};