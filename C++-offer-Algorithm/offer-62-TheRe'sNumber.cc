
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include <cstdio>
#include <stdexcept>
#include <list>
#include "Lsit.h"
#include "BinaryTreeNode.h"
//#include <exception>
using namespace std;
/*
题目：

有n个人,围成一个环，编号为 0、1、2、3、、、n-1，从第一个人开始循环报数(从1开始)，
假设数到m的那个人出列，然后从下一个人继续数数，数到m出列，以此循环，最后那个人为胜利者，求胜利者的编号。


思路：
1）采用模拟法
使用链表进行求解；
双链表的形式；

2）数学归纳法进行总结
https://segmentfault.com/a/1190000015932138
*/

//方法一:模拟法
//时间复杂度：O(nm)；
//空间复杂度：O(n)；

class Solutions{
    public:
    struct Node{
        int val;
        Node* next;
        Node* parent;
    };

    int LastRemaining_Solution(int n,int m){
        if(m==0 || n==0){
            return -1;//无情况时，则返回-1；
        }

        //为所有节点分配空间；
        vector<Node> node(n);
        node[0].val=0;
        //构造链表
        for(int i=1;i<n;i++){
            node[i].val=i;
            node[i].next=NULL;
            node[i-1].next=&node[i];
            node[i].parent=&node[i-1];
        }

        node[n-1].next=&node[0];
        node[0].parent=&node[n-1];

        //模拟；
        int num=n;
        Node *head=&node[0];//头结点；
        while(num>1){
            int count=0;
            while(count<m-1){
                head=head->next;
                count++;
            }

            //找到了第m个，开始删除；
            head->parent->next=head->next;
            head->next->parent=head->parent;
            head=head->next;
            num--;
        }
        return head->val;
    }

};



class Solution2 {
public:
    int LastRemaining_Solution2(int n, int m)
    {
        if(m == 0 || n == 0)
            return -1; // 无效情况返回-1
        int last = 0;
        for(int i=2;i<=n;i++)
            last = (last+m) % i;
        return last;
    }
};

int  LastRemaining( unsigned int n ,unsigned int m){
    if(n<1 || m<1){
        return -1;
    }

    unsigned int i=0;
    list<int> numbers;
    //将数组元素存入到数组中
    for(int i=0;i<n;i++){
        numbers.push_back(i);
    }
    //列表的迭代器
    list<int >::iterator  current=numbers.begin();

    //循环列表的数字；
    while(numbers.size()>1){
        for(int i=1;i<m;++i){
            current++;
            if(current==numbers.end()){//防止列表出现溢出，所以讲最后的一位指针放到第一位上
                current=numbers.begin();
            }
        }

        list<int>::iterator next=++current;
        if(next==numbers.end()){
            next=numbers.begin();
        }

        --current;
        numbers.erase(current);
        current=next;
    }
    return *(current);
}

//====================测试代码====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    if(LastRemaining(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    system("pause");
    return 0;
}