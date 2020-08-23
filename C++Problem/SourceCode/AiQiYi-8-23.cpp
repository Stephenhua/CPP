#include <iostream>
#include <vector>
using namespace std;


int Core(int n){
    if( n< 5 ){
        return 0;
    }else{
        int temp = n/5+Core(n/5);
        return temp;
    }
}
int main( int argc,char*argv[]){
    int n ;
    int res = 0;
    cin >> n;
    res =Core(n);
    cout<<res<<endl;
    return 0 ;

}


#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool Core(string s){
    set<pair<int,int>> ms ;
    int x =0 ;
    int y =0 ;
    ms.insert({x,y});
    for(int i=0 ;i <s.size();i++){
        if(s[i]=='N'){
            ++y;
        }
        if(s[i]=='S'){
            --y;
        }
        if(s[i]=='W'){
            --x;
        }
        if(s[i]=='E'){
            ++x;
        }
        if(ms.count({x,y})){
            return true;
        }
        ms.insert({x,y});
    }
    return false;

    set<vector<int>> path;
    vector<int> Cor={0,0};
    path.insert(Cor);

    for(int i =0 ;i < s.size();i++){
        switch (s[i])
        {
        case 'N':
            Cor[0]++;
            break;
        case 'S':
            Cor[0]--;
            break;
        case 'W':
            Cor[1]--;
            break;
        case 'E':
            Cor[1]++;
        default:
            break;
        }
        pair<set<vector<int>>::iterator,bool> pa = path.insert(Cor);
        if(!pa.second){
            return true;
        }
    }
    return false;
}

int main(int argc ,char*argv[]){
    string s;
    cin>>s;
    bool res = Core(s);
    if(res){
        cout << "True" <<endl;
    }else{
        cout <<"False" <<endl;
    }

    system("pause");
    return 0 ;
}




#include <iostream>
#include <vector>
#include <set>
#include <char>

using namespace std;

bool Core(string s){

    stack<char> t;
    for(int i = 0 ; i < s.size();i++){
        if(s[i]=='('){
            t.push(')');
        }else if(s[i] == '{'){
            t.push('}');
        }else if(s[i] == '['){
            t.push(']');
        }else{
            if(t.top!=s[i] || t.empty()){
                return false;
            }else{
                t.pop();
            }
        }
    }
    return t.empty();
}

int main(int argc ,char*argv[]){
    string s;
    cin>>s;
    bool res = Core(s);
    if(res){
        cout << "True" <<endl;
    }else{
        cout <<"False" <<endl;
    }

    system("pause");
    return 0 ;
}
