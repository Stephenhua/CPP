#include <iostream>
#include <vector>

using namespace std;

class Sigletion{
    private:
        Sigletion(){
            cout<<"Sigletion()" <<endl;
        }

        static Sigletion * instance ; // 静态成员，指向sigletion对象的指针；

    public:


	//提供静态共有方法，可以使用类名加域名进行访问，返回对象指针；

        static Sigletion* GetSigletion(){
            return instance;
        }
};

Sigletion * Sigletion::instance = new Sigletion;


int main()
{
    cout << "main begin:"<<endl;

    Sigletion* ptr = Sigletion::GetSigletion();

    Sigletion* ptr2 = Sigletion::GetSigletion();

    if( ptr == ptr2){
        cout<<"yes"<<endl;
    }else{

        cout<< "no" <<endl;
    }

    cout<<"End"<<endl;
    system("pause");
    return 0 ;
}
