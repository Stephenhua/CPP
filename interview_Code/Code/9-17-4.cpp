#include <iostream>
#include <vector>
using namespace std;


int main( int argc, char* argv[] ){
    string s ;
    cin >> s;

    int a[26];
    for(int i = 0 ; i < 26 ;i++){
        a[i] = 0 ;
    }

    int length = s.length();

    for(int i = 0 ; i< length ;i++ ){
        a[s[i] - 'a']++;
    }

    int min = a[s[0]-'a'];
    for(int i = 0 ; i <length ;i++){
        if( a[s[i]-'a'] < min ){
            min = a[ s[i] - 'a'];
        }
    }
    for(int i = 0 ; i < length ;i++){
        if( a[s[i] - 'a']  > min ){
            cout << s[i] ;
        }
    }
    cout <<endl;
    return 0 ;
}