#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
//关键字：组合、全排序、字典序列算法、总结 、对面和相等的正方体
//本题思路，https://blog.csdn.net/darlingwood2013/article/details/90243937
//首先将整个字符串分为两部分，第一个字符为第一部分，第二部分为剩余的部分，
//然后在此基础上，将第一个字符与它后面的字符进行交换，从而得到第二个字符

void Permutation(char * pStr, char * pBegin);

void Permutation(char * pStr){
    if(pStr==nullptr){
        return ;
    }

    Permutation(pStr,pStr);
}

void Permutation(char* pStr ,char* pBegin){
    if(*pBegin=='\0'){
        printf("%s\n",pStr);
    }else{
        for(char* pCh =pBegin;*pCh!='\0';++pCh){
            char temp=*pCh;
            *pCh=*pBegin;
            *pBegin=temp;

            Permutation(pStr,pBegin+1);
            //这部分的交换是为了复位，防止其他分支交换时受到相应的影响
            temp=*pCh;
            *pCh=*pBegin;
            *pBegin=temp;
        }
    }
}

// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr ==nullptr){
        printf("Test for nullptr begins:\n");
    }else{
        printf("Test for %s begins:\n",pStr);
    }

    Permutation(pStr);

    printf("\n");
}



//字符串的字母进行组合

//采用的方法进行递归实现 
//从头扫描字符串得到第一个字符，针对第一个字符，有两种选择
//把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
//如果不把这个字符放到组合中去，则需要在剩下的n-1个字符中选取m个字符 

void Coombination(char * string ,int number ,vector<char>& result){
    if(number==0){
        vector<char>::iterator iter=result.begin();
        for(;iter<result.end();++iter){
            cout<<(*iter);
        }

        cout<<endl;
        return ;
    }

    if(*string=='\0'){
        return ;
    }
    result.push_back(*string);
    Coombination(string+1,number-1,result);//把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
    result.pop_back();
    Coombination(string+1,number,result);//如果不把这个字符放到组合中去，则需要在剩下的n-1个字符中选取m个字符 

}

void Combination(char* string){
    if(string==nullptr){
        return ;
    }

    int length=strlen(string);
    vector<char> result;
    for(int i=1;i<=length;i++){
        Coombination(string,i,result);
    }
}


int main(int argc, char *argv[]){
    Test(nullptr);

    char string1[]="";
    Test(string1);

    char string2[]="a";
    Test(string2);

    char string3[]="ab";
    Test(string3);

    char string4[]="abc";
    Test(string4);

    char s[]="abcd";
    Combination(s);
    system("pause");
    return 0;
}

//==============================================================
//全排列：https://blog.csdn.net/GetterAndSetter/article/details/81516259
//==================================================================
/*
什么是全排列？就是从n个数字中选择n个数字按照一定的顺序排列起来。
本文要讨论的算法要完成的任务是：给定一个数组，输出其所有的全排列结果。要求可以概括为两点：
1、输出该数组所有的全排列结果
2、任意两个全排列是不同的，即任意两个全排列中n个数字排列的顺序不能相同

核心思想就是枚举数组中每个位置的数字，而难点就是如何有序地枚举数组每个位置的数字而做到既全面又不重复。
1）首先我们以这个数组为a={1,2,3}为例，要找到它所有的全排列，这里我们用a[0],a[1],a[2]来表示这个数组中的第一、第二、第三个位置的数值，当前的数组各个位置的值为a[0]=1,a[1]=2,a[2]=3。于是算法可以分为以下几步来完成：
2）对a[0]的位置用1,2,3分别来替换，得到3个子序列
3）由于a[0]位置能取的所有的值的情况已经枚举完毕了，所以我们再对这3个子序列中a[1]位置所有能取的值再进行枚举。
到这里时，所有的子序列a[0]和a[1]都已经确定了，所以a[2]就自然已经确定了，只需要输出即可。
3、要明白这个算法的思想，只需要明白每一层递归在做的事：就是在不断地划分子序列，直到不能再划分为止，就可以输出该数组的值----即当子序列长度为1时，该子序列就不能再往下划分了。

在这里要注意几点：
（1）由于递归的特性，是层层往下走，只有走到某个分支的末尾（我们叫做递归的出口）时才停止，然后再回溯（就是回到上一层），并把上一层的各个分支走完，再逐步往回走，所以结合输出结果和图示我们就可以知道，程序实际上在按从左到右一个分支一个分支地来走的。
（2）这里的例子目的只是为了说明其算法思想，所以比较简单，但是我们的目的是可以对任意长度的数组进行全排列，只要明白这个算法的思路，就可以实现。我们暂时不考虑数组里面元素重复的情况，这其实可以先去重再用这个方法来实现。
（3）这个例子可以帮我们理解递归的思想，但是递归的空间开销较大，所以使用递归的时候要注意有出口而且深度不要太深。

*/

//伪代码
Permutation(m,n){
    if：全排列中只有一个数，输出排列；
    else:
        for(int i=m;i<n;i++){//i遍历地m~n个数，每次以a[i]所存的数值为打头的数
            swap(a[m],a[i]);//把第一个数放在最开始的位置
            Permutation(m+1,n);//递归；
            swap(a[m],a[i]);//为避免重复排序，每个数打头结束后恢复初始排序，防止重复的方法很多，

        }
}

void Permutation(int a[],int m,int n){
    if(m==n){
        cout<<a[0];
        for(int i=1;i<n;i++){
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
    else {
        for(int i=m;i<n;i++){
            int temp=a[m];
            a[m]=a[i];
            a[i]=temp;
            Permutation(a,m+1,n);
            temp=a[m];
            a[m]=a[i];
            a[i]=temp;
        }
    }
}





//===========================================================

//方法三：采用STL中的next_permutation()函数进行全排列
//算法algorithm的库中包含；
//============================================================

void stl_Permutation(int a[],int n){
    int b[n];
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    sort(b,b+n);
    do{
        cout<<b[0];
        for(int i=1;i<n;i++) cout<<" "<<b[i];
        cout<<endl;
    }while(next_permutation(b,b+n));
}


//总结
/*
在处理元素相同情况时，字典序算法不会重复输出。
而一开始给出的递归算法会重复（要使之不重复，应在交换之前判断相邻着的两个数是否相同，如果相同，则不交换）。
但是字典序算法把原来数组改变了，若需要保留原数组可以拷贝一个数组b，在新数组内操作。

*/

void swap(int *a ,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


/*
判断是否有符合条件的排列，如果有的话，则打印出来
*/

bool CubVertex(int *A ,int len, int begin ){
    if(A==nullptr||len!=8){
        return false;
    }

    bool result =false;

    if(bgein=len-1){
        if(A[0]+A[1]+A[2]+A[3]==A[4]+A[5]+A[6]+A[7]&&A[0]+A[2]+A[4]+A[6]==A[1]+A[5]+A[3]+A[7] &&
		A[0]+A[1]+A[4]+A[5]==A[2]+A[3]+A[6]+A[7])
        {
            int i;
            for(int i=0;i<len;i++){
                printf("%d",A[i]);
            }
            printf("\n");
            reslut=true;
        }
    }else{
        int i;
        for(i=begin;i<len;i++){
            swap(&A[begin],&A[i]);
            result=CubVertex(A,len,begin+1);//如果通过全排列找到的话，就将其挑选出来。
            if(result){
                break;
            }
            swap(&A[begin],&A[i]);
        }
    }
    return result;
}