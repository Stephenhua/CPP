#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>

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
int main(){
    int m =100;
    convert_10_To_16(m);
    cout << rs[0]<<endl;
    system("pause");
    return 0 ;
}