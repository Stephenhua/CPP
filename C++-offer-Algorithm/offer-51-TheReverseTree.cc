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
            copy[i]=data[i];
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

         int length=(end-start)/2;

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

         for(;j>=start+length+1;--j){
             copy[indexCopy--]=data[j];
         }

         return left+right+count;
     }

};

//测试代码
void Test(char * testName ,int *data,int length ,int expected){
    if(testName!=nullptr){
        cout<<"testName"<<endl;
    }
    Solutions temp;
   
    if( temp.InversePairs(data,length)==expected){
        cout<<"passed"<<endl;
    }
    else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    int data[] ={ 1,2,3,4,7,6,5 };
    int expected=3;
    Test("Test1",data,sizeof(data)/sizeof(int),expected);
}

 //递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    system("pause");
    return 0;
}