/*
网页链接：
https://www.cnblogs.com/wangkundentisy/p/8946858.html

思路一：
对于1~n中的每个整数，分别判断n中的1的个数，时间复杂度WieO(NlogN)，当N比较大时，一般会超时；
方法二：
找规律，
在分析之前，首先需要知道一个规律：

从 1 至 10，在它们的个位数中，数字1出现了 1 次。
从 1 至 100，在它们的十位数中，数字1出现了 10 次。
从 1 至 1000，在它们的百位数中，数字1出现了 100 次。
依此类推，从 1 至 10i，在它们右数第二位中，数字1出现了10 ^ (i - 1)次。

对于 n = 2134,要找到从1 ~ 2134这2134个数字中所有1的个数。我们可以对2134进行逐位分析：

(1)在个位上，从1~2130，包含213个10，因此数字1出现了213次，剩下的数字2131、2132、2133、2134中个位数上只有2131包含树脂字1，剩下的都不包含。所以个位数上的数字1的总数为213 + 1 = 214。

(2)在十位上，从1 ~ 2100，包含了21个100，因此数字1出现了21 * 10 = 210次，剩下的数字从2101 ~ 2134，只有2110 ~ 2119这10个数字中十位的数字为1，所以十位上的数字1的总数为210 + 10 = 220。

(3)在百位上，从1 ~ 2000，包含了2个1000，因此数字1出现了2 * 100 = 200次，剩下的数字从2001 ~ 2134，只有2100 ~ 2134这35个数字中的百位的数字为1，所以百位数上数字1的总数为200 + 35= 235。

(4)在千位上，包含了0个10000，因此数字1出现了0 * 1000 = 0次，剩下的数字中只有1000 ~ 1999这1000个数字中的千位的数字为1，所以千位上的数字1的总数为1000。

因此从1 ~ 2134这n个数字中，数字出现的总的次数为 214 + 220 + 235 +1000 = 1669。

总结一下以上的步骤，可以得到这么一个规律：

对于数字n，计算它的第i(i从1开始，从右边开始计数)位数上包含的数字1的个数：

假设第i位上的数字为x的话，则

1.如果x > 1的话，则第i位数上包含的1的数目为：(高位数字 + 1）* 10 ^ (i-1)  (其中高位数字是从i+1位一直到最高位数构成的数字)

2.如果x < 1的话，则第i位数上包含的1的数目为：(高位数字 ）* 10 ^ (i-1)

3.如果x == 1的话，则第i位数上包含1的数目为：(高位数字) * 10 ^ (i-1) +(低位数字+1)   (其中低位数字时从第i - 1位数一直到第1位数构成的数字)

*/
#include <cstdio>
//#include "Array.h"
#include <set>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;
int NumberOfDigitalOne(int n){

    if(n<0){
        return 0;
    }

    int i=1;
    int high=n;
    int cnt=0;

    while(high!=0){
        high=n/(pow(10,i));
        int tmep=n / (pow(10,i-1));
        int cur=tmep % 10;//cur表示第i位的值，从1开始计算
        int  low=n-tmep*pow(10,i-1);

        if(cur<1){
            cnt+=high*pow(10,i-1);
        }else if(cur>1){
            cnt+=(high+1)*pow(10,i-1);
        }else{
            cnt+=high*pow(10,i-1);
            cnt+=(low+1);
        }
        i++;
    }
    return cnt;
}

void Test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    
    int result=NumberOfDigitalOne(n);
            cout<<result<<endl;
    if(NumberOfDigitalOne(n) == expected){


        printf("Solution2 passed.\n");
    }
    else{
        printf("Solution2 failed.\n"); 
        }

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
    Test("Test9", 999, 210);
}

int main(int argc, char* argv[])
{
    Test();

    system("pause");
    return 0;
}