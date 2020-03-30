#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

bool isPopOrder(const int* pPush ,const int *pPop,int nLength){
    bool bPossible =false;
    if(pPush!=nullptr && pPop!=nullptr && nLength>0){

        const int*pNextPush=pPush;
        const int * pNextPop =pPop;

        std::stack<int> stack_Data;

        while(pNextPop-pPop<nLength){
            //当辅助栈中国的栈顶元素不是要弹出的元素，则先压入到其中；
            while(stack_Data.empty()||stack_Data.top()!=*pNextPop){
                //如果所有元素都压入到辅助栈中，退出循环
                if(pNextPush-pPush==nLength){
                    break;
                }

                stack_Data.push(*pNextPush);
                
                pNextPush++;
            }
            //处理边界条件；
            if(stack_Data.top()!=*pNextPop){
                break;
            }
            //弹出顶层元素；
            stack_Data.pop();
            pNextPop++;

        }

        if(stack_Data.empty()&&pNextPop-pPop==nLength){
            bPossible=true;
        }
    }
    return bPossible;
}

// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    system("pause");
    return 0;
}