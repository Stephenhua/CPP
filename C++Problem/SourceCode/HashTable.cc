#include "HeshTable.h"

void hashTableListTest(){

    HashTableBucket<int,int> ht ;

    for(size_t i =0 ;i<50 ;i++){
        ht.Insert(i,i);
    }

    ht.Insert(107,32);
    ht.Insert(54,45);

    ht.Remove(1);
}

void HashTableTest(){

    HashTableBucket<int,int> ht ;

    ht.Insert(1,1);
    ht.Insert(11,11);
    ht.Insert(22,22);
    ht.Insert(23,23);
    ht.Insert(54,47);
    ht.Insert(42,12);

    HashTableBucket<int,int> ht1(ht);

    HashTableBucket<int,int> ht2;

    ht2  = ht1;

    ht2.print();
}

void DicFindTest(){
    HashTableBucket<string, string> ht;

	ht.Insert("字典","dirc");
	ht.Insert("钱","money");
	ht.Insert("吃","eat");
	ht.Insert("玩","happy");
	ht.print();
}

int main( int argc ,char* argv[]){

   hashTableListTest();
   HashTableTest();
   DicFindTest();
   system("pause");
   return 0 ;
   
}
