#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
using namespace std;

int ViloentMatch(char* s, char* p){
    if(s==nullptr || p==nullptr){
        return -1;
    }
    int sLen=strlen(s);
    int pLen= strlen(p);

    int i=0;
    int j=0;

    while (i<sLen && j<pLen)
    {
        if(s[i]==p[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
        /* code */
    }
    if(j == pLen){
        return i-j;
    }
    else {
        return -1;
    }
    
}


//测试代码

void Test(char* testName, char* StringStream, char* paternString,int ifFind){

    if(testName!=nullptr){
        cout<<"Test1"<<endl;
    }

    int result= ViloentMatch(StringStream,paternString);

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