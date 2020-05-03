#include <string.h>
#include <iostream>
using namespace std;

int main( int argc ,char* argv[]){

    string s1= "12 4 41";
    int j = 0 ;
    for(int i =0 ;i<s1.size();i++){
        if(s1[i]!=' '){
            s1[j] = s1[i];
            cout<<s1[j] <<endl;
            j++;
        }
    }
    //s1[0]=s1[2];
    s1.erase(s1.begin()+j,s1.end());

    cout <<s1 <<endl;

    cout <<s1.substr(0,j) <<endl;
    system("pause");
    return 0 ;
}