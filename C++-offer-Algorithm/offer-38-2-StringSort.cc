#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
//题目：字符串组合；


/*
字符串组合
*/
void combinationCore(char *str, int len ,vector<char>& rs){
    if(len==0){
        vector<char>::iterator it;
        for(it=rs.begin();it<rs.end();it++){
            cout<<(*it);
        }
        cout<<endl;
        return ;
    }

    if(*str=='\0'){
        return;
    }

    rs.push_back(*str);//把当前字符当做组合的一部分；包含当前元素，那么直接进行了len-1;
    combinationCore(str+1,len-1,rs);
    rs.pop_back();//删除当前字符，恢复之前的状态；不包含，则是len；
    combinationCore(str+1,len,rs);
}
void getCombination(char* str){
    if(str==nullptr){
        return;
    }

    int length=strlen(str);
    vector<char> rs;
    for(int i=1;i<=length;i++){
        combinationCore(str,i,rs);
    }
}

int main(int argc,char* argv[]){
    char s[]= "abcde";
    getCombination(s);
    system("pause");
    return 0;
}