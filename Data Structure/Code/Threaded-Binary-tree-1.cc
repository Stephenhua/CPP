#include<iostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;

class N{
    public:
    int k;
    N *l,*r;
    bool leftTh,rihgtTh;
};

class ThreadBinaryTree{
    private:
    N *root;
    public:
    ThreadBinaryTree(){
        root=new N();
        root->r=root->l=root;
        root->leftTh=true;
        root->k=MAX_VALUE;
    }

    void makeEmpty(){
        root= new N();
        root->r=root->l=root;
        root->leftTh=true;
        root->k=MAX_VALUE;
    }

    //插入节点
    void insert(int key){
        N *p=root;
        for(;;){
            if(p->k>key){
                if(p->leftTh){
                    break;
                }
                p=p->l;
            }else if(p->k<key){
                if(p->rihgtTh){
                    break;
                }
                p=p->r;
            }else{
                return ;
            }
        }

        N *temp =new N();
        temp->k=key;
        temp->rihgtTh=temp->leftTh=true;

        if(p->k <key){
            temp->r=p->r;
            temp->l=p;
            p->r=temp;
            p->rihgtTh=false;
        }else{
            temp->r=p;
            temp->l=p->l;
            p->l=temp;
            p->leftTh=false;

        }
    }

//搜索二叉树
bool search(int key) {
      N *temp = root->l;
      for (;;) {
      if (temp->k < key) { //search in left thread
      if (temp->rihgtTh)
            return false;
         temp = temp->r;
      } else if (temp->k > key) { //search in right thread
         if (temp->leftTh)
            return false;
         temp = temp->l;
      } else {
         return true;
      }
   }
}
    //删除结点
    void Delete(int key){
        N* dest=root->l,*p=root;
        for(;;){
            if(dest->k<key){
                if(dest->rihgtTh){
                    return;
                }
                p=dest;
                dest=dest->r;
            }else if(dest->k >key){
                if(dest->leftTh){
                    return ;
                }
                p=dest;
                dest=dest->l;
            }else{
            break;
            }
        }

        N* target =dest;
        //表示有两个节点
        if(!dest->rihgtTh && !dest->leftTh){
            p=dest;
            target=dest->l;//最大的节点是左孩子
            while(!target->rihgtTh){
                p=target;
                target=target->r;
            }
            dest->k=target->k;
        }

        if(p->k >=target->k){//只有左孩子
            if(target->rihgtTh && target->leftTh){
                p->l =target->l;
                p->leftTh=true;
            }else if(target->rihgtTh){
                N* largest=target->l;
                while(!largest->rihgtTh){
                    largest=largest->r;
                }
                largest->r=p;
                p->l=target->l;
            }else{
                N *smallest = target->r;
                while (!smallest->leftTh) {
                    smallest = smallest->l;
                }
                smallest->l = target->l;
                p->l = target->r;

            }
        }else{//只有右孩子
              if (target->rihgtTh && target->leftTh) {
                    p->r= target->r;
                    p->rihgtTh = true;
                } else if (target->rihgtTh) {
                    N *largest = target->l;
                    while (!largest->rihgtTh) {
                        largest = largest->r;
                    }
                    largest->r= target->r;
                    p->r = target->l;
                } else {
                    N *smallest = target->r;
                    while (!smallest->leftTh) {
                        smallest = smallest->l;
                    }
                    smallest->l= p;
                    p->r= target->r;
                }

        }
    }

void displayTree() { //print the tree
   N *temp = root, *p;
   for (;;) {
      p = temp;
      temp = temp->r;
      if (!p->rihgtTh) {
         while (!temp->leftTh) {
            temp = temp->l;
         }
      }
      if (temp == root)
         break;
      cout<<temp->k<<" ";
   }
   cout<<endl;
}


};

int main() {
   ThreadBinaryTree tbt;
   cout<<"ThreadedBinaryTree\n";
   char ch;
   int c, v;  
   while(1) {
      cout<<"1. Insert "<<endl;
      cout<<"2. Delete"<<endl;
      cout<<"3. Search"<<endl;
      cout<<"4. Clear"<<endl;
      cout<<"5. Display"<<endl;
      cout<<"6. Exit"<<endl;
      cout<<"Enter Your Choice: ";
      cin>>c;
      //perform switch operation
      switch (c) {
         case 1 :
            cout<<"Enter integer element to insert: ";
            cin>>v;
            tbt.insert(v);
            break;
         case 2 :
            cout<<"Enter integer element to delete: ";
            cin>>v;
            tbt.Delete(v);
            break;
         case 3 :
            cout<<"Enter integer element to search: ";
            cin>>v;
            if (tbt.search(v) == true)
               cout<<"Element "<<v<<" found in the tree"<<endl;
            else
               cout<<"Element "<<v<<" not found in the tree"<<endl;
            break;
         case 4 :
            cout<<"\nTree Cleared\n";
            tbt.makeEmpty();
            break;
         case 5:
            cout<<"Display tree: \n ";
            tbt.displayTree();
            break;
         case 6:
            exit(1);
         default:
            cout<<"\nInvalid type! \n";
      }
   }
   cout<<"\n";
   return 0;
}



