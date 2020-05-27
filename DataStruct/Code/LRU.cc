#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
LRU (Least recently used) 最近最少使用，如果数据最近被访问过，那么将来被访问的几率也更高。
LFU (Least frequently used) 最不经常使用，如果一个数据在最近一段时间内使用次数很少，那么在将来一段时间内被使用的可能性也很小。
FIFO (Fist in first out) 先进先出， 如果一个数据最先进入缓存中，则应该最早淘汰掉。
如何缓存数据？
1）新数据插入到链表头部
2）每当缓存命中（即缓存数据被访问），则将数据移到链表头部
3）当链表满的时候，将链表尾部的数据丢弃

LRU Cache具备的操作：
1）set(key,value)：如果key在hashmap中存在，则先重置对应的value值，然后获取对应的节点cur，将cur节点从链表删除，并移动到链表的头部；若果key在hashmap不存在，则新建一个节点，并将节点放到链表的头部。当Cache存满的时候，将链表最后一个节点删除即可。set(key,value)：如果key在hashmap中存在，则先重置对应的value值，然后获取对应的节点cur，将cur节点从链表删除，并移动到链表的头部；若果key在hashmap不存在，则新建一个节点，并将节点放到链表的头部。当Cache存满的时候，将链表最后一个节点删除即可。
2）get(key)：如果key在hashmap中存在，则把对应的节点放到链表头部，并返回对应的value值；如果不存在，则返回-1。

实现步骤：
LRU实现采用双向链表 + Map 来进行实现。
采用双向链表的原因是：如果采用普通的单链表，则删除节点的时候需要从表头开始遍历查找，效率为O(n)，采用双向链表可以直接改变节点的前驱的指针指向进行删除达到O(1)的效率。使用Map来保存节点的key、value值便于能在O(logN)的时间查找元素,对应get操作。
*/
struct CacheNode{
    int key ;
    int value ;

    CacheNode* pre,*next;//节点的前驱、后继指针
    CacheNode(int k ,int v):key(k),value(v),pre(NULL),next(NULL) { }
};
//LRUCache 构造函数的大小；
LRUCache( int capacity){
    int size = capacity;
    CacheNode * head = nullptr;
    CacheNode *tail = NULL;
}

void remove( CacheNode* node){
    if( node->pre !=nullptr){
        node->pre->next = node->next;//前驱结点的直接指向后面的节点；
    }else{
        head = node->next;
    }

    if( node->next !=nullptr){

    }
}