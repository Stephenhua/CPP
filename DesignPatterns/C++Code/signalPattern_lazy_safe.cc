#include <iostream>
#include <vector>

using namespace std;

class Signaletion{
    private:
    Signaletion(){
        pthread_mutex_init(&mutex);
    }

    static Signaletion* p ;
    static pthread_mutex_t mutex;

    public:
        static Signaletion* initance(){
            if( p == nullptr){

                pthread_mutex_lock(&mutex);

                if( p == nullptr){

                     p = new Signaletion();
                }

                pthread_mutex_unlock(&mutex);
            }

            return p ;
        }
};

pthread_mutex_t Signaletion::mutex;

Signaletion * Signaletion::p = nullptr;

