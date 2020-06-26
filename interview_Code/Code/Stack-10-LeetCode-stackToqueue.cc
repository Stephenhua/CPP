#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>
#include <stack>

using namespace std;

/*
232. 用栈实现队列
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
 

示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
 

说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
*/

/*
思路：
1）采用双栈的形式进行求解；
2）入队列时：直接压入到instack中；
3）出队列时，
        如果outStack为空，则把instaack中的数据弹出，压入到outstack,弹出最顶端的元素；
        如果outstak不为空，直接弹出栈顶，因为outstack直接弹出去就可以了。
*/

class MyQueue {

private:

stack<int> inStack;
stack<int> outStack;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        Check();
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        Check();
        return outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }

    void Check(){
        if( outStack.empty()){
            while( !inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
};