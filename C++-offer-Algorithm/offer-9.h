#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;


//将两个栈合成一个队列
template <typename T> class CQueue
{
    public:
    CQueue(void);
    ~CQueue(void);

    //在队列末尾添加一个结点；
    void appendTail(const T&node);
    //删除结点
    T DeleteHead();
    private:
    stack<T> stack1;
    stack<T> stack2;
};
template<typename T> CQueue<T>::CQueue(void){

}
template<typename T> CQueue<T>::~CQueue(void){

}

template<typename T> void CQueue<T>::appendTail(const T &node){
    stack1.push(node);
}

template<typename T> T CQueue<T>::DeleteHead(){
    if(stack2.size()<=0){
        while(stack1.size()>0){
            T& data=stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0){
        cout<<"Queue is empty"<<endl;
    }

    T head=stack2.top();
    stack2.pop();
    return head;
}