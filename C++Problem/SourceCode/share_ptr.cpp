#include <vector>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main( int argc ,char * argv[]){
    int a = 10 ;
    std::shared_ptr<int> ptra = std::make_shared<int>(a); //make_sahred进行初始化对象；然后并继续拧复制shared_ptr 
    std::shared_ptr<int> ptra2(ptra) ;//拷贝；
    std::cout << ptra.use_count() <<endl;

    int b = 20 ;
    int *pb = &a ;
    std::shared_ptr<int> ptrb = std::make_shared<int> (b);//不能使用原始指针初始化智能指针；
    ptra2=ptrb;//赋值；
    pb = ptrb.get();//获得原始指针；

    std::cout <<ptra.use_count() << endl;
    std::cout <<ptrb.use_count() << endl;

    system("pause");
    return 0;
}
