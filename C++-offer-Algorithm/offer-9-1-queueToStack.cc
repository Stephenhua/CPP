#include "offer-9-1-queueToStack.h"

//测试代码
void Test(char artual ,char expected){
    if(artual==expected){
        cout<<"Test passed"<<endl;
    }
    else{
        cout<<"Test Failed"<<endl;
    }
}

int main(int argc ,char * argv[]){
    CStack<char> my_stack;
    my_stack.push1('a');
    my_stack.push1('b');
    my_stack.push1('c');

    char head=my_stack.pop1();
    Test(head,'a');
    head=my_stack.pop1();
    Test(head,'b');

    my_stack.push1('d');
    head=my_stack.pop1();
    Test(head,'c');

    my_stack.push1('e');
    head = my_stack.pop1();
    Test(head, 'd');

    head = my_stack.pop1();
    Test(head, 'e');

    system("pause");
    return 0;

}