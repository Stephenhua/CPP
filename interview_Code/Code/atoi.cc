#include <string.h>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc ,char* argv[] ) {
    using namespace std;
    string strnum=" -232s3112";
    int num1=atoi(strnum.c_str());
    long int num2=strtol(strnum.c_str(),nullptr,10);
    cout<<"atoi的结果为:"<<num1<<endl;
    cout<<"strtol的结果为:"<<num2<<endl;

    system("pause");
    return 0;
}