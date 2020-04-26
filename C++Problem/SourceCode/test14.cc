#include <queue>
#include <string.h>
#include <iostream>
#include <stack>


using namespace std;

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

            string oper1;
            cin >>oper1;
            const char* oper = oper1.c_str();


            if(strcmp( oper ,"poll") == 0 ){
                Pop();
            }else if( strcmp( oper, "peek") == 0){
                Peek;
            }else {
                    int temp = oper[5] -'0';
                    Push(temp);
            }

            Q--;
        }
    system("pause");
    return 0 ;
}