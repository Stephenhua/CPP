#include <stdio.h>
#include <iostream>
#include <stack>
#include  <queue>
using namespace std;


//将两个队列合成一个栈
template <typename T> class CStack
{
    public:
    CStack(void);
    ~CStack(void);

    //在顶端插入结点；
    void push1(const T&node);
    //在顶端删除结点；
    T pop1();
    private:
    queue<T> queue1;
    queue<T> queue2;
};
template<typename T> CStack<T>::CStack(void){

}
template<typename T> CStack<T>::~CStack(void){

}

template<typename T> void CStack<T>::push1(const T &node){
    
    if(queue1.empty()&& queue2.empty()){
        queue1.push(node);
    }
    if(queue1.empty()){
        queue2.push(node);
    }else{
        queue1.push(node);
    }
}

template<typename T> T CStack<T>::pop1(){

    if(queue1.empty()){
        if(queue2.empty()){
            T result;
            return result;
            
            cout<<"stack is empty"<<endl;
        }
        else{
            if(queue2.size()==1){
                T result= queue2.front();
                queue2.pop();
                return result;
            }else{
                while(queue2.size()!=1){
                    queue1.push(queue2.front());
                    queue2.pop();
                }
                T result= queue2.front();
                queue2.pop();
                return result;
            }
        }
    }else{
        if(queue1.size()==1){
            T result =queue1.front();
            queue1.pop();
            return result;
        }else{
            while(queue1.size()!=1){
                queue2.push(queue1.front());
                queue1.pop();
            }
            T result =queue1.front();
            queue1.pop();
            return result;
        }
    }
}
