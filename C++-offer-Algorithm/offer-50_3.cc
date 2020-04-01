#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string.h>

using namespace std;

//删除字符串中所有重复出现的字符；

string    removeDuplicate( string s){
    int len= s.length();
    /*if(len<2){
        return ;
    }*/

    const int TableSize=256;
    int hashTable[TableSize];
    string temp;

    for(int i=0;i<TableSize;i++)
    {
        hashTable[i]=0;
    }
    int n=0;
    int i=0;
    while(i<len){
        if(hashTable[s[i]]==0){
            hashTable[s[i]]=1;
            s[n++]=s[i];
        }
        i++;
    }
    temp=s.substr(0,n);
    //s.erase(n，s.length());
    return temp;
}
void Test(const string pString , const string expected){

    string result =removeDuplicate( pString );
    
    //removeDuplicate( pString );
    //string result=pString;
    cout<<"Lenght"<<result.length()<<endl;
    cout<<result<<endl;

    if(result.length()!=expected.length()){
        cout<<"Test Failed"<<endl;
    }else if(result.length()==0 && expected.length()==0){
        cout<<"Passed"<<endl;
    }else if(result.length()==expected.length()){

        if( result==expected){
            cout<<"Test passed"<<endl;
        }else{
            cout<<"Test failed"<<endl;
      }
 }
}


int main(int argc, char argv[]){
    
    string s1 = "abcde";
    string s11="abcde";

    string s2 = "aaabbb";
    string s21="ab";

    string s3 = "";
    string s31= "";

    string s4 = "abababc";
    string s41="abc";
    
    string s51="cd";
    string s5 = "cccccd";

    Test(s1,s11);
    Test(s2,s21);
    Test(s3,s31);
    Test(s4,s41);
    Test(s5,s51);

    system("pause");
    return 0;

}