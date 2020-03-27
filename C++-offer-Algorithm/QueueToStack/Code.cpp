#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class CStack
{
public:
	CStack() {}
	~CStack() {}
	void push(const T& val)
	{
		if (queue1.empty() && queue2.empty())  //两个队列为空，则插入queue1
		{
			queue1.push(val);
		}

		if (queue1.empty())         //如果queue1为空，则插入queue2
		{
			queue2.push(val);
		}
		else
		{
			queue1.push(val);      //如果queue2为空，则插入queue1
		}
	}
	T pop()
	{
		if (queue1.empty())        //如果queue1为空
		{
			if (queue2.empty())    //如果queue2为空，则说明栈为空
			{
				throw new exception("stack is empty");
			}
			else
			{
				if (queue2.size() == 1)   //如过queue2只有一个元素，直接退出
				{
					T result = queue2.front();
					queue2.pop();
					return result;
				}
				else
				{
					while (queue2.size() != 1)  //依次退出队中元素，直到队列中只有队尾元素
					{
						queue1.push(queue2.front());
						queue2.pop();
					}
					T result = queue2.front();  //将队尾元素退出
					queue2.pop();
					return result;
				}
			}
		}
		else          //如果queue1不为空
		{
			if (queue1.size() == 1)     //如果queue1中只有队尾元素时，直接退出
			{
				T result = queue1.front();
				queue1.pop();
				return result;
			}
			else
			{
				while (queue1.size() != 1)  //依次退出queue1中的元素到queue2，直到queue1只有队尾元素
				{
					queue2.push(queue1.front());
					queue1.pop();
				}
				T result = queue1.front(); //将队尾元素弹出
				queue1.pop();
				return result;
			}
		}

	}
private:
	queue<T> queue1;
	queue<T> queue2;
};

int main()
{
	CStack<char> stack;

	//测试用例1:
	stack.push('a');           //元素a入栈
	stack.push('b');           //元素b入栈
	stack.push('c');           //元素c入栈
	cout << "第1次出栈元素是：" << stack.pop() << endl;
	cout << "第2次出栈元素是：" << stack.pop() << endl;
	stack.push('d');           //元素d入栈
	cout << "第3次出栈元素是：" << stack.pop() << endl;
	cout << "第4次出栈元素是：" << stack.pop() << endl;
	return 0;

}