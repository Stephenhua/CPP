#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
using namespace std;

void GetNexval(char* p ,int next[]);
int KMPSearchCore(char* s, char* p,int next[]);


int KMPSearch( char* s, char* p){

    int *next = new int[strlen(p)+1];
    GetNexval(p,next);
    int result=KMPSearchCore(s,p,next);
    delete [] next;
    return result;
}

void GetNexval(char* p ,int next[]){
    int len=strlen(p);
    next[0]=-1;
    int k=-1;
    int j=0;
    while(j<len-1){
        
        if(k==-1 || p[j]==p[k]){
            ++k;
            ++j;

		//p[k]表示前缀，p[j]表示后缀
            if(p[j]!=p[k]){
                next[j]=k;
            }else{
                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]
                next[j]=next[k];
            }
        }else{
            k=next[k];
        }
    }

}


int KMPSearchCore(char* s, char* p,int next[]){
   if(s==nullptr || p==nullptr){
        return -1;
    }
    int sLen=strlen(s);
    int pLen= strlen(p);

    int i=0;
    int j=0;

    while (i<sLen && j<pLen)
    {

		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j = next[j];//主要找next比较困难；
        }

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

    int result= KMPSearch(StringStream,paternString);

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
