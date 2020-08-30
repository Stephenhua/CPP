#include <iostream>
#include <vector>

using namespace std;

template<class K, class V>
struct HashTableNode{
    K _key ;
    V _value;
    HashTableNode* _next ;
    HashTableNode(const K &_key ,const V& _v):_key(_key),_value(_v),_next(nullptr){}
};

template<class K ,class V >
class HashTable{
    public:
        typedef HashTableNode<K,V> Node ;
    private:
        vector<Node*> _table;//用于存储哈希节点；
        size_t _size ;//用于表示个数
    public:
        HashTable():_table(NULL),_size(){}
        //析构函数
	    ~HashTable(){
            //删除哈希ht;
            if(this->_table.size() != 0){
                for(int i =0 ;i < _table.size() ;i++){
                    Node* cur= _table[i];
                    while( cur){
                        Node* del = cur;
                        cur =cur->_next;
                        delete del;
                        del = NULL;
                    }
                }
            }
        }
        //哈希函数；    
        size_t  HashFunc( const K& key){
            return key%_table.size();
        }

        //拷贝构造函数；
        HashTable(const HashTable& ht){
            
            //重新将数组的内存大小进行分配；
            this->_table.resize(ht._table.size());
            for(int i = 0 ; i < ht._table.size() ; i++ ){
                Node* cur = ht._table[i];
                while(cur){
                    Node* temp = new Node(cur->_key,cur->_value);
                    temp->_next = _table[i];
                    this->_size++;
                    cur = cur->_next;
                }
            }
        }
/*
        HashTable<K, V> operator=(const HashTable<K, V>& ht)
        {	
            if (&ht != this)
            {
                //删除哈希表this
                for (int i = 0; i < this->_table.size(); i++)
                {
                    Node* cur = _table[i];
                    while (cur)
                    {
                        Node* del = cur;
                        cur = cur->_next;
                        Remove(del->_key);
                    }
                }

                将哈希表ht拷贝给this
                this->_table.resize(ht._table.size());
                for (int i = 0; i < ht._table.size(); i++)
                {
                    Node* cur = ht._table[i];
                    while (cur)
                    {
                        Node* tmp = new Node(cur->_key, cur->_value);
                        tmp->_next = _table[i];
                        _table[i] = tmp;
                        this->_size++;

                        cur = cur->_next;
                    }
                }		
            }
            return *this;
        }

*/
        //赋值运算符重载的现代写法
        HashTable<K, V> operator=(HashTable<K, V> ht){
            if (&ht != this)
            {
                swap(_table, ht._table);
                swap(_size, ht._size);
            }	
            return *this;
        }


        //获取新的哈希表容量大小
        size_t _GetnewSize(){
            static const int _PrimeSize = 28 ;
            static const unsigned long _PrimeList[_PrimeSize] =
            {
                53ul, 97ul, 193ul, 389ul, 769ul,
                1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
                49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
                1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
                50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
                1610612741ul, 3221225473ul, 4294967291ul
            };
            
            for(int i = 0 ;i < _PrimeSize  ; i++){
                if( _PrimeList[i] > _table.size()){
                    return _PrimeList[i];
                }
            }
            return _PrimeList[_PrimeSize-1];
        }
        //给哈希桶扩容
        void _ExpandCapacity(){
            //开辟新的更大容量的哈希表；
            size_t newSize = _GetnewSize();
            vector<Node*> newTable;
            newTable.resize(newSize);

            //将每处顺序表中的单链表元素摘下来插入到新的顺序表中；
            for(int i = 0 ; i < _table.size() ;i++){
                Node* cur = _table[i];
                while(cur){
                    Node* temp = cur;
                    int index = HashFunc(temp->_key);
                    temp->_next = newTable[i];
                    newTable[index] = temp;
                }
                _table[i] =NULL;
            }
            _table.swap(newTable);
        }

        //插入关键字
        bool Insert(const K& key,const V& value){
            //检查载荷因子，考虑是否扩容；
            if( _size == _table.size()){
                _ExpandCapacity();
            }

            //在顺序表的index插入节点；
            size_t index = HashFunc(key);
            Node* begin = _table[index];
            while( begin){
			    //设计成不可出现重复元素
                if(begin->_key == key ){
                    return false;
                }
                begin = begin->_next;
            }

            //在同一个单链表上，无所谓存放顺序，直接在尾部进行重新插入；
            Node* tempNode = new Node(key,value);
            tempNode->_next = _table[index];
            _table[index] = tempNode;
            _size++;
            return true;
        }
        //查找关键字
        Node* Find(const K& key){
            int index = HashFunc(key);

            Node* begin = _table[index];
            while(begin){
                if(begin->_key== key){
                    return begin;
                }
                begin = begin->_next;
            }
            return NULL;
        }
        //删除关键字
        bool Remove(const K& key){
            int index= HashFunc(key);
            Node* temp = _table[index];
            Node* prev = NULL;
            //先找到当前的节点；
            while(temp){
                if(temp->_key == key){
                    break;
                }
                prev = temp;
                temp = temp->_next;
            }

            //判断当前节点的位置，在首部和中间，两种情况进行讨论；

            if(temp){
                if( temp ==_table[index]){
                    _table[index] = temp->_next;
                }else{
                    Node* next = temp->_next;
                    prev->_next = next;
                }

                delete temp;
                temp = nullptr;
                --_size;
                return true;
            }
            return false;

        }
        //打印哈希桶
        void PrintHashTable(){

            for(int i = 0 ;i <_table.size() ;i++){
                Node* cur = _table[i];
                cout << i ;
                while(cur){
                    cout << cur->_key <<"->";
                    cur = cur->_next;
                }

                cout << "NUll"<< endl;
            }
            cout << endl;
        }
};


void TestHashTableBucket()
{
	typedef HashTableNode<int, char> Node;

	HashTable<int, char> ht;
	ht.Insert(1, 'a');
	ht.Insert(2, 'b');
	ht.Insert(3, 'c');
	ht.Insert(4, 'd');
	ht.Insert(5, 'd');
	ht.Insert(54, 'x');
	ht.Insert(55, 'y');
	ht.Insert(56, 'z');

	ht.PrintHashTable();

	HashTable<int, char> ht2;
	ht2.Insert(54, 'x');
	ht2.Insert(55, 'y');
	ht2.Insert(56, 'z');
	ht2.Insert(1, 'a');
	ht2.Insert(2, 'b');
	ht2.Insert(3, 'c');
	ht2.Insert(4, 'd');
	ht2.Insert(5, 'd');

	ht2.PrintHashTable();

	ht = ht2;
	ht.PrintHashTable();

}


int main()
{
	TestHashTableBucket();
	system("pause");
	return 0;
}