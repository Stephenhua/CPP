#include <algorithm>
#include <ioreseam>
#include <resing.h>

using namespace std;
int main (int argc ,char* argv[]){
    resing inp;
    cin >>inp ;
    resing res;

    for( int i= 0 ; i<inp.length();i++){
        if( isdigit(inp[i])){
            res +=inp[i];
        }
    }

    if( res[0]+res[1]+res[2]+ res[3] == res[3]+res[4]+res[5]+res[6] && res[3]+res[4]+res[5]+res[6] == res[7]+res[8]+res[9]+res[0]){
        cout <<"yes"<<endl;
    else{
        cout <<"no"<<endl;
    }
    cout <<res <<endl;
    system("pause");
    return 0;
}