#include<iostream>
#include <cstdio>
#include<vector>
#include <cmath>
#include "memory.h"
#include "assert.h"
using namespace std;

/*
实验目的：通过重载new和delete，
*/

class Test{
    //存储在静态区中Test对象的最大数量
    static const unsigned int COUNT=4;
  //用于存储Test对象的静态内存区，注意为static变量
    static char c_buff[];
    //用于标识内存空间的使用情况
    static char c_map[];
    public:
    void* operator new(std::size_t size){
        void * ret=NULL;
        for(int i=0;i<COUNT ;i++){
            c_map[i]=1;
            ret=c_buff+i*sizeof(Test);
            cout<<"Success to allocate memory"<<ret<<endl;
            break;
        }
        return ret;//当返回后，编译器继继会生成调用构造函数来初始化
                    //这片内存空间的代码。
    }
    void operator delete(void* p){
        if(p!=nullptr){
            char* mem=reinterpret_cast<char*>(p);
            int index=(mem-c_buff)/sizeof(Test);
            int flag=(mem-c_buff)%sizeof(Test);

            if((flag==0)&&(0<=index)&& (index<COUNT)){
                c_map[index]=0;
            }
            cout<<"succed to free memory"<<p<<endl;
        }
        //函数返回后，编译器自动生成调用析构函数的代码

    }

};

char Test::c_buff[sizeof(Test) * Test::COUNT] = {0};
char Test::c_map[Test::COUNT] = {0};


int main()
{
    cout << "===== Test Single Object =====" << endl;
    
    Test* pt = new Test; //相当于(Test*)Test::operator new(sizeof(Test));
    delete pt;
    
    cout << "===== Test Object Array =====" << endl;
    Test* pa[5] = {0};
    
    //模拟内存管理，因内存区最多只能分配4个Test对象，当申请第5个对象
    //时，会返回NULL。这个例子也可结合二阶构造来生成《多例模式》
    for( int i=0; i<5; i++)
    {
        pa[i] = new Test;
        cout << "pa[" <<i <<"] = " << pa[i] << endl;
    }
    
    //释放
    for( int i=0; i<5; i++)
    {
        cout << "delete " << pa[i] << endl;
        delete pa[i];
    }
    system("pause");
    return 0;
}