#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;


int MatchCore( char a, char b ){
    if( a == '(' && b == ')'){
        return 1;
    }else if( a == '[' && b == ']'){
        return 1;
    }else if( a == '{' && b == '}'){
        return 1;
    }else{
        return 0 ;
    }
}
bool isMatch( string s1){

    int length = s1.size();

    stack<char> temp ;

    for(int i =0 ;i<length ;i++){
        
        if( s1[i] == '(' || s1[i]=='[' || s1[i] == '{'){
            temp.push(s1[i]);
        }else{

            if( !temp.empty() && MatchCore(temp.top() , s1[i])){
                temp.pop();
            }
            else{
                return 0 ;
            }
        }
    }
    bool result =false;
    if( temp.empty()){
        result = true;
    }else{
        result = false;
    }

    return result ;
}

int main( int argc ,char* argv[]){

    string s1="(())"; 
    //cin>>s1;
    bool ifMatch = isMatch(s1);
    cout <<"isMatch" <<ifMatch <<endl;

    system("pause");
    return 0 ;
}