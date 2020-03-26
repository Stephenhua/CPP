#include <stdio.h>
//前后指针法
int partition(int *arr,int left, int right){
    int cur = left;                     //前指针
    int pre = cur - 1;                 //后指针
    int pos = arr[right];              //标志位
    while(cur <= right){              
        if(arr[cur] <= pos){            //前指针找比pos小的
                pre++;                      
            if(cur != pre){             //指针不同，说明一个指大数，一个指小数，交换
                int temp = arr[cur];
                arr[cur] = arr[pre];
                arr[pre] = temp;
            }
        }
        cur++;                            //找不到小的就移
    }
    return pre;
}
void quick_sort(int *arr, int left, int right){
    if(arr == NULL || left > right)
        return;
    int pos = partition(arr, left, right);
    quick_sort(arr, left, pos - 1);
    quick_sort(arr, pos+1, right);
}

