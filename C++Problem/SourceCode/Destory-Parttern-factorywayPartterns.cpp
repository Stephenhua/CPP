#include <iostream>
using namespace std;


/*

工厂方法模式；

*/
//创建车类；
class Car{
    public:
        virtual void createCar(void) = 0;
};

class BenzCar:public Car{
    public:
        BenzCar(){
            cout << "Benz::Benz()"<<endl;
        }

        virtual void createCar(void ){
            cout <<"Benz::createCar()" <<endl;
        }

        ~BenzCar(){

        }
};

class BmwCar : public Car{
    public:
        BmwCar(){
            cout << "BmwCar::BmwCar()"<<endl;
        }

        virtual void createCar(void){
            cout <<"BmwCar::createCar()"<<endl;
        }

        ~BmwCar(){

        }
};

//工厂
class Factory{
    public:
        virtual Car* createSpecificCar(void ) = 0;
};

class BenzFactory:public  Factory{
    public:

    virtual Car* createSpecificCar(void ){
        return (new BenzCar());
    }
};


class BmwFactory: public Factory{
    public:
    
    virtual Car* createSpecificCar(void ){
        return (new BmwCar());
    }

};

int main( int argc ,char * argv[] ){
    Factory* factory = new BenzFactory();
    Car* specificCarA = factory->createSpecificCar();

    factory = new BmwFactory();
    Car* specificCarB = factory->createSpecificCar();

    delete factory;
    delete specificCarA;
    delete specificCarB;

    system("pause");
    return 0 ;
}