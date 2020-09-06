#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc ,char* argv[]){
    int n,p,q;
    cin >> n >> p >>q;
    vector<int> a(p,0);
    vector<int> b(q,0);
    int resa =0;
    int resb = 0 ;
    int resc =0;

    for(int i =0 ;i < p ;i++){
        cin >>a[i];
    }

    for(int i =0 ;i < q ;i++){
        cin >>b[i];
    }

    vector<int>::iterator Ita;
    vector<int>::iterator Itb;

    for(int i =1 ;i <=n ;i++){
        Ita = find(a.begin(),a.end(),i);
        Itb = find(b.begin(),b.end(),i);

        if( Ita != a.end() && Itb != b.end()){
            resc++;
        }else if( Ita != a.end() && Itb==b.end()){
            resa++;
        }else if( Ita==a.end() && Itb != b.end()){
            resb++;
        }
    }

    cout << resa << resb <<resc << endl;
    system("pause");
    return 0 ;
}


int main(int argc ,char* argv[]){
    int n,p,q;
    cin >> n >> p >>q;
    set<int> a(p,0);
    set<int> b(q,0);
    int resa =0;
    int resb = 0 ;
    int resc =0;

    for(int i =0 ;i < p ;i++){
        int temp = 0 ;
        cin >>temp;
        a.insert(temp);
    }

    for(int i =0 ;i < q ;i++){
        int temp =0 ;
        cin >>temp;
        b.insert(temp);
    }

    for(auto i : a){
        if(b.find(i) != b.end()){
            resc++;
        }
    }
    resa = a.size() - resc;
    resb = b.size() - resc;

    cout << resa << resb <<resc << endl;
    system("pause");
    return 0 ;
}