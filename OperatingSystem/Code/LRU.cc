#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
/*
实现一个LRU缓存算法
*/
using  namespace std;


struct CacheNode{
    int key;
    int value;
    CacheNode *pre;
    CacheNode *next;
    CacheNode(int k,int v):key(k),value(v),pre(nullptr),next(nullptr){ }
};

class LRUCache
{
private:
    /* data */
    int size;
    CacheNode* head;
    CacheNode* tail;
    map<int,CacheNode*> mp;
public:
    LRUCache(int capcity){
        size=capcity;
        head=nullptr;
        tail=nullptr;
    };
    ~LRUCache();

    //预备工作
    //删除结点
    void remove(CacheNode* node){
        if(node->pre==nullptr){//头部
            head=node->next;
        }else{
            node->pre->next=node->next;
        }

        if(node->next ==nullptr){//尾部
            tail=node->pre;
        }else{
            node->next->pre=node->pre;
        }
    }

    //将节点插入到头部
    void setHead(CacheNode* node){
        node->next=head;
        node->pre=nullptr;

        if(head!=nullptr){
            head->pre=node;
        }
        head=node;
        if(tail==nullptr){
            tail=head;
        }
    }

    //get(key)操作的实现简单，直接通过判断map中是否含有key值即可，如果找到key,则返回value；否则返回-1；

    int get(int key){
        map<int , CacheNode*>::iterator it =mp.find(key);
        if(it!=mp.end()){
            CacheNode* node=it->second;
            remove(node);
            setHead(node);
            return node->value;
        }else{
            return -1;
        }
    }

    //set操作，分为两种情况讨论
    /*
    1) 如果当前的key值对应的节点已经存在，则将这个节点取出来，并删除节点所处的原有位置
    2）如果节点不存在节点中，这个时候需要在链表的头部插入新节点，插入新节点可能导致容量溢出，
    如果出现溢出的情况，则需要删除链表尾部的节点。
    */
   void set(int key, int value){
       map<int, CacheNode*>::iterator it=mp.find(key);

       if(it!=mp.end()){
           CacheNode* node=it->second;
           node->value = value;
           remove(node);
           setHead(node);
       }else{
           CacheNode * newNode= new CacheNode(key,value);
           if(mp.size()>=size){
               map<int ,CacheNode*>::iterator iter=mp.find(tail->key);
               remove(tail);//删除末尾节点；
               mp.erase(iter);
           }

           setHead(newNode);//将节点插入到头部
           mp[key] = newNode;

       }
   }
};

int main(int argc, char **argv)
{
  LRUCache *lruCache = new LRUCache(2);
  lruCache -> set(2, 1);
  lruCache -> set(1, 1);
  cout << lruCache -> get(2) << endl;
  lruCache -> set(4, 1);
  cout << lruCache -> get(1) << endl;
  cout << lruCache -> get(2) << endl;
  system("pause");
  return 0;
}