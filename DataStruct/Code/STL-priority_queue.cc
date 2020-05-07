#include<iostream>

#include<algorithm>

#include<vector>
#include <queue>
using namespace std;


void buildPriorityQueueMinHeap(){
    priority_queue<int ,vector<int> , greater<int>> q;

    for(int i =0 ;i<10 ;i++){
        q.push(10-i);
    }

    while( !q.empty()){
        cout << q.top() <<endl;
        q.pop();
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pair_q;
    pair<int,int> a(3,4);
    pair<int,int> b(3,5);
    pair<int,int> c(4,3);    
    pair_q.push(a);
    pair_q.push(b);
    pair_q.push(c);

    while( !pair_q.empty()){
        cout << pair_q.top().first <<"  "<<pair_q.top().second <<endl;
        pair_q.pop();
    }


}
int main( int argc, char* argv){

    priority_queue<pair<int,int>> arr ;

    pair<int ,int > a1(1,2);

    pair<int, int> a2(5,3);

    pair<int,int> a3( 2,4);

    pair<int,int> a4(3,1);

    arr.push(a1);
    arr.push(a2);
    arr.push(a3);
    arr.push(a4);

    while(!arr.empty()){
        cout <<" index" <<arr.top().first <<arr.top().second<< endl;
        arr.pop();
        cout << "size" << arr.size() << endl;
    }

    buildPriorityQueueMinHeap();

    system("pause");
    return 0 ;
 
}