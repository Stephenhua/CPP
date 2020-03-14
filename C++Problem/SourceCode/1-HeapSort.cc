#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>

using namespace std;
void Heap_build(int A[],int i,int len){
    int lChild=2*i+1;//根节点的左节点下标
    int rChild=2*i+2;//根节点的右子树下标；
    int largest=i;//先设置根节点，左子树和右子树的下标节点；
    if(lChild<len && A[largest]<A[lChild]){
        largest=lChild;

    if(rChild<len && A[largest]<A[rChild]){
        largest=rChild;
    }

    if(largest!=i){//最大值不是父节点,则需要进行交换；
        swap(A[i],A[largest]);
        Heap_build(A,largest,len);//进行递归调用，保证子树也是最大堆；

    }
}
void buildMaxHeap(int A[],int n){//建立最大堆
    for(int i=n/2-1;i>=0;i--){
        Heap_build(A ,i ,n);
    }

}

void Heap_sort(int a[],int len){
    //先建立堆
    buildMaxHeap(A,len);
    //将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列
    for(int i=n-1;i>0;i--){
        swap(A[0],A[i]);
        Heap_build(A,0,i);

    }
}