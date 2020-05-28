#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
LRU (Least recently used) 最近最少使用，如果数据最近被访问过，那么将来被访问的几率也更高。
LFU (Least frequently used) 最不经常使用，如果一个数据在最近一段时间内使用次数很少，那么在将来一段时间内被使用的可能性也很小。
FIFO (Fist in first out) 先进先出， 如果一个数据最先进入缓存中，则应该最早淘汰掉。
如何缓存数据？
1）插入一个新的节点时，由于很快会用到，则将其插入到链表头部
2）每当缓存命中（即缓存数据被访问），则将数据移到链表头部
3）当链表满的时候，将链表尾部的数据丢弃

LRU Cache具备的操作：
1）set(key,value)：如果key在hashmap中存在，则先重置对应的value值，然后获取对应的节点cur，将cur节点从链表删除，并移动到链表的头部；若果key在hashmap不存在，则新建一个节点，并将节点放到链表的头部。当Cache存满的时候，将链表最后一个节点删除即可。set(key,value)：如果key在hashmap中存在，则先重置对应的value值，然后获取对应的节点cur，将cur节点从链表删除，并移动到链表的头部；若果key在hashmap不存在，则新建一个节点，并将节点放到链表的头部。当Cache存满的时候，将链表最后一个节点删除即可。
2）get(key)：如果key在hashmap中存在，则把对应的节点放到链表头部，并返回对应的value值；如果不存在，则返回-1。

实现步骤：
LRU实现采用双向链表 + Map 来进行实现。map进行查找，效率为O(1)；利用list实现插入、删除效率最高；
采用双向链表的原因是：如果采用普通的单链表，则删除节点的时候需要从表头开始遍历查找，效率为O(n)，采用双向链表可以直接改变节点的前驱的指针指向进行删除达到O(1)的效率。使用Map来保存节点的key、value值便于能在O(logN)的时间查找元素,对应get操作。

存储的功能：
双向链表用于存储数据结点，并且它是按照结点最近被使用的时间来存储的。
1）
*/
struct CacheNode{
    int key ;
    int value ;

    CacheNode* pre,*next;//节点的前驱、后继指针
    CacheNode(int k ,int v):key(k),value(v),pre(NULL),next(NULL) { }
};
//LRUCache 构造函数的大小；
class LRUCache{
    private:

    int m_capacity;
    CacheNode* head;//指向头结点
    CacheNode* tail;//指向尾部；
    map<int, CacheNode*> mp;

    public:

    //构造函数；
    LRUCache( int capacity){
        int size = capacity;
        head = nullptr;
        tail = NULL;
    }

    //析构函数
    ~LRUCache(){
        map<int, CacheNode*>::iterator it = mp.begin();
        for( ;it!=mp.end();){
            delete it->second;
            it->second = nullptr;
            mp.erase(it++);//其他形式的迭代器会导致失效；
        }

        delete head;
        head = nullptr;
        delete tail;
        tail =nullptr;
    }
    //删除一个节点；
    void Remove( CacheNode* pNode){
        //如果删除节点位于头节点；
        if( pNode->pre == nullptr){
            head = pNode->next;
            head->pre = nullptr;
        }

        //如果删除是尾结点；

        if( pNode->next == nullptr){
            tail = pNode->pre;
            tail->next = nullptr;
        }else{
            pNode->pre->next = pNode->next;
            pNode->next->pre = pNode->pre;
        }
        

    }

    //将节点放在头部，最近用过的数据需要放在列表头结点；
    void  setHead( CacheNode* pNode){

        pNode->next = head;
        pNode->pre = nullptr;

        if( head == nullptr){
            head = pNode;
        }else{

            head->pre = pNode;
            head = pNode;
        }

        if(tail == nullptr){
            tail = head;
        }
        
        
    }

    //插入数据，如果存在就只更新数据；

    int Set( int key ,int value ){

        map<int,CacheNode*>::iterator it ;
        it = mp.find(key);

        if( it != mp.end()){
            
            CacheNode* Node = it->second;
            Node->value = value;

            Remove(Node);
            setHead(Node);
        }else{
            CacheNode* newNode = new CacheNode(key,value);

            if( mp.size() >= m_capacity){

                it = mp.find( tail->value);
                Remove(tail);
                //
                delete it->second;
                mp.erase(it);
            }

            setHead(newNode);
            mp[key] = newNode;
        }
    }

    //获取缓存里面的数据
    int Get( int  key){
        map<int,CacheNode*>::iterator it ;

        it = mp.find(key);

        if( it != mp.end()){
            CacheNode* node = it->second;
            Remove(node);
            setHead(node);
            return node->value;
        }else{
            return -1;
        }
    }

    //或取整个内存大小；
    int getSize(){
        return mp.size();
    }
};

int main( int argc ,char* argv[]){

    LRUCache* lruCahe = new LRUCache(3);
    lruCahe->Set(1,1);
    lruCahe->Set(2,2);

    cout<< lruCahe->getSize() <<endl;

    lruCahe->Set(3,5);
    cout<<lruCahe->getSize() <<endl;

    cout<<lruCahe->Get(2)<<endl;

    lruCahe->Set( 6,3);

    cout << lruCahe->getSize() <<endl;

    cout<< lruCahe->Get(1)  <<endl;
    cout<< lruCahe->Get(2) <<endl;
    cout <<lruCahe->Get(3) <<endl;

    system("pause");
    return 0;
}