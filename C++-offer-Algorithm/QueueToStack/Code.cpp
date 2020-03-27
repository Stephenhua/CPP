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
		if (queue1.empty() && queue2.empty())  //��������Ϊ�գ������queue1
		{
			queue1.push(val);
		}

		if (queue1.empty())         //���queue1Ϊ�գ������queue2
		{
			queue2.push(val);
		}
		else
		{
			queue1.push(val);      //���queue2Ϊ�գ������queue1
		}
	}
	T pop()
	{
		if (queue1.empty())        //���queue1Ϊ��
		{
			if (queue2.empty())    //���queue2Ϊ�գ���˵��ջΪ��
			{
				throw new exception("stack is empty");
			}
			else
			{
				if (queue2.size() == 1)   //���queue2ֻ��һ��Ԫ�أ�ֱ���˳�
				{
					T result = queue2.front();
					queue2.pop();
					return result;
				}
				else
				{
					while (queue2.size() != 1)  //�����˳�����Ԫ�أ�ֱ��������ֻ�ж�βԪ��
					{
						queue1.push(queue2.front());
						queue2.pop();
					}
					T result = queue2.front();  //����βԪ���˳�
					queue2.pop();
					return result;
				}
			}
		}
		else          //���queue1��Ϊ��
		{
			if (queue1.size() == 1)     //���queue1��ֻ�ж�βԪ��ʱ��ֱ���˳�
			{
				T result = queue1.front();
				queue1.pop();
				return result;
			}
			else
			{
				while (queue1.size() != 1)  //�����˳�queue1�е�Ԫ�ص�queue2��ֱ��queue1ֻ�ж�βԪ��
				{
					queue2.push(queue1.front());
					queue1.pop();
				}
				T result = queue1.front(); //����βԪ�ص���
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

	//��������1:
	stack.push('a');           //Ԫ��a��ջ
	stack.push('b');           //Ԫ��b��ջ
	stack.push('c');           //Ԫ��c��ջ
	cout << "��1�γ�ջԪ���ǣ�" << stack.pop() << endl;
	cout << "��2�γ�ջԪ���ǣ�" << stack.pop() << endl;
	stack.push('d');           //Ԫ��d��ջ
	cout << "��3�γ�ջԪ���ǣ�" << stack.pop() << endl;
	cout << "��4�γ�ջԪ���ǣ�" << stack.pop() << endl;
	return 0;

}