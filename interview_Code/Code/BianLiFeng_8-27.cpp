#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace  std;

int main(int argc,char* argv[]){
    int  L;
    cin >> L ;

    vector<int> widths;
    vector<int> values;

    int temp;
    while(cin >>temp){
        widths.push_back(temp);
    }
    int temp2;
    while ( cin >>temp2)
    {
        values.push_back(temp2);
    }
    

    int res = layout(L,widths,values);
    
    cout <<res <<endl;
    return 0 ;

}

int layout(int length ,vector<int>& widths,vector<int>& values){
    int size = widths.size();
    int res;
    if(size == 0 ){
        return 0 ;
    }

    vector<vector<int>> dp(size+1,vector<int>(length+1,0));

    for(int i =1 ;i <= size;i++){
        for(int j =1 ;j <= length ;j++){
            if(j-widths[i-1] < 0 ){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j-widths[i-1]]+values[i-1],dp[i-1][j]);
            }
        }
    }
    return dp[size][length];

}

string Core(string str){
    int n = str.size();
    string res;
    for(int i =0 ;i <n ;i+=2){
        char  p = str[i];
        int num = p-'0';

        for(int i=0 ;i < num ;i++){
            res +=str[i+1];
        }
    }
    return res;
}

int main(int argc, char* argv[] ){
    string str;

    string res = Core(str);
    cout <<res<<endl;
    return 0 ;
}


