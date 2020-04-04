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
    int samllest=i;//先设置一个根节点，左子树、右子树以及下标；
    if(lChild <len&& arr[samllest]>arr[lChild]){
        samllest=lChild;
    }
    if(rChild <len && arr[samllest]<arr[rChild]){
        samllest=rChild;
    }

    if(largst!=i){
        swap(arr[i],arr[samllest]);
        Heap_build1(arr,samllest,len);//递归调用，保证子树也是最小根；
    }
}
void buildMinHeap1(vector<int>& arr,int len){
    for(int i=len/2;i>=0;i--){

        Heap_build1(arr,i,len);

    }
}
void Heap_Sort(vector<int>& arr, int len){

    buildMaxHeap1(arr,len);//首先构建最大堆；

    for(int i=len-1;i>0;i--){
        // 将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递减序列
        swap(arr[0],arr[i]);
     // 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。       
        Heap_build1(arr,0,i);
    }
}

//利用堆排序实现从n个数字中找出前top-k大的数字

void TheNTheKth(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        if(i>k-1){//当值大于k-1的时候，直接进行堆排序；
            int temp;
            cin>>temp;
            if(temp>arr[0]){
                arr[0]=temp;
                Heap_build1(arr,0,k-1);
            }
        }else
        {
            //构建堆排序；
            int temp;
            cin>>temp;
            arr[i]=temp;
            if(i==k-1){
                buildMinHeap1(arr,i);
            }
            /* code */
        }
        
    }

    //对最小堆中的值进行最小堆排序；
    Heap_Sort(arr,0,k-1);

    //打印节点
    for(int i=0;i<arr.size();i++){
        cout<<arrr[i];
        if(i<arr.size()-1){
            cout<<" ";
        }
    }

    system("pause");
}