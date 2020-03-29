#include <iostream>
#include<algorithm>
#include <string.h>
using namespace std;
/*
解题思路：
当模式中的第二个字符不是“*”时：
1、如果字符串第一个字符和模式中的第一个字符相匹配，那么字符串和模式都后移一个字符，然后匹配剩余的。
2、如果 字符串第一个字符和模式中的第一个字符相不匹配，直接返回false。
当模式中的第二个字符是“*”时：
字符串第一个字符跟模式第一个字符不匹配，则模式后移2个字符，继续匹配
如果字符串第一个字符跟模式第一个字符匹配，可以有3种匹配方式：
1）模式后移2字符，相当于x*被忽略；mathCore(str,pattern+2)
2）字符串后移1字符，模式后移2字符；mathCore(str+1,pattern+2)
3）字符串后移1字符，模式不变，即继续匹配字符下一位，因为*可以匹配多位。mathCore(str+1,pattern)
*/
bool mathCore(const char* str, const char* pattern){
    if(*str=='\0' && *pattern=='\0'){
        return true;
    }

    if(*str!='\0' && * pattern=='\0'){
        return false;
    }

    if(*(pattern+1)=='*'){
        if(*pattern==*str  ||(*pattern=='.'&&*str!='\0')){
            return mathCore(str+1,pattern+2)||mathCore(str+1,pattern)||mathCore(str,pattern+2);
        }else{
            return mathCore(str,pattern+2);
        }
    }

    if(*str==*pattern ||(*pattern=='.'&& *str!='\0')){
        return mathCore(str+1,pattern+1);
    }
    return false;
}
bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return mathCore(str, pattern);
}
// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);
    system("pause");

    return 0;
}