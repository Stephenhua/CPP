#include <iostream>
#include <vector>

using namespace std;

class SignalPattern{

    private:
        SignalPattern(){
            cout<<" Sigletion2" <<endl;
        }

        static SignalPattern * instance ;
    
    public:
        static SignalPattern* GetSignal(){

            if(instance == nullptr ){
                cout<<"It is once "<<endl;

                instance = new SignalPattern();
            }else{

                cout<<"It is not once "<< endl;
            }
            return instance ;
        }
};
//初始化时，为空， 等到真正用的时候再用这个单例模式进行创建；
SignalPattern * SignalPattern::instance = nullptr ;
int main()
{
    cout << "main begin:"<<endl;

    SignalPattern* ptr = SignalPattern::GetSignal();

    SignalPattern* ptr2  = SignalPattern::GetSignal();

    if( ptr == ptr2){
        cout<<"yes"<<endl;
    }else{

        cout<< "no" <<endl;
    }

    cout<<"End"<<endl;
    system("pause");
    return 0 ;
}
