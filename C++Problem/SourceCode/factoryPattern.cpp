#include <iostream>
using namespace std;

enum CarType{BENZ ,BMW};

class Car{
    public:
        virtual void CreateCar(void)=0;
};

//奔驰车；
class benz : public Car{
    public:
        benz(){
            cout<< "benz::benz()"<<endl;
        }
        virtual void CreateCar(void){
            cout <<"benz::createCar" << endl;
        }

        ~benz(){

        }
};

//宝马车
class BmwCar:public Car{
    public:
        BmwCar(){
            cout <<"BmwCar::BmwCar()"<<endl;
        }

        virtual void CreateCar(void){
            cout <<"BmwCar::createCar()"<<endl;
        }
        ~BmwCar(){

        }
};

class CarFactory{
    public:
        Car* createSpecificCar(CarType type){
            switch (type)
            {
                case BENZ:
                    return ( new benz() );
                    break;
                case BMW:
                    return (new BmwCar());
                    break;
                default:
                    return NULL;
                    break;
            }
        }
};

int main(int argc ,char* argv[]){
    CarFactory carfac;
    Car* specificCarA = carfac.createSpecificCar(BENZ);
    Car* specificCarB = carfac.createSpecificCar(BMW);

    delete specificCarA;
    delete specificCarB;
    
    system("pause");
    return 0 ;
}