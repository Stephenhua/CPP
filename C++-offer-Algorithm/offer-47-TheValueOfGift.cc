#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

    int getMaxValue(const int*values ,int rows ,int cols){
        if(values ==nullptr ||rows <=0 ||cols <=0){
            return 0;
        }

        int * maxValue=new int[cols];

        for(int i=0;i<rows;++i){
            for(int j=0;j<rows;++j){
                int left=0;
                int up=0;

                if(i>0){
                    up =maxValue[j];
                }
                if(j>0){
                    left=maxValue[j-1];                
                }

                //比较两个值得大小
                maxValue[j]=max(left,up)+values[i*cols+j];
            }
        }
        int max_Value=maxValue[cols-1];

        delete[] maxValue;
        return max_Value;
    }


//测试代码
void test(const char* testName,const int *values ,int rows ,int cols ,int expectd){
    if(getMaxValue(values,rows,cols)==expectd){
        cout<<testName<<":solutions passed."<<endl;
    }else{
        cout<<testName<<"solutions failed ."<<endl;
    }
}


void test1(){
    int values[][3]={
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }

    };
    int expected=29;
    test("test1",(const int *)values,3,3,expected);

}

void test2()
{
    //四行四列
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // 一行四列
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // 一行一列
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // 空指针
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    system("pause");
    return 0;
}
