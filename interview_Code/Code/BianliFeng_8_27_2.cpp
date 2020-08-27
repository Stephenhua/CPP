#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace  std;

int main(int argc,char*argv[]){
    
    string str;
    while (cin >>str)
    {

        Core(str); 
    }

    return 0 ;
    
}

void Core(string str){
    vector<vector<char>> res[5][5]={{"0","1","C","H","A"},{"9","E","7","8","I"},{'K','D','4','8','J'},{'6','5','F','G','O'},{'L','N','M','2','3'}};
    int n = str.size();
    
}