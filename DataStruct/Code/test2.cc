#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main (){
    int a,b ,m ,x;
    cin >> a >> b >> m >> x ;
    vector<int> temp;
    int value =m ;
    if(( a >=1 && b>=1 && x>=1 && m >= 1)&&(a<=m && b<=m && x <=m) &&(m<=100000))
    {
        while(value>=0){
            x = (a*x +b ) % m;
            temp.push_back(x);
            value--;
        }
        cout << "hello"<<endl;
        int count = 0 ;
        map<int,int> result;
        int size= temp.size();
        int i=0;
        while( i < size){
        
           if(result[temp[i]] == 0){
                count++;
                result[temp[i]]++;
            }else{
                return count;
                break;
            }
            i++;

        }
    }
    return 0;
}