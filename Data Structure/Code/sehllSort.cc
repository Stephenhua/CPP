#include <vector>
#include <iostream>
#include <string>

using namespace std;

//直接插入法，只是插入的间隔发生了变化；
void InsertI(vector<int> & arr, int gap,int i){
    int inserted=arr[i];
    int j;
    for(j=i-gap;j>=0&& inserted<arr[j];j-=gap){
        arr[j+gap]=arr[j];
    }
    arr[j+gap]=inserted;
}

//希尔进行划分；
void shellSort(vector<int>&  arr){
    int size=arr.size();
    for(int gap=size/2;gap>0;gap/=2){
        for(int i=gap;i<size;i++){
            InsertI(arr,gap,i);
        }
    }
}


//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){
   shellSort(arr);
    int size=arr.size();
    int number=0;
    for(int i=0;i<size;i++){
        if(arr[i]==arr_sort[i]){
            number++;
            cout<<arr[i]<<"  "<<arr_sort[i]<<endl;
        }
    }
    if(number==size){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
    Test(arr,arr_sort);
}

void Test2(){
    vector<int> arr={};
    vector<int> arr_sort={};
    Test(arr,arr_sort);

}
void Test3(){
    vector<int> arr={1};
    vector<int> arr_sort={1};
    Test(arr,arr_sort);
}
void Test4(){
    vector<int> arr={6,72,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
    Test(arr,arr_sort);
}
int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    Test4();
    system("pause");
    return 0;
}
