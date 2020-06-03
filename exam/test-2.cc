#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

vector<string> rs;
void convert_10_To_16( int num){

    char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int nums[100];
    int i=0;
    int m;
    while( num > 0){
        nums[i++] = num%16;
        num = num/16;
    }
    string rs1;
    for( i=i-1; i>=0 ;i--){
        m = nums[i];
        rs1+=hex[m];
    }
    
    rs.push_back(rs1);
}

int main( int argc ,char* argv[]){


    vector<int> hexIp;
    char ipv4[100];
    cin.getline(ipv4,100);

    char* str;

    const char * d =".";
    str = strtok(ipv4,d);

    int num ;

    bool flag = true;

    int i=0,j=0;

    while(str != 0){

        num = atoi(str);

        hexIp.push_back( num);

        i++;

        if( i>4 || num >255 || num < 0){

            flag = false;

            break;
        }
        str = strtok(0,d);
    }


    if( (i<3 && flag)|| !flag || i>4){
        cout <<"false"<<endl;
    }

    //cout << hexIp.size() <<endl;

    for( i =0 ;i <4 ;i++){
        convert_10_To_16(hexIp[i]);
    }

    for( int i =0;i <3 ;i++){
        cout <<rs[i] <<".";
    }
    cout <<rs[3]<<endl;

    system("pause");
    return 0 ; 
}

