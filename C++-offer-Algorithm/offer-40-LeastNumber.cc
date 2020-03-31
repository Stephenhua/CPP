/*
关键字：最小的k个数、快速排序法、测试代码
https://blog.csdn.net/qq_36528114/article/details/78667034

*/

#include <cstdio>
#include "Array.h"
#include <set>
#include <vector>
#include <isotream>
#include <functional>

using namespace std;


//快速排序法

//=====================================
//左右值指针法,把最后的一个单独预留出来，然后最后进行交换值
//=======================================
int PartSort(int *array ,int left ,int right){
    int& key = array[right];
    while(left<right){
        while(left<right&& array[left]<=key){
            ++left;
        }
        while (left<right&& array[right]>=key)
        {
            /* code */
            --right;
        }
        swap(array[left],key);        
    }

    swap(array[left],key);
    return left;
}
//============================================
//挖坑法：进行天坑处理,首先进行左边处理，然后进行右边处理；当右边处理结束后，然后进行左边结束；
//
//============================================

int PartSort(int *array ,int left ,int right){
    int key=array[right];
    while(left<right){
        while (left<right&&array[left]<=key)
        {
            ++left;
        }
        array[right]=array[left];
        while(left<right&& array[right]>=key){
            --right;
        }
        array[left]=array[right];
        
    }
    array[right]=key;
    return right;

}

// ==============================================================
//前后指针法，
//============================================================

int PartSort(int *array ,int length,int start ,int end ){
    if(array==nullptr||length<=0||start<=0||end<=0){
        return ;
    }
    int index=RandomInRange(start,end);
    swap(&data[index],&date[end]);
    int small=start-1;
    for(index=start,index<end;index++){
        if(data[index]<data[end]){
            ++small;
            if(small!=index){
                swap(array[index],&array[small]);
            }

        }
    
    }
    ++small;
    swap(&data[small],&data[end]);
    return small;
}

void QuickSort(int data[],int length ,int start ,int end){
    if(start==end){
        return ;
    }
    int index=PartSort(data,length,start,end);
    if(index>start){
        QuickSort(data,length,start,index-1);
    }else{
        QuickSort(data,length,index+1,end);
    }
}

//方法一：采用先排序，然后进行选择，这样的复杂度为O(nlong(n))
vector<int> GetSolutions_1(vector<int> input,int k){
    vector<int> res;
    if(input.size()<k){
        return res;
    }

    sort(input.begin(),input.end());
    for(int i=0;i<k;i++){
        res.push_back(input[i]);
    }

    return res;
}


//方法二：采用快速排序的方法，该方法的好处是处理速度快，时间复杂度为O(n)，但是不适用于大量的数据处理,同时需要修改原来数组的值

void GetLeastNumber(int * input ,int n ,int *output, int k){
    if(input==nullptr|| n<=0||output==nullptr||k<=0||k>n){
        return ;
    }

    int start =0;
    int end= n-1;
    int index= partition(input,n,start,end);
    while(index!=k-1){
        if(index>k-1){
            end= index-1;
            index=partition(input,n,start,end);
        }else
        {
            start=index+1;
            index=partition(input,n,start ,end);
        }
    
    }

    for(int i=0;i<k;++i){

        output[i]=input[i];

    }
}

//方法三:采用红黑树的形式，时间复杂度为O(n long k),适合处理复杂大量的数据，
/*
具体实施步骤
1）在k个数中找到最大数
2）有可能在这个容器中删除最大数
3有可能要插入一个新的数字
*/

typedef multist<int, greater<int>>  intSet;
typedef multist<int, greater<int>>::iterator setIterator;

void GetLeastsNumbers(const vector<int>&data, intSet& LeastNumber,int k){
    leastNumbers.clear();
    if(k<1|| data.size()<k){
        return;
    }

    vector<int>::const_iterator iter=data.begin();
    for(;iter!=data.end();++iter){
        if((LeastNumber.size()<k)){
            LeastNumber.insert(*iter);
        }else{
            setIterator iterGreatest=LeastNumber.begin();
            ig(*iter<*(LeastNumber.begin()))
            {
                LeastNumber.erase(iterGreatest);
                LeastNumber.insert(*iter);  
            }
        }
    }
}
//方法四：采用的冒泡排序方法进行求解；
vector<int> GetLeastNumber_Solutions(vector<int> input,int k){
    vector<int> res;
    if(input.size()<k){
        return res;
    }

    for(int i=k;i<input.size();++i){
        for(int j=0;j<k;++j){
            if(input[j]>input[i]){
                int temp=input[j];
                input[j]=input[i];
                input[i]=temp;
            }
        }
    }

    for(int i=0;i<k;++i){
        res.push_back(input[i]);
    }
    return res;
}
