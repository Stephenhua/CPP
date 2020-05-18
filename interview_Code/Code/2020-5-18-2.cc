#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include <algorithm>
using namespace std;
vector<string> res;
vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void  DFS( vector<string>& res,  string str, string& digits ,int i ){
    //进行回溯的出口，
    if( i >= digits.size()){
        if( str.size()>0){
            res.push_back(str);
        }
        return;
    }else{
        //用于找出表中数字对应的位置；
        string s = table[digits[i]-'2'];
        //对S位置的字符串进行循环遍历，枚举元素的值；
        for( int j = 0 ; j<s.size() ;j++){
            str.push_back(s[j]);
            //压入一个之后，进行下一个字符求和；
            DFS(res,str,digits,i+1);

            //当回溯结束之后，然后将其弹出来，进行状态还原；
            str.pop_back();
        }
    }
}

vector<string> CompareFind(vector<string>& res, vector<string>& dict){
    vector<string> value;
    vector<string>::iterator Iter;
    for( int i = 0 ; i <res.size() ;i++){
        string temp = res[i];
        Iter = find(dict.begin(),dict.end(),temp);
        if( Iter != dict.end()){
            value.push_back(*Iter);
        }
    }
    return value;
}
void PrintCode(vector<string>& result){
    for(int i =0 ;i < result.size() ;i++){
        cout << result[i] << endl;
    }
}
int main (){
    int m ;
    cin >> m ;
    vector<string> dict;
    while( m--){
        string dict_string;
        cin >> dict_string;
        dict.push_back(dict_string);
    }

    string input;
    while( cin >> input){
        //将输入的数字进行组合；
        DFS( res, "" ,input , 0);
        //将子典和里面的值进行比较；如果符合，则输出，
        vector<string> result =CompareFind(res,dict);
        PrintCode(result);
    }
    return 0 ;
}

