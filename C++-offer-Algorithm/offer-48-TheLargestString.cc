#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
在计算的过程中，从左向右扫描，分为两种情况
1）若第i个字符在之前并没没有出现过，则其值为f（i）=f(i-1)+1;
2)如果第i个字符在之前出现过，分为两种情况进行讨论，
    计算第i个字符距离上次出现之间的距离为d
  a) 若d<f(i-1)，则说明第i个字符出现在f(i-1)对应的不重复字符串内，那么更新f(i)=d;
  b)若d>f(i-1),则无影响，f(i)=f(i-1)+1;

*/

int lengthOfLongestSubstring(string s){
    if(s.length()==0){
        return 0;
    }

    int curLen=0;
    int maxLen=0;
    
    //position目的用于存储最近出现元素的下标值；

    int *position=new int[26];
    for(int i=0;i<26;++i){
        position[i]=-1;
    }

    for(int i=0;i<s.length();i++){
        int preIndex=position[s[i]-'a'];
        if(preIndex<0 ||i-preIndex>curLen)//表示没有出现过，或者d>f(I-1);
        {
            ++curLen;
        }else{//表明d<f(i);所以更新curLeno的值
            if(curLen>maxLen){
                maxLen=curLen;
            }
            curLen=i-preIndex;//如果出现重复的元素，那么最大的元素间隔就是两个相同元素之间的个数；，舍去前一个出现的元素，将现有元素新加入到其中，组成一个新的元素额序列；
        }        
        position[s[i]-'a']=i;

     }
    if(curLen>maxLen){
         maxLen=curLen;
    }

     delete[] position;

     return maxLen;

    
}
void testSolutions(const std::string &input ,int expected){
    int output=lengthOfLongestSubstring(input);
    if(output==expected){
        std::cout<<"Solution passed .with input "<<output<<endl;
    }else{
        cout<<"Solution failed ,with output "<<output<<endl;
    }

}

void test1(){
    const string input="abcacfrar";
    int expected=4;
    testSolutions(input,expected);
}


void test2(){
    const string input="aaaaaa";
    int expected=1;
    testSolutions(input ,expected);
}
void test3(){
    const string input="abcdefgh";
    int expected=8;
    testSolutions(input,expected);
}
void test4(){
    const string input="a";
    int expected=1;
    testSolutions(input,expected);
}

void test5(){
    const string input ="";
    int expected=0;
    testSolutions(input, expected);
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