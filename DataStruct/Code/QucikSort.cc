#include <vector>
#include <iostream>
#include <string>

using namespace std;

void QuickSort_1_Core(vector<int>& temp,int first,int last)//需要将vector的地址进行修改，由于查找的是关于vector的位置，所以要加& 
{
    if(first<last){
    
        int left=first;
        int right=last;
        int Base_number=temp[first];
        while(left<right){
            //当右边的数大于基准数时，略过，继续向左查找
			//不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
                while(left<right && temp[right]>Base_number){//从右向左填坑，
                    right--;
                }
			//将右边小于等于基准元素的数填入右边相应位置
                temp[left]=temp[right];//进行填坑操作
			//当左边的数小于等于基准数时，略过，继续向右查找
			//(重复的基准元素集合到左区间)
			//不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
                while(left<right && temp[left]<=Base_number){//从左向右填坑
                    left++;
                }
			//将左边大于基准元素的数填入左边相应位置
                temp[right]=temp[left];

        }
		//将基准元素填入相应位置
        temp[left]=Base_number;
        //此时的left即为基准元素的位置
		//对基准元素的左边子区间进行相似的快速排序
        QuickSort_1_Core(temp,first,left-1);
        //对基准元素的右边子区间进行相似的快速排序
        QuickSort_1_Core(temp,left+1,last);       
    }else{
        //如果区间只有一个数，则返回
        return ;
    }

}
vector<int>  QuickSort_1(vector<int>& arr){
    int size= arr.size();
    int left=0;
    int right=size-1;
    QuickSort_1_Core(arr,left,right);
    return arr;
}

//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){
    vector<int> temp=QuickSort_1(arr);
    int size=temp.size();
    int number=0;
    /*
    for(vector<int>::iterator iter1=temp.begin(),iter2=arr_sort.begin();iter1!=temp.end(),iter2!=arr_sort.end();iter1++,iter2++)
    {
        if(*iter1 ==*iter2){
            number++;
            cout<<*iter1<<"  "<<*iter2<<endl;
        }
        cout<<*iter1<<endl;
    }
    */
    for(int i=0;i<size;i++){
        if(temp[i]==arr_sort[i]){
            number++;
            cout<<temp[i]<<"  "<<arr_sort[i]<<endl;
        }
    }
    if(number==size){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
    Test(arr,arr_sort);
}

void Test2(){
    vector<int> arr={};
    vector<int> arr_sort={};
    Test(arr,arr_sort);

}
void Test3(){
    vector<int> arr={1};
    vector<int> arr_sort={1};
    Test(arr,arr_sort);
}

int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    system("pause");
    return 0;
}
