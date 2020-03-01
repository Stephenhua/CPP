/*
线索二叉树；
*/

#include<iostream>
#include <vector>

 //线索二叉树结点类
template<typename T>
struct ThreadNode   //结点类
{
    int ltag, rtag;  //左右子树标志位
    ThreadNode<T> *leftChild, *rightChild;   //左孩子和右孩子
    T data; //结点存储的值
    ThreadNode(const T item) :data(item), leftChild(NULL), rightChild(NULL), ltag(0), rtag(0) {}  //结点类的构造函数
};

template <typename T>
class TreadTree{
 ThreadTree():root(NULL){}

 //指定结束标志ReFValue的构造函数；
 ThreadTree(T value):RefValue(value),root(NULL){}
 
 //使用前序遍历创建好的铍铜二叉树进行中序线索化；

 void CreateTreeThread(){

 }

 //线索化二叉树上执行中序遍历算法；
 void InOrder(){Inorder(root);}
 //中序线索化二叉树上实现前序遍历的算法；
 void PreOrder(){ PreOrder(root);}
 //中序线索二叉树的后序遍历算法；
 void PostOrder(){ PostOrder(root);}

 private:
    ThreadNode<T>* root;
    T RefValue;

 // 使用前序遍历创建二叉树，
    void CreateTree(ThreadNode<T>* &subTree){
        T item;
        if(cin>>item){
            if(item!=RefValue){
                subTree= new ThreadNode<>(item);
                if(subTree ==NULL){
                    cout<<"空间分配错误"<<endl;
                    exit(1);
                }

                CreateTree(subTree->leftChild);//创建左子树；
                CreateTree(subTree->rightChild);//创建右子树；
            }else{
                subTree=NULL;
            }
        }
    }

    //中序遍历对二叉树进行线索化；
    void CreateInThread(ThreadNode<T>* current,ThreadNode<T>* &pre){
        if(current==NULL){
            return ;
        }

        CreateInThread(current->leftChild,pre);//递归左子树序列化；
        if(current->leftChild ==NULL){//建立当前节点的前驱节点
            current->leftChild=pre;
            current->ltag=1;
        }

        if(pre!=NULL && pre->rightChild==NULL){
            pre->rightChild=current;
            pre->rtag=1;
        }

        pre=current;
        CreateInThread(current->rightChild,pre);//建立当前节点的后继节点；
    }
};