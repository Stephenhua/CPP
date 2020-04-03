#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "BinaryTreeNode.h"
using namespace std;

/*
该二叉树为一般二叉树，有二叉树节点中包含指向父节点的指针
*/

struct BinaryNode
{
	BinaryNode* _left;
	BinaryNode* _right;
	BinaryNode* _parent;
	int _value;
 
	BinaryNode(const int& value)
		:_value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};

//方法一：直接用node1的所有父节点与node2的所有父节点进行比较；，时间复杂度为o(N^2);

/*
首先给出node1的父节点node1->_parent，然后将node1的所有父节点依次和node2->parent作比较，
如果发现两个节点相等，则该节点就是最近公共祖先，直接将其返回。
如果没找到相等节点，则将node2的所有父节点依次和node1->_parent->_parent作比较......
直到node1->_parent==NULL。
*/


BinaryNode * GetLastCommonAncestor(BinaryNode * root, BinaryNode * node1, BinaryNode * node2)
{

    BinaryNode* temp=nullptr;
    while(node1!=nullptr){
        node1=node1->_parent;
        temp=node2;
        while(temp!=nullptr){
            if(node1 ==temp->_parent){
                return node1;
            }
            temp=temp->_parent;
        }
    }
}

//方法二：采用链表的形式进行
/*
给定的两个节点都含有父节点，因此，可将这两个节点看做是两个链表的头结点，
将求两个节点的最近公共祖先节点转化为求两链表的交点，
这两个链表的尾节点都是根节点。
*/

 int Hight(BinaryNode* root, BinaryNode* node){
     int len=0;
     for(;node!=nullptr;node=node->_parent){
         len++;
     }
     return len;
 }

 BinaryNode * GetLastCommonAncestor(BinaryNode * root, BinaryNode * node1, BinaryNode * node2)
{
    if(root == nullptr || node1==nullptr || node2==nullptr){
        return nullptr;
    }

    int len1=Hight(root,node1);
    int len2=Hight(root,node2);
    
    if(len1>len2){
        while(len1>len2){
            node1=node1->_parent;
        }
    }else{
        while(len2>len1){
            node2=node2->_parent;
        }
    }

    while(node1 && node2 && node1!=node2){
        node1=node1->_parent;
        node2 = node2->_parent;
    }

    if(node1==node2){
        return node1;
    }else
    {
        return nullptr;
    }
        
}