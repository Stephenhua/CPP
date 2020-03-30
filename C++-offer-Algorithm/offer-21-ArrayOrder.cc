#include <cstdio>
#include <iostream>
using namespace std;
void Record(int *pData, unsigned int length,bool(*func)(int));
//void isEven(int n);

void RecordOddEven_1(int *pData,unsigned int length){
    if(pData==nullptr||length==0){
        return ;
    }

    int *pBegin=pData;
    int *pEnd=pData+length-1;
    while(pBegin<pEnd){
        //向后移动pBegin,直到其指向指数；
        while(pBegin<pEnd&&(*pBegin&&0x1)!=0){
            pBegin++;
        }

        //向前移动pEnd，直到遇到前面的指针
        while(pBegin<pEnd&&(*pEnd&&0x1)==0){
            pEnd--;
        }

        if(pBegin<pEnd){
            int temp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=temp;
        }
    }
}
/*
bool isEven(int n){

    return (n&1)==0;

}
*/
void PrintArray(int numbers[],int length){
    if(length<0){
        return;
    }

    for(int i=0;i<length;i++){
        printf("%d\t",numbers[i]);
    }
    printf("\n");
}

void Test(char*testName,int numbers[],int length){
    if(testName!=nullptr){
        printf("%s,begins:\n",testName);
    }

    int *copy=new int[length];
    for(int i=0;i<length;i++){
        copy[i]=numbers[i];
    }

    printf("Test soulutions 1:\n");
    PrintArray(numbers,length);
    RecordOddEven_1(numbers,length);
    PrintArray(numbers,length);
}

void Test1(){
    int numsbers[]={1,2,3,4,5,6,7,8};
    Test("Test1",numsbers,sizeof(numsbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", nullptr, 0);
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