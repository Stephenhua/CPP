#include <vector>
#include <iostream>
#include <string>

using namespace std;

void  InsertSort(vector<int>& temp){
    for(int i=1;i<temp.size();i++){
        int key=temp[i];
        int j=i-1;
        while(j>=00&& key<temp[j]){//替换前n-1个值
            temp[j+1]=temp[j];
            j--;
        }
        temp[j+1]=key;//将值插入到j+1de位置，大于J位置上的值；
    }
}

//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){
    InsertSort(arr);
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
