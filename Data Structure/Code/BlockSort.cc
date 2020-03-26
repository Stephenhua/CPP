#include <vector>
#include <algortithm>
#include <list>
#include <iostream>

using namespace std;

struct iNode{
    int m_data;  //块中对大的元素
    int m_pointer;//指针下标
};

void blockSort(iNode *index, int *arr ,int n,int key){
    //对索引表进行二分查找；
    int low =0;
    int high=m-1;
    int mid=0;

    while(low<=high){
        mid= (low+high)/2;
        if(key <= index[mid].m_data){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    int aind=index[mid].m_pointer;
    bool ex= false;

    while(arr[aind]<=index[mid].m_data && aind!=n){
        if(key== arr[aind]){
            cout<<"数组中第"<< aind+1 <<" 个数据元素与关键字"<<key <<"相匹配"<<endl;
            ex=true;
            ++aind;
            continue;
        }
        ++aind;
    }
    if(ex=false){
        cout<<"数组中存在的元素不匹配"<<endl;
    }
}