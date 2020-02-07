//该方法采用了空间复杂度换取时间复杂度，
#include <stack>
#include <assert.h>

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

template <typename T > void StackWithMin<T>::min()const{
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