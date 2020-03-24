#include <vector>
#include <iostream>
#include <string>

using namespace std;
int PatrSort(vector<int> &temp,int left, int right){
    int & key= temp[right];
    while(left<right){
        while(left<right && temp[left]<=key){
            ++left;
        }
        while(left<right && temp[right]>=key){
            right--;
        }
        swap(temp[left],temp[right]);
    }
    swap(temp[left],key);
    return left;
}

void Quick_Sort(vector<int>& arr,int left,int right){
    if(left>=right){
        return;
    }
    int index=PatrSort(arr,left,right);
    Quick_Sort(arr,left,index-1);
    Quick_Sort(arr,index+1,right);
}
void QuickSort(vector<int> & arr){
    int size=arr.size();
    int left=0;
    int right=size-1;
    Quick_Sort(arr,left,right);

}

//测试代码
void Test(vector<int>& temp ,vector<int>& arr_sort){
    QuickSort(temp);
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
