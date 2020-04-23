#include "Brass.h"
#include <iostream>
using namespace std;

typedef std::ios_base::fmtflags format ;
typedef std::streamsize precis;

format setFormat();

void restore(format f , precis p) ;


Brass::Brass(const string & s, long an , doube bal){
    
    fullname = s;
    
    accNum = an ;

    balance = bal ;
}

void Brass::Deposit(double amt){
    if(amt<0){
        cout<< "Negative depost not allowed"<<endl;
    }else{
        balance += amt;
    }
}

void Brass::Withdraw( double amt){

    format initialState = setFormat();

    precis prec = cout.precision(2);

    if(amt<0){
        cout<<"Withdrawal amount must be postive;"
    }else if( amt <= balance){
        balance -= amt ;
    }else{
        cout<<" Withdraw amount of $" <<amt <<" exceed your balance.\n";
    }

    restore(initialState,prec);
}

double Brass::Balance() const{

    return balance;

}

void Brass::ViewAcct() const{

    format initialState = setFormat() ;

    precis prec  = cout.precision(2);

    cout<<"Client:"<< fullname <<endl;
    cout<< "Account Number" << accNum <<endl;
    cout<<"Balanced :" <<balance <<endl;

    restore( initialState ,prec) ;
}


//Brassplus 
BrassPluss::BrassPluss(const string& s,  long an ,double bal ,double ml ,double r):Brass(s,an,bal){
    maxLoan = ml ;
    owesBank = 0.0 ;
    rate = r;
}

//复制构造函数
BrassPluss::BrassPluss ( const Brass& ba, double ml ,double r):Brass(ba){

    maxLoan = ml ;
    owesBank = 0.0 ;
    rate = r; 
}

void BrassPluss::ViewAcct() const{
    
    format initialState = setFormat();

    precis prec = cout.precision(2);

    Brass::ViewAcct();

    cout<<"Maxium loan :$" <<maxLoan <<endl;

    cout<<"Owed to bank :&"<<owesBank <<endl;

    cout.precision(3);

    cout<<"Loan Rate:" <<100* rate <<endl;

    restore(initialState, prec);

}

void BrassPluss::Withdraw(double amt){
    format initialstate = setFormat();

    precis prec  = cout.precision(2);

    double bal = Balance() ;

    if(amt <bal){

        Brass::Withdraw(amt);

    }else if( amt <= bal+maxLoan -owesBank){

        double advance  = amt - bal;
        owesBank += advance*(1.0+ rate);

        cout<< "Bank advance: $" << advance <<endl; 

        cout<<" Finance charge :$" << advance*rate <<endl;

        Deposit(advance) ;
        
        Brass::Withdraw(amt);
    }else{

        cout <<" Credit limit execeeded .Transaction cancelled .\n";
        restore( initialstate ,prec);
    }

}


format setFormat(){
    
    return cout.setf(std::ios_base::fixed ,std::ios_base::floatfield);
}


void restore (format f, precis p){

    cout.setf(f,std::ios_base::floatfield);
    cout.precision( p );
    
}