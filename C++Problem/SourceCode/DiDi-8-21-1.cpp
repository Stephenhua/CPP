#include<iostream>
#include <vector>

using namespace std;

int main(int argc,char*argv[]){
    
    int n ;
    cin >>n ;
    vector<vector<int>> res;

    for( int a =0 ; a<=9; a++){
        for(int b = 0 ; b <= 9 ; b++){
            if(a==b){
                continue;
            }
            for(int c = 0 ; c<= 9 ; c++){
                if( a==c || b==c ){
                    continue;
                }

                int num1 = a*100+b*10+c*1;
                int num2 = a*100 +c*10+c*1;
                if( num1 < 100 || num2 < 100 ){
                    continue;
                }
                if(num1 +num2 == n ){
                    vector<int> temp;
                    temp.push_back(num1);
                    temp.push_back(num2);
                    res.push_back(temp);
                }
            }
        }
    }

    cout << res.size()<<endl;
    for(int i =0 ;i <res.size() ;i++){
        cout << res[i][0]<<" "<<res[i][1]<<endl;
    }
    system("pause");
    return 0 ;
}
