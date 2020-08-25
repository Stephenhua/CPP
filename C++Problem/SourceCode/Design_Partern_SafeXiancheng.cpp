#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

class Singlton{
    protected:
        Singlton(){
            pthread_mutex_init(&mutex,NULL);
            cout << "Create new object  "<<endl;
        }
    private:
        static Singlton* p;
    public:
        static pthread_mutex_t mutex;
        static Singlton* instance();
};

pthread_mutex_t Singlton::mutex;
Singlton* Singlton::p = nullptr;
Singlton* Singlton::instance(){
    if( p == nullptr){
        //加锁
        pthread_mutex_lock(&mutex);
        if( p == nullptr ){
            p = new Singlton();
        }
        pthread_mutex_unlock(&mutex);
    }
    return p ;
}

int main(int argc, char*argv[]){
    Singlton* ct1 = Singlton::instance();
    Singlton* ct2 = Singlton::instance();

    system("pause");
    return 0 ;
}