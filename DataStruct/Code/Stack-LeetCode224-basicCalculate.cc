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
    stack<char> opors;

    int i = start;

    while( i < end){

        if( s[i] == '('){

            opors.push( s[i]);
            ++i;
        }else if( s[i] == '+' || s[i]=='-' || s[i] == ')'){

            while( opors.size() && ( opors.top() == '+'|| opors.top() == '-')){
                
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

            while( i < end && isdigit(s[i])){
                result = 10 * result +(s[i++] -'0');
            }

            oprands.push( result );
        }

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
            }else if( op == '-'){
                oprands.push( a-b );
            }

        }

    return oprands.top();
}
int cacultate( string s){

    string t;
     for(int i=0;i<s.size() ;i++){

         if( s[i] != ' '){
             t += s[i];//用于取出空格；
         }
     }

     return Core( t, 0 ,t.size());
}

//方法二：采用单栈法,代码存在问题

/*
只有+和-，可以将-与后面的数字合在一起考虑，引入数字的符号。这样整个表达式都是加法。

而且+和-都是从左向右结合的。这样的随着表达式从左向右推进，每遇到+和-，就将刚取出的整数，与前面的值累加。

例如：”2-1+2″

假设现在遍历到1的位置。此时左边已算出的值:left = 2。当前的数字：next_integer = 1，其符号是 next_sign = -1。

往右推进到+，此时将next_sign * next_integer 加到 left 上。

left = left + next_sign * next_integer = 2 -1 =1。

然后，+号，下一个数字的符号是正，next_sign = 1。

继续往右推进，直到结束。只要表达式中没有括号，就可以用这样的方式进行，并能得出正确的值。

唯一难处理的是括号。

这是引入栈。

当遇到'(‘时，要先算括号中的表达式，可将左边已经算出的值left和当前数字符号next_sign入栈。

当遇到’)’时，括号中的表达式结束了。要将括号内的表达式的值，先求出。其符号和括号前的值，都在栈中。只要将它们取出，算出新的值。

例如：”1-(2-3)+6″

当遍历到'(‘时，left=1,next_sign = -1。入栈S=[1,-1]。

当遇到’)’时，括号内的值为-1。

此时，要与之前的值整合。

出栈。

之前的值是1。

括号内的值的符号是-1。

整合值为1+(-1 * -1) = 2。

left = 0: 已算出的值;
next_sign = 1: 下一部分的符号;
next_integer = 0: 下一部分的值;
S：栈;
for (i in s){
    if(s[i] 是 '(') left入栈S; next_sign入栈S;
    if(s[i] 是 ')') 合计出括号内的值；扩号前的值和括号值的符号出栈S，整合成新值;
    if(s[i] 是 '+' 或 '-') 合计出符号前的值;更新next_sign；
    if(s[i] 是 数字) 取整数;
}

作者：jason-2
链接：https://leetcode-cn.com/problems/basic-calculator/solution/si-chong-jie-fa-by-jason-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

作者：jason-2
链接：https://leetcode-cn.com/problems/basic-calculator/solution/si-chong-jie-fa-by-jason-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/


int Caculate( string & s){

    stack<int> s1;
    int left = 0 ;
    int next_sign = 1;
    int next_integer = 0 ;
    int i =0 ;

    while (i < s.size())
    {
        
        if( s[i] == '('){
            s1.push(left);
            s1.push(next_sign);

            next_sign = 1;
            left = 0;
            next_integer = 0;

        }else if( s[i] == ')'){

            left = left + next_sign * next_integer;

            int  my_sign = s1.top() ;
            s1.pop();

            int prev_left = s1.top() ;s1.pop();

            left = prev_left+ my_sign* left;

            next_sign = 1;

            next_integer = 0 ;

        }else if( s[i] == '+' || s[i] == '-'){

            left = left + next_sign* next_integer;
            next_sign = s[i] == '+' ? 1 :-1;
            next_integer = 0 ;

        }else{

            while( i < s.size() && isdigit(s[i])){

                next_integer = 10* next_integer + ( s[i++] - '0' );

            }

            --i;
        }

        ++i;
    }

    return left + next_sign* next_integer ;
    
}

int Core1( string s){
    string t;
     for(int i=0;i<s.size() ;i++){

         if( s[i] != ' '){
             t += s[i];//用于取出空格；
         }
     }

     return Caculate(t);;
}

int main( int argc ,char* argv[]){

    string s= "(1+3)-4+(4-8)";
    int result  = cacultate(s);

    cout<<" result " << result << endl;

    int result2= Core1(s);

    cout <<"result2 " <<result2<<endl;

    system("pause");
    return 0;

}