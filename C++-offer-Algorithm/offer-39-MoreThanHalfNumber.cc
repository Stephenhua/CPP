#include<cstdio>
#include <array>
#include <algorithm>
#include "array.h"

bool g_bInputInvalid =false;


//如果参数输入的是一个指针，那么判别数组则是无效的
bool CheckInvalidArray(int * numbers ,int length){
    g_bInputInvalid=false;
    if(numbers==nullptr&& length<=0){
        g_bInputInvalid=true;
    }
    return g_bInputInvalid;
}

//如果数组中的数字个数没有超过整个数组的一半，则不符合题目要求，所以要进行判断
bool CheckMoreThanHalf(int *numbers, int legnth,int number){
    int times=0;
    for(int i=0;i<legnth;i++){
        if(numbers[i]==number){
            times++;
        }
    }

    bool isMoreThanHalf=true;
    if(times*2<=legnth){
        isMoreThanHalf=false;
        g_bInputInvalid=true;
    }

    return g_bInputInvalid;
}
// 快速排序的方法进行实现

ine Partition(int data[], int length, int start ,int end ){
    if(data==nullptr||length<=0||start<0||end<0){
        throw new std::exception("Invalid Parameters");
    }

    int index=Rando
}
//====================================================
//方法一：采用快速排序的方法进行排序；
//====================================================
int MoreThanHalfNUm_Solutions(int *numbers,int length){
    
    if(CheckInvalidArray(numbers,length)){
        return 0;
    }

    int mid =length>>1;
    int start =0;
    int end =length-1;

    int index=Partition(numbers,length,start ,end);//快速排序算法
    while(index!=mid){
        if(index>mid){
            end=index-1;
            index=Partition(numbers,length,start,end);
        }else{
            start=index+1;
            index=Partition(numbers,length ,start ,end);
        }
    }
    int reslut=numbers[mid];
    if(!=CheckMoreThanHalf(numbers,length,reslut)){
        reslut=0;
    }
    return reslut;


}


//====================================================
//方法er :采用关键字值map查找；
//具体实现思路：
// 考虑在遍历数组的过程中保存两个值，一个是数组中的一个数字，一个是次数
//当遍历到下一个数字时，下一个数字与前面的数子相同时，则次数加1；
//如果与前一个数不相同时，则次数减1；
// 由于超过一半的数出现的次数要比其他数的次数多，所以要钟爱的数字肯定是最后一次把次数设置为1；
//空间复杂度为O(1)，时间复杂度为O(n)
//====================================================

int MoreThanHalfNum(int *numbers, int lenght){
    if(CheckInvalidArray(numbers,lenght)){
        return 0;
    }

    int result=numbers[0];
    int times=1;
    for(int i=1;i<lenght;++i){
        if(times==0){//比较的次数
            result=numbers[i];
            times=1;
        }
        else if(numbers[i]==result){//判断值是否相一致
            tiems++;
        }else{
            times--;
        }
    }
    
    if(!CheckMoreThanHalf(numbers,length,result)){
        return 0;
    }

    return result;
}