#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

int main (){
    int T;
    cin >>T ;
    queue<int> temp_queue;

    while(T>0){
        int Q ;
        cin >>Q ;
        while(Q>0){

            char oper[20] ;
            cin >>oper;

            if(strcmp( oper ,"TOP") == 0 ){
                if(temp_queue.size() == 0){
                    cout<<-1<<endl;
                }
                cout <<temp_queue.front() <<endl;
            }else if( strcmp( oper, "POP") == 0){
                if( temp_queue.size() == 0){
                    cout <<-1 <<endl;
                }
                temp_queue.pop();
            }else if( strcmp( oper, "SIZE") == 0){
                cout << temp_queue.size() <<endl;
            }else if( strcmp( oper ,"CLEAR") == 0){
                while( temp_queue.size() != 0){
                    temp_queue.pop();
                }
            }else {
                    int temp = oper[4] -'0';
                    temp_queue.push(temp);
            }

            Q --;
        }

        T--;
    }
    system("pause");
    return 0 ;
}