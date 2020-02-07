//该部分主要对sTL 标准库中的函数尽心分析和描述，以求解不同的函数
//sort函数对于数组规模的大小不同，采用的排序测略也不相同，
/*数据量大时采用QuickSort快排算法，分段归并排序。
一旦分段后的数据量小于某个门槛（16），为避免QuickSort快排的递归调用带来过大的额外负荷，就改用Insertion Sort插入排序。
如果递归层次过深，还会改用HeapSort堆排序。
*/

#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
//插入排序解析
/*
1.从第一个元素开始，该元素可以认为已被排序；
2.取出下一个元素，在已经排序的元素序列中从后向前扫描；
3.如果该元素（已排序）大于新元素，将该元素移到下一个位置；
4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5.将新元素插入到该位置后，重复2~5
*/


void InsertionSort(int *a, int len){
    for(int i=1;i<len;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

template<class RandomAccessIterator ,class T>
inline void _linear_insert(RandomAccessIterator first , RandomAccessIterator last , T*){
    T value =*last;
    if(value< *first){//如果直接大大于第一元素，那么直接插入到最前面
        copy_backward(first,last,last+1);
        *first=value;
    }
    else{
        __unguarded_insertion_sort(last,value);

    }
}

template<class RandomAccessIterator ,class T>
void __unguarded_insertion_sort(RandomAccessIterator last , T value){
    RandomAccessIterator next=last;
    --next;
    while(value<*next){
        *last=*next;  
        last=next;  //调整迭代器
        --next;     //左移一个位置，
    }
    *last=value;  // value 的正确落脚之处；
}

//快速排序的分割函数
//其平均复杂度为O(NlogN),最坏情况达到O(N2)
//三点中值
template<class RandomAccessIteraotr,class T>
RandomAccessIterator _unguarded_partition(RandomAccessIterator first,RandomAccessIterator second,T pivot){
    while(true){
        while(*first <pivot){
            ++first;
        }
        --last;
        while(pivot<*last){
            --last;
        }

        if(!(first<last)){
            return first;
        }
        iter_swap(first,last);
        ++first;
    }
}