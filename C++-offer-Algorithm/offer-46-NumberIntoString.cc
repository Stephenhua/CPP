/*
采用递归和回溯的方式进行，但是容易出现重复的数字；
所以采用自下而上的方法进行，从右到左翻译并计算不同翻译的数目；
*/


#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int GetTanslationCount_1(const string & number);

int GetTranslationCount(int number){
    if(number < 0)
        return 0;

    string numberInString = to_string(number);
    return GetTanslationCount_1(numberInString);
}
//设立一个数组进行存储个数；然后进赋值
int GetTanslationCount_1(const string &number){
   int length = number.length();
    int* counts = new int[length];
    int count = 0;
    //采用倒叙的形式进行求解
    for(int i = length - 1; i >= 0; --i)
    {
        count = 0;
         if(i < length - 1)
               count = counts[i + 1];
         else
               count = 1;

        if(i < length - 1)
        {
            //判断两个数字之间的关系
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25)
            {
                if(i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }

    count = counts[0];
    delete[] counts;

    return count;
}


//测试代码

void Test(const string & testname,int number ,int expected){
    if(GetTranslationCount(number)==expected){
        cout<<testname<<"passed ."<<endl;
    }else{
        cout<<testname<<"failed"<<endl;
    }
}
//功能测试
void Test1(){
    int number=0;
    int expected=1;
    Test("Test1",number,expected);
}

void Test2(){
    int number=10;
    int expected=2;
    Test("Test1",number,expected);
}

//特殊输入测试（包含 负数、0、25 、26的数字测试）

void Test3(){
    int number=125;
    int expected=2;
    Test("Test1",number,expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
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
    Test8();
    Test9();

    system("pause");
    return 0;
}



