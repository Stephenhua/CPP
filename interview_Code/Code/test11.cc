#include <queue>
#include <string.h>
#include <iostream>

using namespace std;
/*
题目：
输入样例：
第一行输入样例数T，之后每个样例，先输入操作数Q，然后进行"PUSH", "TOP", "POP", "SIZE","CLEAR"五种操作。
输出样例：
"TOP"输出队头元素，队伍空返回-1；"POP"失效时输出-1。
*/
int main (){
    int T;
    cin >>T ;


    while(T>0){
        int Q ;
        cin >>Q ;
        while(Q>0){
            
            queue<int> temp_queue;

            string s; 

            cin >>s ;

            if( s == "PUSH"){

                int i ;
                cin >>i ;
                temp_queue.push(i);

            }else if( s == "TOP"){
                if(temp_queue.empty()){
                    cout << "-1" <<endl;
                }
                cout << temp_queue.front() <<endl;

            }else if( s == "SIZE"){

                cout<<temp_queue.size()<<endl;

            }else if( s == "POP"){
                if(temp_queue.empty()){
                    cout << "-1" <<endl;
                }
                temp_queue.pop();
            }else if( s == "CLEAR")
            {
                while( !temp_queue.empty()){
                    temp_queue.pop();
                }
                 
            }
            Q--;
        }

        T--;
    }
    system("pause");
    return 0 ;
}