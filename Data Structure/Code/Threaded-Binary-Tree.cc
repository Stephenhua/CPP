/*
线索二叉树；
*/

#include<iostream>
#include <vector>
using namespace std;
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

  void CreateTreeThread(){ }

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
                subTree= new ThreadNode<T>(item);
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

        if(pre!=NULL && pre->rightChild==NULL){//建立当前节点的后继节点；
            pre->rightChild=current;
            pre->rtag=1;
        }

        pre=current;//用前驱记住当前的结点；
        CreateInThread(current->rightChild,pre);//递归右子树的线索化；
    }

    ThreadNode<T>* First(ThreadNode<T>* current){
        ThreadNode<T>*p=current;
        while(p->ltag==0){
            p=p->leftChild;//循环找到最左下角结点
        }
        return p;
    }

    //寻找中序下的后继结点；
    ThreadNode<T>* Next(ThreadNode<T>* current){
        ThreadNode<T>* p=current->rightChild;
        if(current->rtag == 0){
            return First(p);
        }
        else{
            return p;
        }
    }

    //寻找中序下的最后一个节点
    ThreadNode<T>* Last(ThreadNode<T>* current){//返回以*current为根的中序线索二叉树中序遍历的最后一个结点
        ThreadNode<T>* p=current;
        while(p->rtag==0){
            p=p->rightChild;
        }
        return p;
    }

    //寻找结点在中序下的前驱节点
    ThreadNode<T>* Prior(ThreadNode<T>* current){
        ThreadNode<T>* p=current->leftChild;
        if(current->ltag==0){
            return Last(p);
        }else{
            return p;
        }

    }


 //在中序线索化二叉树中求父节点
     ThreadNode<T>* Parent(ThreadNode<T>* t)
     {
         ThreadNode<T>* p;
         if(t==root)    //根节点无父节点
         {
             return NULL;
         }
         for (p = t; p->ltag == 0; p = p->leftChild);    //求*t为根的中序下的第一个结点p
         //情况1
         if (p->leftChild!=NULL)    //当p左子树指向不为空
         {
             //令p为p的左子树指向的结点，判断此结点是否并且此节点的左右子树结点的指向都不为t，再将p为p的右孩子结点
             for (p = p->leftChild; p != NULL&&p->leftChild != t&&p->rightChild != t; p = p->rightChild);
         }
         //情况2
         //如果上面的循环完了，由于是p==NULL结束的循环，没有找到与t相等的结点，就是一直找到了中序线索化的第一个结点了，这时候这种就要用到情况2的方法
         if (p==NULL||p->leftChild==NULL)
         {
             //找到*t为根的中序下的最后一个结点
             for (p = t; p->rtag == 0; p = p->rightChild);
             //让后让他指向最后一个结点指向的结点，从这个结点开始，以此判断它的左孩子孩子和右孩子是否和t相等
             for (p = p->rightChild; p != NULL&&p->leftChild != t&&p->rightChild != t; p = p->leftChild);
         }
        return p;
     }

     //中序线索化二叉树上执行中序遍历算法；
     void InOrder(ThreadNode<T>* p){
         for(p=First(root);p!=NULL;p=Next(p)){//采用依次求解的方式进行求解；
            cout<<p->data<<" ";
         }
         cout<<endl;
     }

     //中序线索二叉树上实现前序遍历算法；
     void PreOrder(ThreadNode<T>* p){
         while(p!=NULL){
             cout<<p->data<<" ";//先访问根节点；
             if(p->ltag == 0){
                 p=p->leftChild;//有左子树，则为后继节点；
             }else if(p->rtag==0){
                 p=p->rightChild;//有右子树，则为后继节点；
             }else{//当无左右子树的时候；
                 while(p!=NULL && p->rtag==1){//检测后继线索；
                     p=p->rightChild;//直到找到右子树的节点；
                 }
                 if(p!=NULL){
                     p=p->rightChild;//该节点的右子树为后继
                 }
             }
         }
         cout<<endl;
     }

     //中序线索二叉树实现后序遍历算法

     void PostOrder(ThreadNode<T>* p){
         ThreadNode<T>* t=p;
         while(t->ltag==0 ||t->rtag==0){//寻找后继第一个节点
            if(t->ltag==0){
                t=t->leftChild;
            }else if(t->rtag==0){
                t=t->rightChild;
            }
         }

         cout<<t->data<<" "; //访问第一个节点；

         while((p=Parent(t))!=NULL){//每次找到当前节点的父节点；
            //若当前结点是父节点的右子树或者当前节点是左子树，但是这个父节点没有右子树，则后续下的后继改为父节点；
            if(p->rightChild ==t || p->rtag ==1){
                t=p;
            }
            //否则，在当前结点的右子树上重复执行上面的操作；
            else{
                t=p->rightChild;
                while(t->ltag==0 || t->rtag){
                    if(t->ltag==0){
                        t=t->leftChild;
                    }else if(t->rtag){
                        t=t->rightChild;
                    }
                }
            }
            cout<<t->data<<" ";
         }
     }
};



 int main(int argc, char* argv[])
{
    //abc##de#g##f###
    ThreadTree<char> tree('#');
    tree.CreateTree();
    tree.CreateInThread();
    tree.InOrder();
    tree.PreOrder();
    tree.PostOrder();
}