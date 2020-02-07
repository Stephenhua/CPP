#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         //特殊情况直接排除
        if(s.empty()||words.empty())return {};
        
        //存放结果的数组
        vector<int> result;
        
        //单词数组中的单词的大小，个数，以及总长度
        int one_word=words[0].size();
        int word_num=words.size();
        int all_len=one_word*word_num;
        
        //建立单词->单词个数的映射
        unordered_map<string,int> m1;
        for(const auto& w:words)m1[w]++;
        
        for(int i=0;i<one_word;++i)
        {
            //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            int left=i,right=i,count=0;
            
            unordered_map<string,int>m2;
            
            //开始滑动窗口
            while(right+one_word<=s.size())
            {
                //从s中提取一个单词拷贝到w
                string w=s.substr(right,one_word);
                right+=one_word;//窗口右边界右移一个单词的长度
                
                if(m1.count(w)==0){//此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                    count=0;
                    left=right;
                    m2.clear();
                }
                else{//该单词匹配成功，添加到m2中
                    m2[w]++;
                    count++;    
                    while(m2.at(w)>m1.at(w))//一个单词匹配多次，需要缩小窗口，也就是left右移
                    {
                        string t_w=s.substr(left,one_word);
                        count--;
                        m2[t_w]--;
                        left+=one_word;
                    }
                    if(count==word_num)result.push_back(left);
                }
            }
        }
        return result;
        
    }
};

//解法二：采用窗口法进行遍历字符串

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.size() == 0)//判断words为空,因为下面用到了words[0]
            return ret;
        
        int word_size = words[0].size();
        int word_num = words.size();
        
        unordered_map<string,int> m1;//构造hashmap
        for(int i=0;i<word_num;i++)
            m1[words[i]]++;
        
        unordered_map<string , int >m2;
        for(int i=0;(i+word_num*word_size)<=s.size();i++){
            //int j=0;
            for(int j=i;j<(i+word_num*word_size);j=j+word_size){

                string temp_str= s.substr(j,word_size);
                if(m1[temp_str]==0){//没有截取字符，则跳出
                    break;
                }else{
                    m2[temp_str]++;
                    if(m1[temp_str]<m2[temp_str]){//如果超出的话，依旧跳出去
                        break;
                    }
                }
            }
            if(j==(i+word_num*word_size)){
                ret.push_back(i);
            }
            m2.clear();
        }
        return ret;
    }
};

//方法三：采用新的方式，进行了剪枝操作等。
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        if(words.empty()){
            return {};
        }

        unordered_map<string ,int> wordmap ,smap;
        for(string word:words){
            wordmap[word]++;
        }

        int wordlen=words[0].size();
        int wordnum=words.size();

        vector<int >reslut;
        for(int k=0;k<wordlen;k++){
            int i=k,j=k;
            while(i<s.size()-wordlen*wordmap){
                while(j<i+wordlen*wordmap){
                    string temp_str= s.substr(j,wordlen);
                    smap[temp_str]++;
                    j+=wordlen;
                    if(wordmap[temp_str]==0){//word中不存在的单词
                        i=j;
                        smap.clear();                        
                        break;
                    }else if(smap[temp]>wordmap[temp]){
                        while(smap[temp]>wordmap[temp]){
                            smap[s.substr(i,wordlen)]--;
                            i+=wordlen;//对i进行加速；
                        }
                        break;
                    }
                }
                if(j==i+wordlen*wordmap){
                    reslut.push_back(i);
                    smap[s.substr(i,wordlen)]--;
                    i+=wordlen;
                }
            }
            smap.clear();
        }
        return ans;
    }
};