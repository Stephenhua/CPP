#include "offer-9.h"

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
    CQueue<char> queue;
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head=queue.DeleteHead();
    Test(head,'a');
    head=queue.DeleteHead();
    Test(head,'b');

    queue.appendTail('d');
    head=queue.DeleteHead();
    Test(head,'c');

    queue.appendTail('e');
    head = queue.DeleteHead();
    Test(head, 'd');

    head = queue.DeleteHead();
    Test(head, 'e');

    system("pause");
    return 0;

}