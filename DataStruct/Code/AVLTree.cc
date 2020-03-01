//===========================================================、
//平衡二叉树的实现和说明
//
//
//============================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
}; 

int max(int a,int b){
    return (a>b)?a:b;
}

int height(struct Node* N){
    if(N==NULL){
        return 0;
    }

    return N->height;
}

//创建新的节点，
Node* newNode(int key){
    Node* node =new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;//节点初始化时，节点的高度为1；
    return node;
}

//右旋；
Node* rightRoate(Node *y){
    Node*x= y->left;
    Node*T2=x->right;

    x->right=y;//x称为根节点，所以其右子树为y;
    y->left=T2;//将x节点的右子树放到y节点的左子树；

    //更新高度；
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

//左旋
Node*leftRoate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;//表示父节点的值；
}


//判断二叉树是不是平衡二叉树；
int getBalance(Node* N){
    if(N==NULL){
        return 0;
    }

    return height(N->left)-height(N->right);
}


//节点插入
/*
1)执行正常的BST插入
2)更新其其父节点的高度
3）得到这个祖先的平衡因子节点，以检查此节点是否已成为不平衡
4）如果不平衡，则将有四种情况；
a) 左左  ；b) 右右； c) 左右 ； d) 右左；

*/
Node * insert(Node * node ,int key){

    if(node ==NULL ){
        return newNode(key);
    }

    if(key<node->key){
        node->left =insert(node->left,key);
    }else if(key >node->key){
        node->right =insert(node->right,key);
    }else{
        return node;//说明二叉树中存在这种列表；
    }
    //2、更新其父节点的高度；
    node->height=1+max( height(node->left),height(node->right));

    //3、判断节点的是不是为平衡树；
    int balance =getBalance(node);

    //步骤四：如果树的尺寸不平衡，则发生下面的四种情况；

    if(balance>1 && key<node->left->key){
        return rightRoate(node);
    }

    if(balance<-1 && key>node->right->key){
        return leftRoate(node);
    }

    if(balance>1&& key>node->right->key){
        node->left=leftRoate(node->right);
        return leftRoate(node);
    }

    if(balance<1 && key<node->right->key){
        node->right =rightRoate(node->right);
        return leftRoate(node);
    }

    return node ;
    
}

//前序遍历

void preOrder(Node *root){
    if(root!=NULL){
        cout<<root->key<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//查找非空二叉树中的最小值；

Node* minValueNode(Node* node){
    Node * current= node;
    while(current->left!=NULL){
        current=current->left;
    }

    return current;
}
//删除某一个节点
/*
步骤：
1）执行正常二叉树操作，该步骤主要寻找删除的节点；
a）找到删除结点的位置；分为三种情况进行讨论；
b)如果找到给该节点；进行删除该节点；，此时又会分为三种情况进行讨论；
  @ 没有孩子节点或者只有一个孩子节点；
  @@有两个孩子节点；

2）更新二叉树的高度；
3）获得该节点的平衡因子；
4）如果不平衡，则有四种因素；
a)左左；b)右右；c)左右；d) 右左；

*/


Node* deleteNode(Node*root, int key){
    //1、找到相关的节点；
    if(root ==NULL){
        return root;
    }

    if(key< root->key){
        root->left=deleteNode(root->left,key);
    }else if(key> root->key){
        root->right = deleteNode(root->right,key);
    }else{
        //找到了该节点；

        //只有一个节点或者没有节点；
        if((root->left==NULL)|| (root->right==NULL)){
            Node*temp =root->left?root->left:root->right;

            if(temp==NULL){
                temp=root;
                root=NULL;
            }else{
                *root=*temp;
            }
            free(temp);
        }else{
            //有两个节点的情况
            Node* temp=minValueNode(root->right);

            root->key=temp->key;

            root->right=deleteNode(root->right,root->key);
        }
    }

        if(root==NULL){
            return root;
        }

        root->height =1+max(height(root->left),height(root->right));

        int balance=getBalance(root);

        //进行平衡二叉树

        if (balance > 1 &&  getBalance(root->left) >= 0)  
        return rightRoate(root);  

        // Left Right Case  
        if (balance > 1 &&  getBalance(root->left) < 0)  
        {  
            root->left=leftRoate(root->left); 
            return rightRoate(root);  
        }  

        // Right Right Case  
        if (balance < -1 &&  getBalance(root->right) <= 0)
            return leftRoate(root);    

        // Right Left Case  
        if (balance < -1 &&  getBalance(root->right) > 0)  
        {  
            root->right=rightRoate(root->right);
            return leftRoate(root);  
        }  
         return root;

}



int main()  
{  
Node *root = NULL;  
  
    /* Constructing tree given in 
    the above figure */
    root = insert(root, 9);  
    root = insert(root, 5);  
    root = insert(root, 10);  
    root = insert(root, 0);  
    root = insert(root, 6);  
    root = insert(root, 11);  
    root = insert(root, -1);  
    root = insert(root, 1);  
    root = insert(root, 2);  
  
    /* The constructed AVL Tree would be  
            9  
        / \  
        1 10  
        / \ \  
    0 5 11  
    / / \  
    -1 2 6  
    */
  
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
  
    root = deleteNode(root, 10);  
  
    /* The AVL Tree after deletion of 10  
            1  
        / \  
        0 9  
        / / \  
    -1 5     11  
        / \  
        2 6  
    */
  
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";  
    preOrder(root);  
    system("pause");
    return 0;  
}  