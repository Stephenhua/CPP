#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

int caculateCore( string & t){

    stack<int> num ;
    stack<char> z;
    int value = 0;

    for(int i =0 ;i< t.size() ;i++){

        if(isdigit(t[i])){//获取数字；
            value = value*10 + (t[i]-'0');
                continue;
        }

        // 判断符号栈是不是为空，以及是否为乘法或除法；
        if( !z.empty() && (z.top() == '*' || z.top() == '/')){
            //处理上一次的*/;
            value = (z.top() == '*') ? num.top() * value : num.top() /value;

            num.pop();
            z.pop();
        }

        //处理当前状态的值；
        if( z.empty() || t[i]== '*' || t[i] == '/' ){
            num.push(value);
            z.push( t[i]);
        }else{

			// 如果本次不是 */ ，可以把上一次的 +- 处理了
            num.top() += (z.top() == '+') ?(value):(-value);
            z.top() = t[i];
        }
        value =0 ;   
            
    }
    return num.top();

}
int calculate( string s){

    string t;
    for(int i=0;i <s.size() ;i++){

        if( s[i] != ' '){
            t +=s[i];
        }
    }
    t.append("+");

    return caculateCore( t);
}

//方法二：
    int calculate(string s) {
        int res = 0, num = 0, left = 0;
        char c, sign = '+';
        for(int i = 0; i < s.size(); ++i) {
            c = s[i];
            if (c <= '9' && c >= '0') {
                num = num * 10 + (c - '0');
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i + 1 == s.size()) {
                switch(sign) {
                    case '+':
                        left += num; break;
                    case '-':
                        left -= num; break;
                    case '*':
                        left *= num; break;
                    case '/':
                        left /= num; break;
                }
                if (c == '+' || c == '-' || i + 1 == s.size()) {
                    res += left;
                    left = 0;
                }
                num = 0;
                sign = c;
            }
        }
        return res;
    }

int main( int argc ,char* argv[] ){
    
    string s ="1-1+1";
    string s2= " 2*4*5";
    int result = calculate( s);

    cout << "result" <<result<<endl;


    int result2 = calculate(s2);
    
    cout <<" result2" << result2 <<endl;


    system("pause");

    return 0 ;
}