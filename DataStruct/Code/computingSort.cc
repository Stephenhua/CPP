#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;

vector<int> countSort(vector<int>& arr, int lenght){


    if( lenght <=0){
        return arr;
    }

    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<lenght;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    vector<int > temp(max+1,0);
    vector<int> temp1(arr);
    /*
    for(int i=0;i<d;i++){
        temp[i]=0;
    }
*/
    // 遍历数组，统计每个数出现的次数
    for(int i=0;i<lenght;i++){
        ++temp[arr[i]];
    }

    //数组变形后，后面的元素等于前面元素的和；
    for(int i=1;i<=max;++i){
        temp[i]+=temp[i-1];
    }

    //倒叙数组变模型，从统计数组中找出正确的位置输出结构；


    for(int i=lenght-1;i>=0;--i){
        arr[temp[temp1[i]]-1]=temp1[i];
        temp[arr[i]]--;
    }
    return arr;
}



//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){

    int size=arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

   vector<int > temp=countSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    int number=0;
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
