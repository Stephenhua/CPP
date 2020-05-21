#include<iostream>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>

using namespace std;

typedef struct _AA_
{
    int b1:5;
    int b2:2;
}AA;

int   main(int argc, char* argv[])
{
    AA aa;
    char cc[100];
    strcpy(cc,"0123456789abcdefghijklmnopqrstuvwxyz");
    memcpy(&aa,cc,sizeof(AA));
    cout << aa.b1 <<endl;
    cout << aa.b2 <<endl;

    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);
    printf("%d,%d",*(a+1),*(ptr-1));

    system("pause");
    return 0 ;
}



struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
    ListNode* m_pre;
};

void  Insert( ListNode* Node,ListNode* InsertNode){

    if(Node->m_pNext == nullptr){
        Node->m_pNext = InsertNode;
        InsertNode->m_pNext=Node;
        InsertNode->m_pre =nullptr;
    }
    ListNode* preNode = Node->m_pre;
    preNode->m_pNext = InsertNode;
    InsertNode->m_pNext = Node;
    Node->m_pre = InsertNode;
}

//实现排序；

string SortASCII( char* str){

    vector<int> temp;

    int size = strlen(str);

    for(int i =0 ;i <size ;i++){
        temp[i]=str[i];
    }

    sort(temp.begin() ,temp.end());

    string res;

    for(int i=0;i!=temp.size();i++){
        res+=temp[i];

    }
}
int   main(int argc, char* argv[])
{
    char * str = "54321abCdEf";

    string res = SortASCII( str);

    cout <<res <<endl;
    system("pause");
    return 0 ;
}