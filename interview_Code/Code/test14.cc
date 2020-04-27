#include <queue>
#include <string.h>
#include <iostream>
#include <stack>


using namespace std;
/*
大体思路是两个栈分别扮演队列的队头和队尾，入队操作在队尾栈里，出队和检查队头在队头栈中，中途要维护队尾栈向队头栈的元素转移。
输入样例：
第一行是操作数N
之后有N行操作，有“add”，“peek”和“poll”三种操作
输出样例：
“peek”操作需输出队头元素

*/
stack<int> stack1;
stack<int> stack2;

void Push( int x){
    stack1.push(x);
}

void Pop(){
    if(stack2.size() <=0){
        while(stack1.size() > 0 ){

            int temp = stack1.top();
            stack2.push(temp);
            stack1.pop();

        }
    }
    stack2.pop();
}

int Peek(){
    if(stack2.size() <=0){
        while(stack1.size() > 0 ){

            int temp = stack1.top();
            stack2.push(temp);
            stack1.pop();

        }
    }
    int temp = stack2.top();
    return temp;

}
int main (){

        int Q ;
        cin >>Q ;

        while(Q>0){

            string oper;
            cin >>oper;


            if(oper =="poll" ){
                Pop();
            }else if( oper == "peek" ){
               int result =  Peek();
               cout <<result <<endl;
            }else {
                    int i ;
                    cin >> i;
                    Push(i);
            }

            Q--;
        }

    system("pause");
    return 0 ;
}