 
//算法一，暴力求解,空间占有率较低，但是花费时间较长

bool IsUgly(int number){

    while(number%2==0){
        number/=2;
    }
    while(number%3==0){
        number/=3;
    }

    while (number%5==0){
        number/=5;
    }
    return (number==1)?true:false;

}

int GetUglyNumber(int index){

    if(index<=0){
        return 0;
    }

    int number=0;
    int uglyNumber=0;

    while(uglyNumber<index){
        ++number;
        if(IsUgly(number)){
            ++uglyNumber;
        }
    }

    return number;
}


//采用方法二：利用空间换取时间的方法进行
/*
具体实现方法：
当前丑数是另一个丑数乘以2、3、5的结果包括1，，所以通过创建数组，里面的数字时排好序的丑数

如何生成下一个丑数？
1）考虑将某一个丑数乘以2，从而可以得到小于或者等于M的结果，由于数组是按照顺序进行的，所以首先考虑已有的数小于或者等于M的数量
2）得到大于当前丑数的第一个数 M2，M3、M5；
3）
*/
int Min(int number1,int number2 ,int number3)
{
    int min=(number1>number2)?number2:number1;
    min=(min>number3)?number3:min;
    return min;
}

int GetUglySolutions_2(int index){
    if(index<0){
        return 0;
    }

    int *pUglyNumber=new int[index];
    pUglyNumber[0]=1;
    int nextUglyIndex=1;

    int *pMility2=pUglyNumber;
    int *pMility3=pUglyNumber;
    int *pMility5=pUglyNumber;

    while(nextUglyIndex<index){

        int min=Min(*pMility2*2,*pMility3*3,*pMility5*5);
        pUglyNumber[nextUglyIndex]=min;

        while(*pMility2*2<pUglyNumber[nextUglyIndex]){
            ++pMility2;
        }

        while(*pMility3*3<pUglyNumber[nextUglyIndex]){
            ++pMility3;
        }

        while(*pMility5*5<pUglyNumber[nextUglyIndex]){
            ++pMility5;
        }

        ++nextUglyIndex;
    }

    int ugly=pUglyNumber[nextUglyIndex-1];
    delete[] pUglyNumber;
    return ugly;
}

//测试代码
void Test(int index ,int expected){
    if(GetUglySolutions_2(index)==expected){
        cout<<"Solutions passed"<<endl;
    }else{
        cout<<"Solutiions faield"<<endl;
    }

    if(GetUglyNumber(index)==expected){
        cout<<"Solutions passed"<<endl;
    }else{
        cout<<"Solutions failed"<<endl;
    }
}

int main(int argc, char *argv[]){
    Test(1,1);
    Test(2,2);
    Test(4,4);
    Test(5,5);
    Test(6,6);
    Test(7,8);
    Test(8,9);
    Test(9,10);
    Test(10,12);
    Test(11,15);

    Test(1500,859963392);

    Test(0,0);
    
    system("pause");
    return 0;
}