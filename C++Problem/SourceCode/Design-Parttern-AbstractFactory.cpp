#include <iostream>
using namespace std;

class Car{
    public:
        virtual void createCar(void) = 0 ;
};

class BenzCar : public Car{
    public:
        BenzCar(){
            cout <<"BenzCar::BenzCar()"<<endl;
        }

        virtual void createCar(void){
            cout <<"BenzCar::createCar()" << endl;
        }

        ~BenzCar(){

        }
};

class BmwCar: public Car{
    public:
        BmwCar(){
            cout <<" BmwCar::BmwCar()" <<endl;
        }

        virtual void createCar(void){
            cout <<"BmwCar::createCar()"<<endl;
        }
        ~BmwCar(){

        }
};


class HighCar{
    public:
        virtual void createHighCar(void )=0;
};

class HighBenzCar:public HighCar{
    public:
        HighBenzCar(){
            cout <<"HighCar::HighBenzCar()" <<endl;
        }
        virtual  void createHighCar(void ){
            cout <<"HighBenzCar::createHighCar()"<<endl;
        }
        ~HighBenzCar(){

        }
};


class HighBmwCar: public HighCar{
    public:
        HighBmwCar(){
            cout <<"HighBmwCar::HighBmwCar()" << endl;
        }
        virtual void createHighCar(void ){
            cout <<"HighBmwCar::createHighCar" <<endl;
        }

        ~HighBmwCar(){

        }
};

class Factory{
    public:
    virtual Car* createSpecificCar(void ) =0 ;
    virtual HighCar* createHighCar( void ) =0 ;
};


class BmwFactory : public Factory{
    public:
    virtual Car* createSpecificCar(void){
        return (new BmwCar());
    }

    virtual HighCar* createHighCar(void){
        return (new HighBmwCar());
    }
};


class BenzFactory : public Factory{
    public:
        virtual Car* createSpecificCar(void){
            return (new BenzCar());
        }

        virtual HighCar* createHighCar(void){
            return (new HighBenzCar());
        }
};

int main( int argc, char* argv[]){
    Factory* factory = new BenzFactory();
    Car* specificCar = factory->createSpecificCar();
    HighCar* specificHighCar = factory->createHighCar();
    delete factory;
    delete specificCar;
    delete specificHighCar;

    system("pause");
    return 0 ;
=- 