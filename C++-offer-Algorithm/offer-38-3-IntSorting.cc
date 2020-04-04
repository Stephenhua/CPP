#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;


void PermutationCore(vector<int> &arr,int start,int end){
    if(start == end){
        //cout<<arr[0];
        for(int i=0;i<end;i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }
    else {
        for(int i=start;i<end;i++){

            swap(arr[start],arr[i]);
            PermutationCore(arr,start+1,end);
            swap(arr[start],arr[i]);

        }
    }
}

void Permutation(vector<int>& arr){
    if(arr.empty()){
        cout<<"empty"<<endl;
    }
    int size=arr.size();
    PermutationCore(arr,0,size);
}

int main(int argc,char* argv[]){
    vector<int> test1={1,2,3};

    Permutation(test1);

    system("pause");
    return 0;
}