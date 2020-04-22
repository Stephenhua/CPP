#include <iostream>
#include <stack>
using namespace std;

const int Defaultsize = 100;



template<class T>
class MinHeap{
    public:

    MinHeap( int sz = Defaultsize);
    MinHeap( T arr[] , int n);
    ~MinHeap(){ delete[] heap;}

    bool Insert( const T & x);

    bool Remove();

    bool isEmpty() const;

    bool isFull() const ;

    void PreOrder();

    private:

    T *heap;
    int CurrentSize;

    void shiftDown(int start , int m);

    void shiftUp (int start) ;

};

//构造函数
template<class T>
MinHeap<T>::MinHeap(int sz){
    heap = new T[sz];
    CurrentSize = 0;
}

//复制构造函数；
template<class T>
MinHeap<T>::MinHeap( T arr[] , int n ){
    
    heap = new T[Defaultsize];
    CurrentSize = n ;
    for(int i=0 ;i< n ;i++){
        heap[i] = arr[i];
    }

    int CurrentPos = (CurrentSize-2)/2;

    while(CurrentPos>=0){
        //从下到上逐渐扩大，形成堆；
        shiftDown( CurrentPos, CurrentSize-1);
        //到currentSize-1为止；
        CurrentPos--;
    }
}

//向下调整
//m表示长度；
template<class T>
void MinHeap<T>::shiftDown( int start  ,int m){

    int i =start ;
    int lChild = 2*i+1;
    int RChild = 2* i +2;

    T temp = heap[i];

    while( lChild <= m ){

        if(lChild < m && heap[lChild] > heap[lChild+1]){
            lChild++;//选两字子女进行比较；
        }
        //当父节点比孩子节点小时，则执行下面的语句；
        if( temp <= heap[lChild]){
            break;
        }else{
            heap[i] = heap[lChild];
            i = lChild ;
            lChild = 2* i +1;
        }
    }
    heap[i] = temp ;
}

//向上调整；
template<class T>
void MinHeap<T>::shiftUp(int start){
    
  // 从start开始，直到0或者当前值大于双亲结点的值时，调整堆
    int j =start ,i =(j-1)/2;

    T temp = heap[j];

    while(j>0){
        //父节点小于两个自己节点；
        if(heap[i] <= temp){
            break;
        }else{
            heap[j] = heap[i];
            j  = i;
            i = ( j-1)/2;
        }
    }
    heap[j] = temp;
}

//堆插入
template< class T>
bool MinHeap<T>::Insert(const T &x){
    if(CurrentSize == Defaultsize){
        cout<<"heap is full"<<endl;
        return false ;
    }

    heap[CurrentSize] = x;

    shiftUp(CurrentSize);

    CurrentSize++;

    return true;
}

//删除堆
template<class T>
bool MinHeap<T>::Remove(){
    int x; 
    if(!CurrentSize){
        cout<<"heap is empty"<<endl;
        return false;
    }
    x = heap[0];//最小元素出列；
    heap[0] = heap[CurrentSize-1];//使用最后一个元素进行填充；
    CurrentSize--;
    shiftDown(0 , CurrentSize-1);//从0的位置开始调整
    return true;

}

//判断堆是否为空
template<class T>
bool MinHeap<T>::isEmpty() const {
    if(!CurrentSize){
        return true;
    }
    return false;
}

//判断是否为已满
template<class T>
bool MinHeap<T>::isFull() const {
    if(CurrentSize == Defaultsize){
        return true;
    }
    return false;
}


//前序遍历
template<class T>
void MinHeap<T>::PreOrder(){
    std::stack<int> s;
    int i ;
    i = 0;
    while( i<CurrentSize || !s.empty()){
        while( i < CurrentSize){
            cout<<"heap"<<heap[i]<<" ";
            s.push(i);
            i= 2*i +1;
        }

        if(!s.empty()){
            i = s.top();
            s.pop();
            i= 2*i+2;
        }
    }
}

int main(int argc, char * argv[]) {
    
    int finished, choose, x, len;
    
    int arr[] = {9, 17, 65, 23, 45, 78, 87, 53};
    
    len = sizeof(arr) / sizeof(arr[0]);
    
    finished = 0;
     MinHeap<int> h = MinHeap<int>(arr, len);

     while(!finished) {
         std::cout << "\n*************菜单*************\n";
        std::cout << "1:往最小堆中插入一个值：\n";
        std::cout << "2:删除最小堆中的最小值\n";
         std::cout << "3:判断最小堆是否为空\n";
         std::cout << "4:判断最小堆是否已满\n";
         std::cout << "5:前序遍历最小堆\n";
        std::cout << "6:退出\n";
        std::cout << "请输入你的选择[1-6]:";
        std::cin >> choose;
        switch(choose) {
            case 1:
              std::cout << "请输入要插入的值:";
              std::cin >> x;
              h.Insert(x);
               break;
            case 2:
              h.Remove(); // 删除最小值
                break;
            case 3:
                if(h.isEmpty())
                    std::cout << "最小堆为空！\n";
                else
                     std::cout << "最小堆不为空！\n";
                break;
            case 4:
                if(h.isFull())
                    std::cout << "最小堆已满\n";
                else
                    std::cout << "最小堆还没满!\n";
                break;
            case 5:
                std::cout << "最小堆的数据为：\n";
                h.PreOrder();
                 std::cout << std::endl;
                break;
            case 6:
                 finished = 1;
                 break;
            default:
                 std::cout << "选择输入错误，请重新输入！\n";
        } // switch
    } // while
    system("pause");
    return 0;
}