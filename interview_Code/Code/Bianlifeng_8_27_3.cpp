#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace  std;

string Core(string str){
    int n = str.size();
    string res;
    for(int i =0 ;i <n ;i+=2){
        char  p = str[i];
        int num = p-'0';

        for(int i=0 ;i < num ;i++){
            res +=str[i+1];
        }
    }
    return res;
}

int main(int argc, char* argv[] ){
    string str;
    cin>>str;
    string res = Core(str);
    cout <<res<<endl;
    system("pause");
    return 0 ;
}