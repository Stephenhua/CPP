#include <iostream>
#include <string.h>

using namespace std;

void memmove_my( char* dest ,char* src ,size_t n){
    char* s_dest = dest;
    char* s_src = src ;

    if( s_dest > s_src && (s_src+n > s_dest) ){
        s_dest = s_dest+n -1;
        s_src = s_src+n - 1;

        while(n--){
            *s_dest-- = *s_src--;
        }
    }else{
        while( n--){
            *s_dest++ = *s_src++;
        }
    }
}
int main(){
    char* s="ancsdg";
    char* d;
    memmove_my( d,s,7);

    cout <<"s Addresss"<< &s <<endl;
    cout <<" S char " <<s <<endl;

    cout <<" d Address "<< &d <<endl;
    cout <<"D char "<< d <<endl;

    system("pause");
    return 0;
}
