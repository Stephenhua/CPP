#include <vector>
#include <iostream>
#include <algorithm>

using namespace  std;

//vector自定义比较函数:方法三：函数对象

struct Item{
    int Id ;
    int num ;
};

class Compless{
    public:
        bool operator()( const Item& s1, const Item& s2){
            return s1.num < s2.num ;
        }
};

class Compgreater{

    public:
        bool operator() ( const Item& s1, const Item& s2){
            return s1.num > s2.num ;
        }
};

int main(){
    vector<Item> st;
    Item a1;
    a1.num =2; 
    a1.Id =1;

    Item a2;
    a2.Id = 2;
    a2.num = 5;

    Item a3;

    a3.Id = 3;
    a3.num =1;

    st.push_back(a1);
    st.push_back(a2);
    st.push_back(a3);

    sort(st.begin() , st.end() ,Compless());//升序

    for (int i = 0; i < st.size(); i++)
    {
        cout <<" Id "<<st[i].Id <<" num" <<st[i].num <<endl;
        /* code */
    }
    

    sort(st.begin() , st.end() , Compgreater() );//降序；

    for (int i = 0; i < st.size(); i++)
    {
        cout <<" Id "<<st[i].Id <<" num" <<st[i].num <<endl;
        /* code */
    }

    system("pause");
    return 0 ;
    
}