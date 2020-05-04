#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;


//方法一：双栈法，一个栈用于存储运算符，一个栈用于存储数字；
/*
碰到'(‘，'(‘入opors栈。

碰到’)’，opors栈中栈顶到'(‘的运算符都要计算出来。 这表示括号内的表达式结束了。然后， ‘(‘ 出栈。

碰到’+”-‘， opors栈中栈顶到'(‘的运算符都要计算出来。 这是左结合性导致的。然后 ‘+”-‘ 入栈。

碰到数字，提取出整数，然后入opands栈。


怎么按opors计算数值呢
opors计算逻辑：
while(opors不为空 且 opors栈顶是'+'或'-'){
    b = opands出栈;
    a = opands出栈;
    op = opors出栈;
    r = a op b;
    r入opands栈;
}

完整思路：
for(i in s){
    if(s[i]是'(') '('入栈opors;
    if(s[i]是')') 执行opors计算逻辑; '('出栈;
    if(s[i]是'+'或'-') 执行opors计算逻辑; '+'或'-'入栈;
    if(s[i]是数字) 提取整数,入栈opands;
}
执行opors计算逻辑;
*/

int  Core( const string &s, int start ,int end ){

    stack<int> oprands;
    stack<int> opors;

    int i = start;

    while( i < end){

        if( s[i] == '('){

            opors.push( s[i]);
            ++i;
        }else if( s[i] == '+' || s[i]=='-' || s[i] == ')'){

            while( opors.size() && ( s[i] == '+'|| s[i] == '-')){
                
                int b = oprands.top();
                oprands.pop();

                int a = oprands.top() ;
                oprands.pop();

                char op = opors.top();
                opors.pop();

                if( op == '+'){
                    oprands.push( a+b);
                }else if( op == '-'){
                    oprands.push( a- b);
                }
            }

            if( s[i] == ')'){
                if(opors.size() && opors.top()=='('){
                    opors.pop();
                }else{
                    opors.push(s[i]);
                }
            }

            ++i ;

        }else{//都是数据的情况；

            int result = 0;

            while( i < y && isdigit(s[i])){
                result = 10 * result +(s[i++] -'0');
            }

            oprands.push( result );
        }

        while( opors.size()){

            int b = oprands.top();
            oprands.pop();

            int a = oprands.top();
            oprands.pop();

            char op = opors.top();
            opors.pop();

            if( op == '+'){
                oprands.push( a+b);
            }else if( op == '+'){
                oprands.push( a-b );
            }

        }
    }

    return oprands.top();
}
int cacultate( string s){

    string t;
     for(int i=0;i<s.size() ;i++){

         if( s[i] != ' '){
             t += x;//用于取出空格；
         }
     }

     return Core( t, 0 ,t.size());
}

