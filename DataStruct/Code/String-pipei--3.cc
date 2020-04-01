#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
using namespace std;

int MAXSIZE= 256;
int moveLength[MAXSIZE];

void getMoveLength(char *T){

    int tLen=strlen(T);

    for(int i=0;i<MAXSIZE;i++){
        moveLength[i]= tLen+1;
    }

    for(int i=0;T[i];++i){
        moveLength[T[i]]=tLen-i;
    }
}

int Sunday(char* S, char*T) {
　　　　
        getMoveLength(T);
　　    int tLen = strlen(T);
　　　　int sLen = strlen(S);
　　　　int i = 0;    //    S遍历下标
　　　　while(i < sLen) {
　　　　　　int j = 0;
　　　　　　//    符合条件下标就继续右移
　　　　　　for(  ; j < tLen && i + j < sLen && S[i + j] == T[j]; ++ j) ;
　　　　　　//    遍历结束，判断遍历情况
　　　　　　if(j >= tLen) return i;
　　　　　　//    查找不成功，那么S下标右移
　　　　　　if(i + tLen >= sLen) 
　　　　　　return -1;
　　　　　　i += moveLength[S[i + tLen]];
　　　　}
　　
　　　　return -1;
　　}


//测试代码

void Test(char* testName, char* StringStream, char* paternString,int ifFind){

    if(testName!=nullptr){
        cout<<"Test1"<<endl;
    }

    int result= Sunday(StringStream,paternString);

    cout<<"result"<< result <<endl;

    if(result == ifFind){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }

}

void Test1(){
    char s[]="abcdefgabcdefgh";
    char p[]="abcdefga";
    Test("Test1",s,p,0);
}

void Test2(){
    char s[]="abcdefgabcdefgh";
    char p[]="fga";
    Test("Test2",s,p,5);
}


void Test3(){
    char s[]="abcdefgabcdefgh";
    char p[]="gh";
    Test("Test3",s,p,13);
}

void Test4(){
    char s[]="abcdefgabcdefgh";
    char p[]="ab";
    Test("Test4",s,p,0);
}


void Test5(){
    char s[]="abcdefgabcdefgh";
    char p[]="";
    Test("Test5",s,p,-1);
}

void Test6(){
    char s[]="";
    char p[]="";
    Test("Test6",s,p,-1);
}

int main(int argc ,char* argv[]){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
 Test6();
    system("pause");
    return 0;
}
