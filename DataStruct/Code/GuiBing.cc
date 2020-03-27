#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;

//首先讲解合并的方法：将有序数组a和有序数组b合并到c中
//其时间复杂度为O(N)
void MemeryArray(int a[],int n ,int b[],int m,int c[]){
    int i,j,k;

    i=j=k=0;
    while(i<n&&j<m){
        if(a[i]>b[j]){
            c[k++]=b[j++];
        }else
        {
            c[k++]=a[i++];
        }
        
    }

    while(i<n){
        c[k++]=a[i++];
    }

    while(j<n){
        c[k++]=b[j++];
    }
}

//步骤二：讲解归并排序的两步：分——————递归的方法，归并=====采用求和的形式

//将有序数组合并

void mergearray(int a[],int first,int mid ,int last ,int temp[]){
    int i=first,j=mid+1;
    int m=mid ,n =last;
    int k=0;

    while (i<=m&&j<=n)
    {
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
        }
    }

    while (i<=m)
    {
        temp[k++]=a[i++];
    }

    while(j<=n){
        temp[k++]=a[j++];
    }

    for(i=0;i<k;i++){
        a[first+i]=temp[i];
    }
}

//数组分开
void MergeSort(int a[],int first,int last,int temp[]){
    if(first<last){
        int mid=(first+mid)/2;
        MergeSort(a,first,mid,temp);//左边有序
        MergeSort(a,mid+1,last ,temp);//右边有序

        mergearray(a,first,mid ,last ,temp);//将两个有序数组进行合并
    }
}

bool MerageSort(int a[],int n){
    int *p=new int [n];
    if(p==nullptr){
        return false;
    }

    MergeSort(a,0,n-1,p);
    delete[] p;
    return true;
}