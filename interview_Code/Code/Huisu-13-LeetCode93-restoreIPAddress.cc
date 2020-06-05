#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
93. 复原IP地址
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

/*
采用回溯的方法进行求解；
ips ====> 表示结果；
path -===> 表示当前变量；
s =======>表示出入的string；
begin ==== > 表示s的位数；
split ===== >表示总共应该分隔 4段；

*/

void Core( vector<string>& ips, vector<string>& path ,const string & s , int begin, int split){

    int length =  s.size();

    if( split == 0 && begin == length){

        ips.emplace_back<std::string>( {path[0] + '.' + path[1]+'.' + path[2] +'.' + path[3]});
        return;
    } 

    //对于0值，需要进行特别处理；

    if( s[begin] == '0'){

        if(( length - begin-1) > 3* split){
            return;
        }

        path.emplace_back<std::string>({"0"});
        Core( ips,path ,s , begin+1 ,split-1);
        path.pop_back();
        return;
    }

    for( int indx = begin ; indx <length && indx <begin+3;++indx){

        if(( length-indx -1) >(3*split)){
            continue;
        }

        auto&& substr = s.substr(begin, indx-begin+1);

        if(std::stod(substr) > 255){
                break;
        }

        path.emplace_back( substr);
        Core( ips,path,s,indx+1,split-1);
        path.pop_back();
    }

}
vector<string> restoreIpAddresses(string s) {

    //最终返回的结果；
    vector<string> ips;

    if(s.empty()){
        return ips ;
    }  

    vector<string> path;

    path.reserve(4);

    Core( ips, path,s,0,4);
    
    return ips;

}

// 方法二

bool isVaild( string ip){

    int val = stoi(ip);

    if( val >255) {
        return false;
    }

    if( ip.size() >= 2 && ip[0] == '0'){
        return false;
    }
    return true;

}
void Core( vector<string>& ips ,vector<string>& path, string& s, int begin){

  //首先判断剩余的位数，是不是还能满足要求，比如25525511135，若2.5.5.25511135显然不满足，这可以预判
    int maxLen = (4-path.size()) *3;
    if( s.size() - begin > maxLen){
        return;
    }
    // 结束条件：如果此时 begin 也刚好遍历完整个 s
    if( path.size() == 4 && begin ==  s.length()){
        
        string  res= "";
        for( int i =0 ;i <4 ;i++){
            res += path[i];
            if( i != 3){
                res += ".";
            }
        }
        ips.push_back( res);
        return;       
    }

    for( int i = begin ; i< s.size()&& i < begin+3 ;++i){

        string ip = s.substr( begin ,i-begin+1);
        
        if( !isVaild(ip)){
            continue;
        }
        
        path.push_back( ip);

        Core( ips, path, s, i + 1);

        path.pop_back();

    }
}
vector<string> restoreIpAddresses(string s) {

    //最终返回的结果；
    vector<string> ips;

    if(s.size() ==0  || s.size() < 4){
        return ips ;
    }  

    vector<string> path;

    Core( ips, path,s,0);
    
    return ips;

}