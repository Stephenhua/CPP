#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int longestValidParenthe(string s) {
	int size = s.length();
    vector<int> dp(size,0);

    int res = 0 ;
    for(int  i = 1 ; i < size ;i++){
        if( s[i] == ')'){
            if(s[i-1] == '('){
                dp[i] = 2 ;
                if( i - 2 >= 0 ){
                    dp[i] = dp[i] + dp[i-2];
                }
            }else if( dp[i-1] > 0 ){
                if( ( i - dp[i-1] -1) >= 0 && s[i-dp[i-1] -1 ] == '(' ){
                    dp[i] = dp[i-1] +2;
                    if( (i - dp[i-1] -2) >= 0){
                        dp[i] = dp[i] +dp[i-dp[i-1]-2];
                    }
                }
            
            }
        }
        res = max(res , dp[i]);
    }
    return res;    

}
/******************************结束写代码******************************/


int main() {
    int res;

    string _s;
    getline(cin, _s);
    
    res = longestValidParenthe(_s);
    cout << res << endl;
    
    return 0;

}


vector < int > findNumber(int num) {

    vector<int> res;
    int num01 = 0 ;
    int num11 = 0;

    int num1 = 0;
    int num0 = 0 ;
    int temp1 =x ;
    int temp2 = x;

    while(( temp1 & 1 )==0 &&( temp1 != 0)){
        num01++;
        temp1 >>= 1;
    }

    while( ( temp1 & 1 ) == 1){
        num11++;
        temp1 >>=  1;
    }

    while( ( temp2 & 1) == 1 ){
        num1++;
        temp2 >>=1;
    }

    while( (( temp2 & 1) == 0 ) && ( temp2 != 0) ){
        num0++;
        temp2 >>=1;
    }

    res.push_back( (x -   (1 << ( num1 ) ) - (1 << (num0-1)) +1) );
    res.push_back(  ( x + (1 << (num11 -1 )) + (1 << num01) - 1 ));
    return res;

}


vector < int > findNumber(int num) {

    int  a = 0, b = 0 ,i = 0 ;
    vector<int> res({-1.-1});
    int tmep = num ;
    while( !( temp & 1 )){
        ++a;
        ++i ;
        temp = temp >> 1;
    }

    int sum = 0 ;
    while( temp&1 && temp &2 ){
        sum +=(1<<i);
        temp = temp>>1;
        ++i;
    }

    if( i < 30 ){
        res[0] = num += ( 1 << i );
    }

    if( a ){
        res[0] -= (( 1 << a)-1)*sum/(1<<a);
    }

    temp = num ,i = 0 ,sum = 0;

    while( (temp & 1)){
        sum += (1 << i);
        temp = temp>>1;
        if( ++i >= 31 ){
            return res;
        }
    }

    while( !(temp  & 1 )&& !(temp &2)){
        ++b;
        temp = temp >> 1;
        if( ++i >= 31){
            return res;
        }
    }

    res[1] = num - (1<<i);
    if(b){
        res[1] += sum*((1<<b)-1);
    }
    return res;


}