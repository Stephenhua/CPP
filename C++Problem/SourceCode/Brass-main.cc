#include <iostream>
#include "Brass.h"
using namespace std;

int main (){
    
    Brass Piggy("procelot Pigg" , 2381299 , 4000.00);
    BrassPluss Hoggy("Horation Hogg" ,382288 ,3000.00);
    Piggy.ViewAcct();
    cout<<endl;
    Hoggy.ViewAcct();
    cout<<endl;

    cout<<"Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);

    cout<<"New Balance:$" <<Hoggy.Balance() <<endl; 

    cout<<" Withdrawin $4200 from the pigg Account :\n";
    Piggy.Withdraw(4200.00);

    cout<<"Pigg account balance： $" <<Piggy.Balance() <<endl ;

    cout<<"Withdrawing $4200 from the Hogg Accout :\n";

    Hoggy.Withdraw(4200.00) ;

    Hoggy.ViewAcct();
    system("pause");
    return 0;
}