#include <iostream>

using namespace std;
/*
class cSignalPartern{
    private:
        cSignalPartern(){
            cout <<" new create"<<endl;
        }
        cSignalPartern(const cSignalPartern& );
        cSignalPartern& operator=(const cSignalPartern& );

        ~cSignalPartern(){
            cout <<" Destroy new"<<endl;
        }


    public:
        static cSignalPartern* getInstance(){
            static cSignalPartern myInstance;//单例对象创建；
            return &myInstance;
        }
};


int main(int argc ,char*argv[] ){
    cSignalPartern* ct1 = cSignalPartern::getInstance();
    cSignalPartern* ct2 = cSignalPartern::getInstance();
    cSignalPartern* ct3 = cSignalPartern::getInstance();
    system("pause");
    return 0 ;
}

*/

class CSingleton
{
private:
    CSingleton()
    {
    }
    static CSingleton *p;
public:
    static CSingleton* getInstance()
    {
        if(p == NULL)
            p = new CSingleton();
        return p;
    }
};
CSingleton* CSingleton::p = NULL;
int main()
{
    CSingleton *t = CSingleton::getInstance();
    CSingleton *tt = CSingleton::getInstance();
    cout << t << endl << tt << endl;
    system("pause");
    return 0;
}