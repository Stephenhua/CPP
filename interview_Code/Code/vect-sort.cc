#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;

/*
实现原理：
给出n个只包含小写字母'a'~'z'的字符串，我们称一个字符串s_i为原根，当且仅当给出的其他任何字符串都不是它的前缀。

现在牛牛想知道给出的字符串中有多少个原根。
（相同字符串互为前缀）
*/
static bool cmp(string a, string b) { //定义比较规则时static很重要，否则可能报错

        return a.size() < b.size();
} 

void PrintMinNumber(vector<string> numbers) {

        sort(numbers.begin(), numbers.end(), cmp);

        for (auto n : numbers) {
            cout << n <<endl; 
        }

};

bool judge(const string &a,const string &b)
{
    int i,j;
    if(a.length()<b.length())
        return false;
    for(i=0;i<a.length();i++){

        for(j=0;j<b.length();j++){

            if(a[i+j]!=b[j])
                break;   // 字符不相等，退出
        }

        if(j==b.length()) // 达到了b.length,说明字符全部相等
            return true;
    }
    return false;
}

bool judge(string &a, string &b)
{
    int i,j;
    if(a.length()<b.length())return false;
    for(i=0;i<a.length();i++){
        for(j=0;j<b.length();j++){
            if(a[i+j]!=b[j])
                break;   // 字符不相等，退出
        }
        if(j==b.length()) // 达到了b.length,说明字符全部相等
            return true;
    }
    return false;
}

int solve(vector<string>& s) {

    int size = s.size();
    if( size == 0){
        return 0;
    }

    if( size == 1){
        return 1;
    }

    int rs = 0 ;

    sort( s.begin() ,s.end() ,cmp);

    PrintMinNumber(s);

    vector<string> rest;

    for(int i =0 ; i< size; i++){

        string temp = s[i];
        
        if( rest.empty() ){
            rest.push_back(temp);
            rs++;

        }else{

            string s1;

            int num = 0;

            for( int i=0 ;i<temp.size() ;i++){

                s1 += temp[i];

                 int num1 = 0;

                for( int j = 0 ; j <rest.size() ; j++){

                    if( !judge( s1, rest[j] )){
                        num1++;
                    }
                }

                //每次循环都要进行遍历，从而导致这些数发生了变化；

                if( num1 == rest.size()){

                    num =rest.size();
                }
            }

            if( num == rest.size()){

                rest.push_back(temp);

                rs++;

            }

        }


    }
    return rs;

}

int main( int  argc, char* argv[]){

    vector<string> rs = {"abc","adsfb","a","ba","cd","ef","fsg"};
    int res = solve(rs );
    cout <<res <<endl;

    system("pause");
    return 0 ;
}


