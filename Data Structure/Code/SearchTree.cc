//===========================================================、
//搜索二叉树的实现和说明
//
//
//============================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


enum Type
{
	THREAD,//表示指针被线索化
	LINK//表示指针未被线索化
};
template<typename T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T> *_left;
	BinaryTreeNode<T> *_right;
	Type _leftTag;//标识左指针
	Type _rightTag;//标识右指针
	BinaryTreeNode(const T& x)//构造函数
		:_data(x)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{}
 
	BinaryTreeNode()//默认构造函数
	{}

//前序线索化

void _PrevOrder(BinaryTreeNode* _root){
    static BinaryTreeNode* prev=NULL;
    if(_root){
        if(! _root->left){
            _root->_leftTag=THREAD;
            _root->_left=prev;
        }
        if(prev && !prev->_right){
            prev->_rightTag=THREAD;
            prev->_right=_root;
        }

        prev=_root;
        if(_root->_leftTag ==LINK){
            _PrevOrder(_root->_left);
        }
        if(_root->_rightTag == LINK){
            _PrevOrder(_root->_right);
        }
    }
}

//中序线索化
void _InOrder(BinaryTreeNode* _root){
    static BinaryTreeNode* prev=NULL;

    if(_root){
        if(_root->_leftTag ==LINK){
            _InOrder(_root->_left);
        }

        if(!_root->_left){
            _root->_leftTag=THREAD;
            _root->_left=prev;
        }

        if(prev && !prev->_right){
            prev->_rightTag=THREAD;
            prev->_right=_root;
        }

        prev=_root;
        if(_root0>_rightTag ==LINK){
            _InOrder(_root->_right);
        }
    }
}


//后序线索化


void _PostOrder_Thd(BinaryTreeNode* _root)
{
	if (_root == NULL)
	{
		return;
	}
	static BinaryTreeNode* prev = NULL;
	_PostOrder_Thd(_root->_left);
	_PostOrder_Thd(_root->_right);
	if (!_root->_left)
	{
		_root->_leftTag = THREAD;
		_root->_left = prev;
	}
	if (prev && !prev->_right)
	{
		prev->_rightTag = THREAD;
		prev->_right = _root;
	}
	prev = _root;
}



//利用中序线索化思想将搜索二叉树转换成有序的双向列表

void _TreeToList(BinaryTreeNode* _root){
    static BinaryTreeNode* prev=NULL;

    if(_root ==NULL){
        return;
    }

    _TreeToList(_root->_left);//递归左子树；
    _root->_left=prev;//让当前节点的左指针指向上一次访问的节点，即前驱；
    if(prev){
        prev->_right =_root;
    }

    prev=_root;//更新prev;
    _TreeToList(_root->_right);//递归右子树
}