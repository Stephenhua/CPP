#include <vector>
#include <iostream>
#include <string>

using namespace std;
vector<int> bubbleSort(vector<int> arr){

    int size=arr.size();
    if(size==0){
        return arr;
    }
    for(int i=1;i<size;i++){//往返的次数；
        for(int j=0;j<size-i;j++){//数组中的排序的次数；与往返的次数相关
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}

//测试代码
void Test(vector<int> arr ,vector<int> arr_sort){
    vector<int> temp=bubbleSort(arr);
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<endl;
    }
    int size=temp.size();
    int number=0;
    /*
    for(vector<int>::iterator iter1=temp.begin(),iter2=arr_sort.begin();iter1!=temp.end(),iter2!=arr_sort.end();iter1++,iter2++)
    {
        if(*iter1 ==*iter2){
            number++;
            cout<<*iter1<<"  "<<*iter2<<endl;
        }
        cout<<*iter1<<endl;
    }/*/
    for(int i=0;i<size;i++){
        if(temp[i]==arr_sort[i]){
            number++;
            cout<<temp[i]<<"  "<<arr_sort[i]<<endl;
        }
    }
    if(number==size){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    vector<int> arr={1,5,2,3,6};
    vector<int> arr_sort={1,2,3,5,6};
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

int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    system("pause");
    return 0;
}
