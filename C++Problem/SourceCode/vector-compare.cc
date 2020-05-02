#include <vector>
#include <iostream>
#include <algorithm>

using namespace  std;

struct TItem{
    int num ;
    int Id;

    bool operator< (const TItem& rhs) const{
        return num < rhs.num;
    }

    bool operator >( const TItem& rhs) const
    {
        return num > rhs.num;
    }
};

int main(){
    vector<TItem> st;
    TItem a1;
    a1.num =2; 
    a1.Id =1;

    TItem a2;
    a2.Id = 2;
    a2.num = 5;

    TItem a3;

    a3.Id = 3;
    a3.num =1;

    st.push_back(a1);
    st.push_back(a2);
    st.push_back(a3);

    sort(st.begin() , st.end() , less<TItem>());

    for (int i = 0; i < st.size(); i++)
    {
        cout <<" Id "<<st[i].Id <<" num" <<st[i].num <<endl;
        /* code */
    }
    

    sort(st.begin() , st.end() , greater<TItem>());

    for (int i = 0; i < st.size(); i++)
    {
        cout <<" Id "<<st[i].Id <<" num" <<st[i].num <<endl;
        /* code */
    }

    system("pause");
    return 0 ;
    
}