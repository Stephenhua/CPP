#include <memory.h>
#include <vector>
#include <iostream>

#define BYTESIZE 8

using namespace std;

void SetBit(char *p, int posi){

    for(int i= 0; i<(posi/BYTESIZE);i++){
        p++;
    }

    *p = *p | (0x01 << (posi%BYTESIZE));//将该bit设置为1；
    return ;
}

void BitmapSortDemo(vector<int>& num ){

    const int BufferLen = 2;

    char* pBuffer = new char[size];
//要将所有的Bit位置为0，否则结果不可预知
    memset( pBuffer, 0, BufferLen);

    for( int i =0 ;i< 9;i++){
//首先将相应Bit位上置为1
        SetBit( pBuffer, num[i]);
    }

    for(int i =0 ;i<BufferLen ;i++){//每次处理一个字节(Byte)

        for(int j= 0; j<BYTESIZE; j++){//处理该字节中的每个Bit位

			//判断该位上是否是1，进行输出，这里的判断比较笨。
			//首先得到该第j位的掩码（0x01＜＜j），将内存区中的
			//位和此掩码作与操作。最后判断掩码是否和处理后的
            // 结果相同
            
            if((*pBuffer& (0x01 <<j)) == (0x01 <<j)){
                cout <<" value "<< i*BYTESIZE+j<<endl;
            }
        }
        pBuffer++;
    }

}

int main(int argc, char* argv[]){

    vector<int> nums = {3,5,2,10,6,12,8,14,9};

    //int size = nums.size() * BYTESIZE;

    BitmapSortDemo(nums);

    system("pause");
    
    return 0 ;

}