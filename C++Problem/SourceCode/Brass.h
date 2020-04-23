#ifndef BRASS_H_
#define BRASS_H_

#include <string.h>
#include <iostream>

using namespace std;

class Brass{
    private:
        string fullname ;
        long accNum ;
        double balance ;
    public:
        Brass(const string& s ="Nullbody" , long an =-1 ,double bal = 0.0);
        void Deposit(double amt);

        virtual void Withdraw(double amt);

        double Balance() const ;

        virtual void ViewAcct() const ;

        virtual ~Brass(){};

};

class BrassPluss :public Brass{
    private:
        double maxLoan ;
        double rate ;
        double owesBank ;

    public:
        BrassPluss( const string& s = "Nullbody" ,long an =-1 ,double bal =0.0 ,double ml =500 , double r = 0.11125);
        
        BrassPluss(const Brass& ba ,double ml =500 , double r = 0.11125);

        virtual void ViewAcct() const ;

        virtual void Withdraw( double amt);

        void ResetMax( double m) { maxLoan = m;}

        void ResetRaet(double r ){ rate = r ;}

        void ResetOews() {owesBank = 0 ;}
};
#endif