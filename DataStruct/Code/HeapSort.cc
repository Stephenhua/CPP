#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
using namespace std;

//将i节点为根的堆中小的数依次上移,n表示堆中的数据个数
void Heap_build1 (vector<int>& arr,int i,int len){
    int lChild=2*i+1;
    int rChild=2*i+2;
    int largst=i;//先设置一个根节点，左子树、右子树以及下标；
    if(lChild <len&& arr[largst]<arr[lChild]){
        largst=lChild;
    }
    if(rChild <len && arr[largst]<arr[rChild]){
        largst=rChild;
    }

    if(largst!=i){
        swap(arr[i],arr[largst]);
        Heap_build1(arr,largst,len);//递归调用，保证子树也是最大根；
    }
}
void buildMaxHeap1(vector<int>& arr,int len){
    for(int i=len/2;i>=0;i--){

        Heap_build1(arr,i,len);

    }
}
void Heap_Sort(vector<int>& arr, int len){

    buildMaxHeap1(arr,len);//首先构建最大堆；

    for(int i=len-1;i>0;i--){
        // 将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列,index = 0 的话，那么就是表根堆顶；
        swap(arr[0],arr[i]);
     // 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。       
        Heap_build1(arr,0,i);
    }
}


//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){
    int size=arr.size();
    Heap_Sort(arr,size);
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
