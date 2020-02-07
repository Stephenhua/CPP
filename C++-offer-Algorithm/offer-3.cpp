
#剑指offer第三题，关于查找数组中的重复的数字
# 时间复杂复杂度O(n),空间复杂复O(1)
# 操作步骤：
# If 首先比较这个数字（用m表示）是不是等于 i，如果是，则直接扫描下一个数字；如果不是，则在拿他和第m个数字进行比较，如果他和第m个数字相等，就找到一个重复的数字；
#如果他和第m个数字不相等，就把第i个数字和第m个数字进行交换，把m放到属于它的位置。

bool duplicate (int numbers[],int length ,int *duplicate)
{
    if(numbers==nullptr ||length<0)
    {
        return false;
    }

    for(int i =0;i<length;i++){
        if(numbers[i]<0||numbers[i]>length-1)
        {
            return false;
        }
    }

    for(int i =0;i<length;i++){
        while(numbers[i]!=i){
            if(numbers[i]==numbers[numbers[i]])
            {
                *duplicate=numbers[i];
                return true;
            }
            int temp=numbers[i];
            numbers[i]=numbers[temp];
            numbers[temp]=temp;
        }
    }
}

# 题目二：不修改数组找出重复的数字
# 不改变原有数组的顺序，重新建立排序表

# 思路一：引入辅助空间进行求解，然后将原数组的元素进行比较、如果原数组中被复制的数字是m,则把它复制到辅助数组中下标为m的位置。

int getDupiucate(const int *numbers, int length){
    unorder_map<int,int > temp_Value;
    if (numbers == nullptr || length <0){
        return -1;
    }
    for(int i=0;i<length;i++){
        temp_Value[numbers[i]]++;
        if(temp_Value[numbers[i]]>1){
            return numbers[i]
        }
    }
}

#思路二：采用二分法查找的思路，如果输入长度为n的数组，那么函数countRange将会被调用O(long n) 次，每次需要的时间为O(n)。整个程序的时间复杂度为O(long n ) ,空间复杂复位O(1)；
if getDupiucate(const int *numbers , int length){
        if (numbers == nullptr || length <0){
        return -1;
    }
    int start =1;
    int end = length -1 ;
    while(end >= start){
        int middle =((end-start)>>1)+start;
        int count = countRange(numbers ,lenght, start, middle);
        if(end== start){
            if(count>1){
                return start;
            }
            else {
               break;
            }
        }
        if(count> (middle -start +1)){
            end=middle;
        }else{
            start = middle =1；
        }
        return -1;
    }
}

int countRange(const int * numbers , int length ,int start ,int end ){
    if(numbers == nullptr){
        return 0;
    }
    int count =0;
    for (int i=0;i<length;i++){
        if(numbers[i]>=start && numbers[i]<=end){
            count++;
        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    return count;
}