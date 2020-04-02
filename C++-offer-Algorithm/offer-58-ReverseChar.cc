/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，
写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，
但却读不懂它的意思。例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
at对一一翻转这些单词顺序可不在行，你能帮助他么？


测试时候注意的步骤：
1）功能测试：a边界中有多个单词，b、边界中只有一个单词；
2）鲁邦性测试：输入为；
3）边界值测试：测试空字符串、字符创只有空格、字符串中只有空格；
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
//#include <exception>
using namespace std;
//using namespace boost;
//方法一：采用特定的函数进行分割，
/*
 string  ReverseSentence(string str){
    if(str.length()==0){
        return str;
    }

    const char *split=" ";
    const char*temp=str;
    string temp[]=str.split(" ");
    string  res= "";
    for(int i=temp.size()-1;i>=0;i--){
       
        res+=temp[i];
        if(i!=0){
            res+=" ";
        }
        return res;
    }
}

*/

//方法二：对数组进行挨个翻转，从而翻转数字；先将单词翻转，然后进行组合；这样的就会导致额外的内存空间去存储临变量；

string ReverseSentence_1(string str){
    string ret="";
    string temp="";

    for(int i=0;i<str.length();i++){
        if(str[i]==' '){//交换单词顺序，并在前添加空格；
            ret=' ' +temp+ret;
            temp="";
        }else{//翻转单词
            temp+=str[i];
        }
    }

    if(str.length()){//由于最后一个单词并没有进行相加，所以需要进行交换值；
        ret=temp+ret;
    }
    return ret;
}

//方法三：首选翻转所有字符，然后在翻转每个单词中字符的顺序；
//通过扫描空格确定每个单词的起始和终止位置。

void Reverse(char *pBegin,char *pEnd){
    if(pBegin==nullptr || pEnd==nullptr){
        return ;
    }
    while(pBegin<pEnd){
        char temp=*pBegin;
        *pBegin=*pEnd;
        *pEnd=temp;

        pBegin++;
        pEnd--;
    }
}

char * ReverseSentence_2(char *pData){

    if(pData==nullptr){
        return nullptr;
    }

    char *pBegin=pData;

    char* pEnd=pData;

    while(*pEnd != '\0'){
        pEnd++;
    }
    pEnd--;//退回到单词的最后一位；

    Reverse(pBegin,pEnd);

    pBegin=pEnd=pData;

    while(*pBegin != '\0'){
        if( *pBegin == ' ' ){
            pBegin++;
            pEnd++;
        } else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd++;
    }

    return pData;
    
}

// ====================测试代码====================
void Test(const char* testName, char* input, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    char *input1= ReverseSentence_2(input);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(input1, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}



// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", " ", " ");
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    system("pause");
    return 0;
}
