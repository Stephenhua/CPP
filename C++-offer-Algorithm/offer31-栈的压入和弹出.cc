#include <cstdio>
#include <stack>

bool isPopOrder(const int* pPush ,const int *pPop,ine nLength){
    bool bPossible =true ;
    if(pPush!=nullptr&& pPop!=nullptr&&nLength>0){
        const int*pNextPush=pPush;
        const int * pNextPop =pPop;
        std::stack<int> stack_Data;
        while(pNextPush-pNextPop<nLength){
            //当辅助栈中国的栈顶元素不是要弹出的元素，则先压入到其中；
            while(stack_Data.empty()||stack_Data.top()!=*pNextPop){
                //如果所有元素都压入到辅助栈中，退出循环
                if(pNextPush-pNextPop==nLength){
                    break;
                }

                stack_Data.push(*pNextPush);
                pNextPush++;
            }
            if(stack_Data.top()!=*pNextPop){
                break;
            }
            stack_Data.pop();
            pNextPop++;

        }

        if(stack_Data.empty()&&pNextPop-pPop==nLength){
            bPossible=true;
        }
    }
    return bPossible;
}