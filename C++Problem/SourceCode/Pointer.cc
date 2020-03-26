#include <iostream>
#include <stdlib.h>    
#include <crtdbg.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory>

using namespace std;

class Test{
    private:
    string str;
    public:
    Test(string s){
        str=s;
        cout<<"Test Create\n";
    }
    ~Test(){
        cout<<"Test Delete"<<str<<endl;
    }

    string& getStr(){
        return str;
    }

    void SetStr(string s){
        str=s;
    }
    void print(){
        cout<<str<<endl;
    }
};

unique_ptr<Test> fun(){
    return unique_ptr<Test>(new Test("234"));
}

int main(){

    unique_ptr<Test> ptest(new Test("123"));//绑定动态对象
    unique_ptr<Test> ptest2(new Test("456"));

    ptest->print();
    ptest2=std::move(ptest);//转化所有权，不能进行拷贝；
    if(ptest==NULL){
        cout<<"ptest is nULL"<<endl;
    }

    Test* p=ptest2.release();//释放所有权
    p->print();
    ptest.reset(p);
    ptest->print();
    ptest2=fun();
    ptest2->print();
    system("pause");
    return 0;
}
//share—ptr;
int main()
{
    shared_ptr<Test> ptest(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    cout<<ptest2->getStr()<<endl;
    cout<<ptest2.use_count()<<endl;
    ptest = ptest2;//"456"引用次数加1，“123”销毁
    ptest->print();
    cout<<ptest2.use_count()<<endl;//2
    cout<<ptest.use_count()<<endl;//2
    ptest.reset();
    ptest2.reset();//此时“456”销毁
    cout<<"done !\n";
    return 0;
}