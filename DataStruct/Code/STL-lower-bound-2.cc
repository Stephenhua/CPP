#include<iostream>

#include<algorithm>

#include<vector>


using namespace std;

static bool weightComp( int a, int b){
    
    return a>b;

}

int main(int argc,char*argv[])

{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(19);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(7);
    std::sort(vecInt.begin(),vecInt.end());

    for(auto itt:vecInt){
        std::cout<<itt<<endl;
    }
    
    std::vector<int>::iterator it=lower_bound(vecInt.begin(),vecInt.end(),0);
    std::cout<<"lower bound: "<< *it <<endl;
    it= upper_bound(vecInt.begin(),vecInt.end(),4);
    std::cout<<"upper bound: "<<*it<<endl;
    system("pause");
    return 0;
}