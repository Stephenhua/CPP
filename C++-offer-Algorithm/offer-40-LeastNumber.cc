#include <cstdio>
#include "Array.h"
#include <set>
#include <vector>
#include <isotream>
#include <functional>

using namespace std;

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