#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param pattern string字符串 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool testMatch(string pattern, string str) {

        vector<string> words;

        string s;

        for(int i = 0 ;i < str.size() ;i ++){
            if( str[i] == ' '){
                if(s.size()){
                    words.push_back(s);
                }
                s="";
            }else{
                s +=str[i];
            }
        }

        if(s.size()){
            words.push_back(s);
        }

        if(words.size() != pattern.size()){
            return false;
        }

        for( int i = 0 ;i < pattern.size() ;i++){
            for(int j = i+1; j<pattern.length() ;j++){
                if(((pattern[i] == pattern[j]) && (words[i]!= words[j]))||((pattern[i] != pattern[j]) && (words[i] ==  words[j]))){
                    return false;
                }
            }
        }
        return false;
    }
};

//方法二：
class Solution {
public:
    /**
     * 
     * @param pattern string字符串 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool testMatch(string pattern, string str) {

        vector<string> vtr;
        int t =-1 ;
        for(int i = 1 ;i < str.size() ;i++){
            if( str[i] == ' '){
                t = t+1;
                vtr.push_back(str.substr(t,i-t));
                t = i;
            }
        }

        vtr.push_back( str.substr(t+1,str.size()-1));
        int n = pattern.size();
        int m = vtr.size();

        if( m!= n ){
            return false;
        }

        map<char ,int > map1;
        map<string ,int > map2;


        for(int i = 0 ;i < n  ;i++){
            if(!map1[pattern[i]]){
                map1[pattern[i]] = i+1;
            }
        }

        for(int i =0 ;i < m ;i++){
            if( !map2[vtr[i]]){
                map2[vtr[i]] = i+1;
            }
        }
        for( int i =0 ;i <n ;i++){
            if(map1[pattern[i]]!= map2[vtr[i]]){
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    /**
     * 
     * @param pattern string字符串 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool testMatch(string pattern, string str) {

        unordered_map<char,string> map1;

        istringstream in(str);
        int i =0 ;
        int n = pattern.size();

        for( string word; in>>word ;++i){
            if(i >= n ){
                return false;
            }

            if( map1.count(pattern[i])){
                if(map1[pattern[i]]  != word){
                    return false;
                }
            }else{
                for( auto a :map1 ){
                    return false;
                }
                map1[pattern[i]] = word;
            }

        }
        return i == n;
    }

};


class Solution {
public:
    /**
     * 
     * @param N int整型 
     * @return int整型
     */
    int findGreaterNum(int N) {
        // write code here

        vector<int> num;
        int temp = N;
        while( temp > 10){
            int temp1 = temp/10;
            int temp2 = temp%10;
            num.push_back(temp2);
            temp = temp1;
        }
        num.push_back(temp);
        reverse(num.begin(),num.end());

        if( next_permutation(num.begin(),num.end())){
            int res=0 ;
            for(int i =0 ;i < num.size() ;i++){
               res = res*10+num[i];
            }
            return res;
        }else{
            return -1;
        }
        return 0;
    }
};


#include <iostream>
#include <unordered_map>
#include <stirng>
#include <cstring>
#include <iomanip>

using namespace std;

void encode (unsigned int n){
    if( n < 128){
        if( n < 16 ){
            cout <<"0X0"<<hex<<n;
        }else{
            cout <<"0X"<<hex <<n ;
        }
        return;
    }

    while( n ){
        unsigned int temp ;
        if( n >= 128 ){
            temp = (0x80 | (n & 0x7F));
            cout <<"0X" << setiosflags(ios::uppercase)<<hex<<temp;
        }else{
            temp = (0X00 | (n & 0x7F));
            if( temp < 16 ){
                cout <<"0X0"<<hex<<temp;
            }else{
                cout <<"0X"<<hex<<temp;
            }
        }
        n >>=7;
    }
    return ;
}

void decode (string & x){
    unsigned int num,res=0;
    int cnt = 0 ;
    while(x.size()){
        string temp = x.substr(0,4);

        x= x.substr(4);
        temp = temp.substr(2);
        num = 0;
        for(int i= 0 ; i< temp.size() ; i++){
            if(temp[i] >='0' && temp[i] <= '9'){
                num = num*16 +temp[i]-'0';
            }

            if( temp[i] >='A' && temp[i] <= 'F'){
                num = num*26 +temp[i] -'A'+10;
            }
        }

        unsigned int value ;
        value = (num & 0X7F);
        for(int i = 1 ;i <= cnt; i++){
            value <<= 7 ;
        }
        res += value;
        cnt++;
    }
    return res;
}

int main( int argc, char*argv[]){
    int n ;
    string x;
    cin>> n ;
    cin >>x ;
    encode(n);
    cout <<endl;
    cout <<dec <<decode(x) << endl;
    return 0 ;
}