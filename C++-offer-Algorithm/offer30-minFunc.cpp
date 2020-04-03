//该方法采用了空间复杂度换取时间复杂度，
#include <stack>
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T> class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    const T& min() const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
    std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};
template <typename T > void StackWithMin<T>::push(const T& value){
    m_data.push(value);
    if(m_min.size()==0|| value<m_min.top()){
        m_min.push(value);
    }else{
        m_min.push(m_min.top());
    }
}


template <typename T > void StackWithMin<T>::pop(){
    assert(m_data.size()>0&&m_min.size()>0);
    m_data.pop();
    m_min.pop();
}

template <typename T > const T& StackWithMin<T>::min()const{
    assert(m_data.size()>0&&m_min.size()>0);
    return m_min.top();
}

template <typename T> T& StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}


void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);

    system("pause");

    return 0;
}