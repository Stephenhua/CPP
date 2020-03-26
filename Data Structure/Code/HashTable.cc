#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;
#define HASHSIZE 19

struct hashNode{
    char *key ;
    char *value ;
    hashNode* next;
};

char * strcopy(char *s){
    int len=strlen(s)+1;
    char *res= new char[len];
    strcpy(res,s);
    if(res==NULL){
        return NULL ;
    }
    return res;
}

class hashTable{
    public:
     hashTable();
     ~hashTable();
     unsigned int hashFun(char *s);
     hashNode * hashFind(char * key);
     bool hashInsert(char* key,char* value);
     bool hashDelete(char * key);
     void display();
     private:
     hashNode* hasData[HASHSIZE];
};

hashTable::hashTable(){
    for(int i=0;i<HASHSIZE;i++){
        hasData[i]=NULL;
    }
}

hashTable::~hashTable(){
    hashNode *p,*q;
    for(int i=0;i<HASHSIZE;i++){
        if(hasData[i]!=NULL){
            p=hasData[i];
            while(p){
                q=p->next;
                delete p->key;
                delete p->value;
                delete p;
                p=q;
            }
        }
    }
}

unsigned int hashTable::hashFun(char *s){
    unsigned int res=0;
    for(;*s!='\0';++s){
        res=*s+res;
    }
    return res%HASHSIZE;
}

hashNode* hashTable::hashFind(char *keys){
    unsigned int res=hashFun(keys);
    hashNode* p=hasData[res];
    for(;p!=NULL;p=p->next){
        if(strcmp(p->key,keys)==0){
            return p;
        }
    }
    return NULL;
}


bool hashTable::hashInsert(char* keys, char* values){
    unsigned int res;
    if(keys==NULL){
        return 0;
    }
    hashNode *p;
    if((p=hashFind(keys))==NULL){
        res=hashFun(keys);
        p=new hashNode;
        if(p==NULL){
            return 0;
        }
        p->key=strcopy(keys);
        p->value=strcopy(values);

        if(p->key==NULL){
            return 0;
        }

        p->next=hasData[res];
        hasData[res]=p;
    }else{
        delete p->value;
        p->value=strcopy(values);
    }
}

bool hashTable::hashDelete(char* keys){

    hashNode *FastPointer= NULL,*SlowPointer=NULL;
    unsigned int res=hashFun(keys);
    FastPointer=hasData[res];
    if(!FastPointer){
        return 0;
    }

    if(strcmp(FastPointer->key,keys)==0){
        hasData[res]=FastPointer->next;
        delete FastPointer->value;
        delete FastPointer->key;
        delete FastPointer;
    }
    SlowPointer=FastPointer;
    FastPointer=SlowPointer->next;

    while(FastPointer && strcmp(FastPointer->key,keys)!=0){
        SlowPointer=FastPointer;
        FastPointer=FastPointer->next;
    }

    if(FastPointer){
        SlowPointer->next=FastPointer->next;
        delete FastPointer->key;
        delete FastPointer->next;
        delete FastPointer;
    }
    return 1;

}
void hashTable::display(){
    hashNode *p;
    for(int i=0;i<HASHSIZE;i++){
        if(hasData[i]==nullptr){
            cout<<"()"<<endl;
        }
        else{
            p=hasData[i];
            cout<<"(";
            for(;p!=NULL;p=p->next){
                cout<<"("<<p->key<<","<<p->value<<")";
            }
            cout<<")"<<endl;
           }
    }
}

int main(){
    hashTable hash_Table;
    hashNode *flag=nullptr;
    char* keys[]= {"user1","user5","user13","user108","suer31","ersu13","user108"};
    char* values[]= {"mike","joy","hello","world","someone","15646","newworld"};

    for(int i=0;i<7;i++){
        hash_Table.hashInsert(keys[i],values[i]);
    }
    cout<<"The result is :"<<endl;
    hash_Table.display();

    cout<<endl;

    flag=hash_Table.hashFind("user108");
    if(flag ==NULL){
        cout<<"the user is not found "<<endl;
    }else
    {
        cout<<"The value is "<<flag->value<<endl;
    }

    hash_Table.hashDelete("user13");
    cout<<endl;
    cout<<"The new result is"<<endl;
    hash_Table.display();
    
    system("pause");
    return 0;
    
}