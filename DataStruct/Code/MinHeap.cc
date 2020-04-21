#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
using namespace std;

void MinHeap_build( vector<int>& nums, int i ,int len ){

    int lChild = 2*i+1;
    int rChild = 2 * i +2;
    int smallest = i ;

    if( lChild < len && nums[lChild] < nums[smallest]){
         smallest = lChild;
    }

    if( rChild < len && nums[rChild] < nums[smallest]){
        smallest = rChild ;
    }

    if(smallest != i){
        swap(nums[i], nums[smallest]);

        MinHeap_build( nums, smallest , len);
    }
}

void MinHeap( vector<int>& arr, int len){

    for(int i=len/2; i>=0 ; i--){
        MinHeap_build(arr, i ,len );
    }
}

void MinHe( vector<int> & nums , int len ){
    
    MinHeap(nums, len);

    for(int i =len-1 ; i>0 ;i--){

        swap( nums[0], nums[i]);

        MinHeap_build( nums, 0 ,i);
    }
}

//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){
    int size=arr.size();
    MinHe(arr,size);

    for(int i =0 ;i<arr.size() ;i++){
        cout<< "arr" <<arr[i]<<endl;
    }
    int number=0;
    cout << "Heloo"<<endl;
    for(int i=0;i<size;i++){

        //cout << "Heloo2"<<endl;
        if(arr[i]==arr_sort[i]){
            number++;
            cout<<arr[i]<<"  "<<arr_sort[i]<<endl;
        }
    }

    cout <<endl; 

    if(number==size){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={85,83,73,72,60,57,48,42,8,6};
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
