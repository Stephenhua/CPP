#include <cstdio>

//==================================
//方法一容易引起死循环的解法，主要针对输的数位负数，那么就会出向负数
//==================================
int NumberOf1_Soultuions(int n){
    int count=0;
    while(n){
        if(n&1){
            count++;
            n=n>>1;
        }
    }
    return count;
}

//==================================
//方法二“
//常规解法：主要反复左移1，使其遍历整个序列
//==================================

int NumberOf1_Solutions2(int n){
    int count=0;
    unsigned int flag=1;
    while(flag){
        if(n&&flag){
            count++;
        }
        flag=flag>>1;
    }
    return count;
}

//==================================
//方法三：
//进一步解法：利用整个数减一，并且与其本身进行相与；
//==================================

int NumberOf1_Soultions3(int n ){
    int count=0;
    while (n)
    {
        ++count;
        n=(n-1)&&n;
        /* code */
    }
    return count;
    
}

void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solutions2(number);
    if (actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Soultions3(number);
    if (actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}
