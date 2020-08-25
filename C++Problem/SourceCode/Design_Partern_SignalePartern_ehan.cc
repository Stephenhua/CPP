#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

class Singelton{
    private:
        Singelton(){
            m_count++;
            printf("Signelton begin\n");
            Sleep(100);
            cout <<"Signelton end \n"<<endl;
        }
        static Singelton *single ;//单例生成；
    public:
        static int m_count ;
        static Singelton * GetSingelton(){
            /*
            if( single == nullptr){
                single = new Singelton;
            }*/
            return single;
        }
        static void print(){
            cout<< m_count <<endl;
        }
};

int Singelton::m_count = 0 ;
Singelton *Singelton::single = new Singelton;
//回调函数
void threadFunc( void *p){
    DWORD id = GetCurrentThreadId();
    cout << id <<endl;
    Singelton::GetSingelton()->print(); // 构造函数并获得实例，调用静态成员函数
}

int main ( int argc ,char*argv[] ){
    int threadNum = 3 ;
    HANDLE threadHd1[100];

    //创建三个进程；
    for(int i = 0 ; i< threadNum ;i++){
        threadHd1[i] = (HANDLE)_beginthread(threadFunc,0,nullptr);
    }

    //让主进程等待所有的线程结束后在退出；
    for(int i = 0 ;i < threadNum ;i++){
        WaitForSingleObject(threadHd1[i],INFINITE);
    }

    cout <<"main"<<endl;
    system("pause");
    return  0 ;
}