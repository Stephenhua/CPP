#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class MinStack{

    public:
        stack<int> StackValue;
        stack<int> StackMin;
        MinStack(){

        }

        void push(int n ){
            StackValue.push(n);
            if( StackMin.empty() || StackMin.top()  >= n ){
                StackMin.push(n);
            }
        }

        void pop(){
            if( StackMin.top() == StackValue.top() ){
                StackMin.pop();
            }
            StackValue.pop();
        }

        int top(){
            return StackValue.top();
        }

        int getMin(){
            return StackMin.top();
        }
};


int main(int argc, char* argv[] ){
    int n ;
    cin >> n ;
    MinStack mystack = new MinStack();
    while( n--){

            cout << mystack.top() <<endl;
            cout << mystack.getMin() << endl;

    }
    return 0 ;

}


int main(int argc, char* argv[] ){
    int n ;
    cin >> n ;
    MinStack mystack = new MinStack();
    while( n--){
        string temp ;
        cin >> temp;
        if( temp == "top"){
            cout << mystack.top() <<endl;
        }else if( temp == "getMin"){
            cout << mystack.getMin() << endl;
        }
    }
    return 0 ;

}



