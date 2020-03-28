//旋转数组的步骤
//采用两个指针进行，实分别放到前面和最后，利用二分法实现。
//特殊情况：
//第一：当不需要旋转的时候，则，直接领indexMin = index1;
//第二：如果出现重复的数字，时，即左中右都相等，则需要使用顺序选择；

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;
int MinOrder(int* numbers, int index1, int index2);
int Min(int *numbers ,int length){

    if(numbers==nullptr||length<=0){
        logic_error ex("Invalid parameters");
        throw new std::exception(ex);
    }

    int index1=0;
    int index2=length-1;
    int indexMid=index1;

    while(numbers[index1]>=numbers[index2]){
        if(index2-index1==1){
            indexMid=index2;
            break;
        }
        indexMid=(index1+index2)/2;

        if(numbers[index1]==numbers[index2]&&numbers[indexMid]==numbers[index1]){
            return MinOrder(numbers,index1,index2);
        }

        if(numbers[indexMid]>=numbers[index1]){
            index1=indexMid;
        }else if(numbers[indexMid]<=numbers[index2]){
            index2=indexMid;
        }

    }
    return numbers[indexMid];
}

int MinOrder(int *numbers ,int index1,int index2){
    int reslut=numbers[index1];
    for(int i=index1+1;i<=index2;++i){
        if(reslut>numbers[i]){
            reslut=numbers[i];
        }
    }
    return reslut;
}


int findMin(vector<int>& arr){
    int size=arr.size();
    if(size==0){
        cout<<"No number"<<endl;
        logic_error ex("Invalid parameters");
        throw new std::exception(ex);
    }
    int start=0;
    int end=size-1;
    int mid;
    while (start+1<end)
    {
        mid=start+((end-start)>>1);
        if(arr[mid]<arr[end]){
            end=mid;
        }
        else if(arr[mid]>arr[end])
        {
            start=mid;
            /* code */
        }else{
            --end;
        }     
    }  
    if(arr[start]<arr[end]){
        return arr[start];
    }
    return arr[end];   
}

void Test(int *numbers, int length ,int expected){
    int reslut=0;
    try{
        reslut=Min(numbers,length);

        for(int i=0;i<length;i++){
            printf("%d",numbers[i]);
        }
        if(reslut==expected){
            printf("\tpassed \n");
        }else{
            printf("\tfailed\n");
        }
    }
    catch(...){
        if(numbers==nullptr){
            printf("Test passed \n");
        }else{
            printf("Test failed\n");
        }
    }
}

void Test1(vector<int>& arr, int minValue){
    int reslut=0;
    try{
        reslut=findMin(arr);
        cout<<"Result:"<<reslut<<endl;
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<endl;
        }
        if(reslut==minValue){
            printf("\tpassed \n");
        }else{
            printf("\tfailed\n");
        }
    }
    catch(...){
        if(arr.size()==0){
            printf("Test passed \n");
        }else{
            printf("Test failed\n");
        }
    }

}

int main(int argc,int *argv[]){
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);
    vector<int> array11={ 3, 4, 5, 1, 2 };
    Test1(array11,1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    vector<int> array22={ 3, 4, 5, 1, 1, 2 };
    Test1(array22,1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    vector<int> array33={ 3, 4, 5, 1, 2, 2 };
    Test1(array33,1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    vector<int> array44={ 1, 0, 1, 1, 1 };
    Test1(array44,0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);
    
    vector<int> array55={ 1, 2, 3, 4, 5 };
    Test1(array55,1);


    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);
    
    vector<int> array66={ 2};
    Test1(array66,2);

    // 输入nullptr
    Test(nullptr, 0, 0);
    vector<int> array77={ };
    Test1(array77,0);

    system("pause");

    return 0;
}