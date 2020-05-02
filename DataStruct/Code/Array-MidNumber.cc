#include  <vector>
#include <iostream>
using namespace std;

/*
题目：求两个长度相同的升序数组的中位数
题解：
     （1）若a=b ，则 a 或 b 即为所求的中位数，算法结束
     （2）若a<b ，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等
     （3）若a>b ，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的长度相等
      在保留的两个升序序列中，重复过程(1)(2)(3)，直到两个序列中均只含一个元素时为止，较小者即为中位数
*/

int MidSearch( vector<int>& a, vector<int>& b){
    
    int aSize = a.size();
    int bSize = b.size();

    int aStart = 0 ;
    int aEnd = aSize -1;

    int bStart = 0 ;
    int bEnd = bSize -1;

    while( aStart != aEnd && bStart != bEnd){

        int aMid = (aStart + aEnd) /2;
        int bMid =( bStart + bEnd )/2;

        if( a[aMid]  ==  b[bMid]){

            return a[aMid];
        }else if( a[aMid] > b[bMid]){

            if( (aStart +aEnd )%2== 0){

                aEnd = aMid;
                bStart = bMid;
            }else{

                aEnd = aMid;
                bStart = bMid+1;
            }
        }else if( a[aMid] < b[bMid]){

            if( (aStart +aEnd)%2 == 0){
                bEnd = bMid ;
                aStart = aMid;
            }else
            {
                bEnd = aMid;
                aStart = aMid+1;
            }
            
        }
    }

    return a[aStart] < b[bStart] ? a[aStart] : b[bStart];

}

int main ( int argc ,char* argv[]){

    vector<int> a= {1,3,5,7,9};
    vector<int> b = {2,4,6,8,10};

    int result = MidSearch(a,b);

    cout<<"Mid number" << result << endl;

    system("pause");
    return 0;
    
}