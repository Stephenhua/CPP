#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main(int argc ,char* argv[]){
    string s; 
    cin >> s;
    int size = s.size();
    int avg = size/2 ;
    int sumA=0;
    for(int i = 0 ;i <size;i++){
        if(s[i]>='A' && s[i]<='Z'){
            sumA++;
        }
    }

    int res = min( abs(avg-sumA),abs(avg-(size-sumA)));
    cout << res << endl;
    return 0 ;
}