#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

/*
目的：实现hashTable的功能
*/

 using namespace std;

//哈希表中的节点；
 template< class T, class V>
 struct HashTableNode{
     T _key;
     T _value;
     HashTableNode(const T & key , const V& key):_key(key),_value(value),_next(nullptr){}
     HashTableNode<T,V> * _next ;
 };

template< class T>
struct _HasFunc{

    size_t operator()(const T& key){
        return key;
    }
};
/*
template <class >
struct _HasFunc<stirng>{

    size_t operator()(const string& key){
        char * str = (char*) key.
    }

};*/

template <class T , class V ,class HashFunc = _HasFunc<T>>
class HashTableBucket{
    typedef HashTableNode<T,V> Node ;
    typedef HashTableBucket<T,V ,HashFunc> Table;
    private:
     vector<Node*> _table ; //哈希表；
     size_t _size;  // 数据的个数；

    protected:
         //哈希函数
        size_t _HasFunc(const T & key ,size_t capacity){
            HashFunc hash ;
            
            return hash(key)% capacity;
        }
        //获取下一个素数；
        size_t _GetNexPrime( const size_t size){
            // 使用素数表对齐做哈希表的容量，降低哈希冲突
            const int _PrimeSize = 28 ;
            static const unsigned long _PrimeList[_PrimeSize]={

                53ul,         97ul,         193ul,       389ul,       769ul,

                1543ul,       3079ul,       6151ul,      12289ul,     24593ul,

                49157ul,      98317ul,      196613ul,    393241ul,    786433ul,

                1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,

                50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,

                1610612741ul, 3221225473ul, 4294967291ul               
            };

            for(size_t i= 0 ; i <_ PrimeSize ; ++i){
                if(_PrimeList[i]>size){
                    return _PrimeList[i];
                }
            }
            return _PrimeList[_PrimeSize -1];

        }

        //检查容量大小；

        void _CheckCapcity(){
            if(_size == _table.size()){
                //获得下一个素数大小的空间；
                size_t nextPrime = _GetNexPrime(_size);
                vector<Node*> newtable;
                //桶重新分配内存；
                newtable.resize(nextPrime);
                
                for(size_t i = 0 ;i < _table.size(); i++){
                    
                    Node* cur  = _table[i];

                    while(cur){
                        //摘节点；
                        Node * temp =cur ;
                        cur = cur->_next;

                        //计算在新表中的节点位置，重新进行哈希桶排序；
                        size_t index = _HasFunc(temp->_key , nextPrime);
                        newtable[index] = temp;
                    }
                    //如果vector《int》当前为空，直接赋值为nullptr；
                    _table[i] = nullptr;
                }

                _table.swap(newtable) ; //释放vector的内存，交换内存大小，将下一个素数大小的内存进行分配；
            }
        }


        public:

        HashTableBucket():_table(nullptr),_size(0){}

        HashTableBucket(size_t capacity):_size(0){
            
            _table.resize( _CheckCapcity(capacity));
        }
};