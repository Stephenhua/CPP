#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

//题目：字符串组合

void combinationCore( char * str, int len , vector<char>& rs){

    if( len == 0){
        vector<char>::iterator it;

        for( it = rs.begin();it<rs.end() ; it++){

            cout <<(*it);
        }
        cout <<endl;
        return;
    }
    if( *str =='\0'){
        return;
    }
    rs.push_back(*str);
    combinationCore(str+1,len-1,rs);
    rs.pop_back();
    combinationCore(str+1, len,rs);

}
void getCombination( char* str){

    if( str == nullptr){
        return;
    }

    int length = strlen(str);

    vector<char> rs;

    for( int i =1 ;i<=length ;i++){
        combinationCore( str, i, rs);
        Core(str,i);
    }
}

void CoreDiGui(char* pStr, char* pBegin){

    if( pStr=='\0'){
        cout<<*pStr<<endl;
    }else{

        for( char* pCh = pBegin ;*pCh!= '\0'; ++pCh){
            swap( *pCh ,*pBegin);
            CoreDiGui(pStr,pBegin+1);
            swap(*pCh, *pBegin);

        }
    }
}
void Core( char* pStr){
    if( pStr == nullptr){
        return ;
    }

    CoreDiGui( pStr,pStr);
}
int main(int argc,char* argv[]){
    char s[]= "abcde";
    getCombination(s);
    system("pause");
    return 0;
}