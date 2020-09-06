#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;


void test(){
    
    static int a = 10;
    int b = 10;
    a++;
    b++;
    cout << a << " "<< b <<endl;

}

int main( int argc ,char*argv[]){
    test();
    test();
    test();
    system("pause");
    return 0 ;
}