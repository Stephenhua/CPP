//STL 标准库
// 主要函数：reverse

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
template<class BidirIt>
void reverse1(BidirIt first, BidirIt last){
    while((first!=last)&&(first!==--last)){
        std::iter_swap(first++,last);
    }
}

int main(){
    vector<int>  v{1,2,3};
    reverse1(v.begin(),v.end());
    for(auto e:v){
        cout<<e<<endl;
    }

    int a[]={4,5,6,7};
    reverse1(begin(a),end(a));
    for(auto e:a){
        cout<<e<<endl;
    }
}
