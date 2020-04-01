#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string.h>

using namespace std;

char*  deleteDuplicateNum(char * pString){
    
    if(pString==nullptr){
        return pString;
    }

    const int TableSize=256;
    int hashTable[TableSize];

    for(int i=0;i<TableSize;i++)
    {
        hashTable[i]=0;
    }

    char *pHashkey=pString; 
    char * pStart=pString;
    char* pEndStart=pString;

    while((*pHashkey)!='\0'){

        if(hashTable[(*pHashkey)]==0){
            hashTable[*pHashkey]=1;
            pString[pStart++]=pString[pHashkey];
        }

        pHashkey++;

    }

    return pString; 

}
void Test(char* pString , char* expected){
    if(strlen(pString)!=strlen(expected)){
        cout<<"Test Failed"<<endl;
        return ;
    }

    char* result=deleteDuplicateNum(pString);

    int num=0;
    for(int i=0;i<strlen(pString);i++){
        if(pString[i]==expected[i]){
            num++;
        }
    }
    if(num==strlen(expected)){
        cout<<"Test passed"<<endl;
    }else{
        cout<<"Test failed"<<endl;
    }
}

int main(int argc, char argv[]){
    
    Test("google",'gle');
    Test("aabccdbd",'abcd');
    Test("abcdefg",'abcdefg');
    Test(nullptr,'\0');

    system("pause");
    return 0;

}