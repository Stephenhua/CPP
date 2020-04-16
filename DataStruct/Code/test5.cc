#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int a, b ;
    cin >> a ;
    vector<int> temp;
    int temp1;
    for(int i=0;i< a; i++){
        cin >>temp1;
        temp.push_back(temp1);
    }

    for(int i=0;i<a;i++){
        cout<< temp[i]<<" ,";
    }
    cout <<endl;
    system("pause");
    return 0;
}