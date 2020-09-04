#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
using namespace std;
int main( int argc ,char * argv[] ){

    std::unique_ptr<int> up1(new int (11));//无法进行复制的unique_ptr;
    //std::unique_ptr<int> up2 = up1; // 错误不能通过编译
    std::cout << *up1 << endl;//11;

    std::unique_ptr<int> up3 = std::move(up1); // 现在p3是数据的唯一的unique_ptr
    cout << *up3 << endl;
    //cout << *up1 << endl;//查看当前的指针是否有值
    up3.reset();//显示释放内存；
    up1.reset();//不会出错；
    //cout << *up3 << endl; //运行时错误，空指针；

   std::unique_ptr<int> up4(new int(22));   // 无法复制的unique_ptr
    up4.reset(new int(44));  // "绑定"动态对象
    std::cout << *up4 << std::endl; // 44
 
    up4 = nullptr; // 显式销毁所指对象，同时智能指针变为空指针。与up4.reset()等价
 
    std::unique_ptr<int> up5(new int(55));
    int *p = up5.release(); // 只是释放控制权，不会释放内存
    std::cout << *p << std::endl;
    // cout << *up5 << endl; // err, 运行时错误，不再拥有内存
    delete p; // 释放堆区资源


    system("pause");
    return 0 ;
}