#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

/*
LRU缓存机制；
146. LRU缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

 

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

*/


/*
思想：
插入的情况讨论：
1）如果已经存在列表中，那么直接应该放在最前面的位置；
2）如果列表中不存在，那么直接插入到最前面就可以了；

获取数据：
1——如果存在了，直接返回；
2）- 如果不存在，那么应该返回-1；


数据结构：
链表+unordered_maop,时间复杂度O(1);

*/
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity){

    }
    
    int get(int key) {

        if( map.find(key) == map.end()){///时间复杂度为O(1);
            return -1;
        }

        auto key_value = *map[key];

        cache.erase(map[key]); //链表删除的时间复杂度为O(1)；
        cache.push_front(key_value);
        map[key] = cache.begin();
        return key_value.second;
    }
    
    void put(int key, int value) {

        if( map.find(key) == map.end() ){
            if( map.size() == cap ){ //如果满了。删除最后一个元素；对应的迭代器和cache；
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }else{//如果存在，先进行删除，然后进行插入到首部；
            cache.erase(map[key]);
        }

        cache.push_front( {key,value });
        map[key] = cache.begin();
        
    }
private:
    int cap ;
    list<pair<int,int>> cache; //用于存放 key =value：
    unordered_map<int ,list<pair<int,int>>::iterator> map;//存放的是链表key中对应的迭代器；
};

//方法二：通过双端链表进行实现；
class LRUCacheNaive {
    struct Node{
        int key;
        int value;
        Node* next;
        Node* former;
    };
    
    unordered_map<int,Node*> used;
    Node* head =nullptr;
    Node* last =nullptr;

    int size=0;
    int capacity;
    
public:
    LRUCacheNaive(int capacity) {
        this->capacity = capacity;

    }
    
    int get(int key) {
        auto it = used.find(key);
        if(it == used.end()) return -1;
        else{
            Node* n = it->second;
            insertToLast(n);
            return n->value;
        } 
    }
    
    void put(int key, int value) {
        auto it = used.find(key);
        if(it == used.end()){
            if(size == capacity){//如果大小到达上限
                removeHead();
            }else
                size++;

            if(!head){// 如果 没有任何内容
                head = new Node{key,value,nullptr,nullptr};
                last = head;
            }else{
                insertToLast(new Node{key,value,nullptr,nullptr});
            }
            used[key] = last;
            
        }else{
            Node* n = it->second;
            insertToLast(n);
            n->value = value;
        }
    }
    void insertToLast(Node* n){
        if(n->former != nullptr){//如果 不是最后一个
            n->former->next = n->next; 
            if(n->former == head) head = n;
        }else if(n->next){
            head = n->next;
            n->next = nullptr;
        }
        last->next = n;
        n->former = last;
        n->next = nullptr;
        last = n;
        
    }
    void removeHead(){
        Node * h = head;
        if(head == last){
            head = last = nullptr;
        }else{
            head->next->former = nullptr;
            head = head->next;
        }
        used.erase(h->key);
        delete h;
    }

};

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }