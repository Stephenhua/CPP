 #include <iostream>
#include <vector>
#include <string.h>
#include <stack>
 typedef long long ll;
using namespace std;

ll doneq(const string & s){
        stack<ll> S;
        ll left = 0;
        ll next_sign = 1;
        ll next_integer = 0;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                S.push(left);
                S.push(next_sign);
                next_sign = 1;
                next_integer = 0;
                left = 0;
            }else if(s[i] == ')'){
                left = left + next_sign * next_integer;
                ll my_sign = S.top();S.pop();
                ll prev_left = S.top();S.pop();
                left = prev_left + my_sign * left;
                next_sign = 1;
                next_integer = 0;
            }else if(s[i] == '+' || s[i] == '-'){
                left = left + next_sign * next_integer;
                next_sign = s[i] == '+' ? 1 : -1;
                next_integer = 0;
            }else{
                while(i < s.size() && isdigit(s[i])){
                    next_integer = 10* next_integer + (s[i++] - '0');
                }
                --i;
            }
            ++i;
        }
        
        return left + next_sign * next_integer;
}

ll calculate(string s) {
        string t;
        for(auto x : s){
            if(x!=' '){
                t+=x;
            }
        }
        return doneq(t);
}


int main( int argc ,char* argv[]){

    string s= "(1+3)-4+(4-8)";
    int result  = calculate(s);

    cout <<"result " <<result<<endl;

    system("pause");
    return 0;

}