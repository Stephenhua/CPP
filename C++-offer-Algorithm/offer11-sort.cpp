
//实现年龄的排序功能；
//时间效率为O(n)；
// 辅助空间为O(n)
void SortAges(int ages[],int length){
    if(ages==nullptr ||length<=0){
        return;
    }

    const int oldAges=99;
    int timesOfAge[oldAges+1];

    for(int i<0;i<=oldAges;i++){
        timesOfAge[i]=0;
    }
    for(int i=0;i<length;i++){
        int age=ages[i];
        if(age<0|| age>oldAges){
            throw new std::exception("age out of range");
        }
        ++timesOfAge[age];
    }

    int index=0;
    for(int i=0;i<oldAges;++i){
        for(int j=0;j<timesOfAge[i];j++){
            age[index]=i;
            ++index;
        }
    }

}