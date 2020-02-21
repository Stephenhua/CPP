#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
using namespace std;

/*
主题：数组中的逆序数
方法：采用规避排序的思想进行求解
逆序数的总数=左边数组的逆序数的数量+右边数组的逆序数的数量+左右结合的新的顺序数组时出现的逆序对的数量

算法：归并排序+递归的思想
当前数组的逆序=左逆序—+右逆序+合并的值；
而这个当前的数组可能是比他大的数组的的左逆序得值，所以需要加上终止条件
*/

class Solutions{
    public:
    int InversePairs(int *data,int length){
        if(data==nullptr||length<0){
            return 0;
        }
        int *copy= new int[length];
        for(int i=0;i<length;i++){
            copy[i]=dara[i];
        }
        int count= InversePairsCore(data,copy,0,length-1);
        delete[] copy ;
        return count;
     }

     int InversePairsCore(int *data,int *copy ,int start ,int end){

         //递归调用的终止条件
         if(start==end){
             copy[start]=data[start];
             return 0;
         }

         int length=(start+end)/2;

         //表示单独求解排好序的逆序数组
         int left=InversePairsCore(copy,data,start,start+length);
         int right=InversePairsCore(copy,data,start+length+1,end);

         //i为初始化前半段最后一个数字的下标
         int i =start +length;

         //j为初始化后半段最后一个数字的下表
         int j =end ;

         int indexCopy=end;

         int count =0 ;
         while(i>=start&&j>start+length+1){
             if(data[i]>data[j]){
                 copy[indexCopy--]=data[i--];//表示进行好的序
                 count+=j-start-length;
             }else{
                 copy[indexCopy--]=data[j--];
             }
         }

         for(;i>=start;--i){
             copy[indexCopy--]=data[i];
         }

         for(;j>=start+length;--j){
             copy[indexCopy--]=data[j];
         }

         return left+right+count;
     }

};