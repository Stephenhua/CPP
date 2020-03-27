#include <vector>
#include <iostream>
#include <string>

using namespace std;

int Quick_Sort(vector<int>& array,int left, int right){

    if(left<right){
        int key=array[right];
        int cur=left;
        int pre=cur-1;
        while (cur<=right){
            while(array[cur]<key&& ++pre!=cur){
                swap(array[cur],array[pre]);
            }
            ++cur;
        }
        swap(array[++pre],array[right]);
        return pre;
    }
    return -1;

}


void Quicksort(vector<int> & temp,int left,int right){

    if(temp.size()==0 || left>right){
        return;
    }

    int div=Quick_Sort(temp,left,right);
    Quicksort(temp,left,div-1);
    Quicksort(temp,div+1,right);

}



void QuickSort_1(vector<int> & arr){
    int size=arr.size();
    int left=0;
    int right=size-1;
    Quick_Sort(arr,left,right);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

}

//测试代码
void Test(vector<int>& temp ,vector<int>& arr_sort){
    QuickSort_1(temp);
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
