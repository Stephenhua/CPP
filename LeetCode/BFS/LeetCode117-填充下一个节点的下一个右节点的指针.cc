#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;



class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


//解法一：采用广度优先的算法进行求解；在whle循环中加入一个for循环，循环的次数是循环前的队列中的元素个数，；
//for循环结束表明当前层结束了，此时的队列将存储下一层的元素了；
class Solution {
public:
    Node* connect(Node* root) {
        
      //判断当前截止条件
        if (root==nullptr)
        {
            return root ;
            /* code */
        }

        queue<Node*> temp_queue;
        temp_queue.push(root);
        while(!temp_queue.empty()){
            int size=temp_queue.size();
            
            Node *pre=nullptr;
            
            for(int i=0;i<size;i++){
                Node *cur= temp_queue.front();
                temp_queue.pop();
                
                if(pre!=nullptr){
                    pre->next=cur;
                }
                pre=cur;
                if(cur->left!=nullptr){
                    temp_queue.push(cur->left);
                }
                if(cur->right!=nullptr){
                    temp_queue.push(cur->right);
                }
            }

        }
        return root; 
        
    }
};
//解法二：采用遍
Node connect(Node root) {
    if (root == null)
        return root;
    Node pre = root;
    Node cur = null;
    while (true) {
        cur = pre;
        while (cur != null) {
            //找到至少有一个孩子的节点
            if (cur.left == null && cur.right == null) {
                cur = cur.next;
                continue;
            }
            //找到当前节点的下一个至少有一个孩子的节点
            Node next = cur.next;
            while (next != null && next.left == null && next.right == null) {
                next = next.next;
                if (next == null) {
                    break;
                }
            }
            //当前节点的左右孩子都不为空，就将 left.next 指向 right
            if (cur.left != null && cur.right != null) {
                cur.left.next = cur.right;
            }
            //要接上 next 的节点的孩子，所以用 temp 处理当前节点 right 为 null 的情况
            Node temp = cur.right == null ? cur.left : cur.right;

            if (next != null) {
                //next 左孩子不为 null，就接上左孩子。
                if (next.left != null) {
                    temp.next = next.left;
                //next 左孩子为 null，就接上右孩子。
                } else {
                    temp.next = next.right;
                }
            }

            cur = cur.next;
        }
        //找到拥有孩子的节点
        while (pre.left == null && pre.right == null) {
            pre = pre.next;
            //都没有孩子说明已经是最后一层了
            if (pre == null) {
                return root;
            }
        }
        //进入下一层
        pre = pre.left != null ? pre.left : pre.right;
    } 
}


//解法三:采用广度优先的方法进行


Node connect(Node root) {
        if(root==nullptr){
              return ;
          }

        Node *pre=root;
        Node *cur=nullptr;
        while(pre->left){
            cur=pre;
            while(cur){
                cur->left->next=cur->right;
                if(cur->next){
                    cur->right->next=cur->next->left;

                }

                cur=cur->next;
            }
            pre=pre->left;
        }
}



//解法四：采用递归的形式进行求解
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return nullptr;
        }

        Node *p= root->next;
        //进行递归的过程时，考虑到上一层的关系，从而绕到下一个next的左子树位置；
        while(p){
            if(p->left){
                p=p->left;
                break;
            }
            if(p->right){
                p=p->right;
                break;
            }

            p=p->next;
        }

        if(root->right){
            root->right->next=p;
        }
        if(root->left){
            root->left->next=root->right?root->right:p;
        }

        connect(root->right);
        connect(root->left);
        return root;

    }
};


//解法四：采用递归的形式进行求解
/*我们建立一个dummy结点来指向每层的首结点的前一个结点，
然后指针cur用来遍历这一层，我们实际上是遍历一层，然后连下一层的next，
首先从根结点开始，如果左子结点存在，那么cur的next连上左子结点，然后cur指向其next指针；如果root的右子结点存在，
那么cur的next连上右子结点，然后cur指向其next指针。此时root的左右子结点都连上了，
此时root向右平移一位，指向其next指针，如果此时root不存在了，说明当前层已经遍历完了，
我们重置cur为dummy结点，root此时为dummy->next，即下一层的首结点，
然后dummy的next指针清空，或者也可以将cur的next指针清空，因为前面已经将cur赋值为dummy了。
那么现在想一想，为什么要清空？因为我们用dummy的目的就是要指到下一行的首结点的位置即dummy->next，
而一旦将root赋值为dummy->next了之后，这个dummy的使命就已经完成了，必须要断开;
如果不断开的话，那么假设现在root是叶结点了，那么while循环还会执行，不会进入前两个if，
然后root右移赋空之后，会进入最后一个if，之前没有断开dummy->next的话，
那么root又指向之前的叶结点了
这里再来说下dummy结点是怎样指向每层的首结点的前一个结点的，过程是这样的，
dummy是创建出来的一个新的结点，其目的是为了指向root结点的下一层的首结点的前一个，具体是这么做到的呢，
主要是靠cur指针，首先cur指向dummy，然后cur再连上root下一层的首结点，这样dummy也就连上了。
然后当root层遍历完了之后，root需要往下移动一层，这样dummy结点之后连接的位置就正好赋值给root，
然后cur再指向dummy，dummy之后断开，这样又回到了初始状态，以此往复就可以都连上了，\*/
class Solution {
public:
    Node* connect(Node* root) {
        Node * dummy=new Node(0,NULL,NULL,NULL);
        Node *cur=dummy;
        Node *head=dummy;

        while(root){
            if(root->left){
                cur->left=root->left;
                cur=cur->next;
            }
            if(root->right){
                cur->next=root->right;
                cur=cur->next;
            }
            root =root->next;
            if(!root){
                cur=dummy;
                root=dummy->next;
                dummy->next=nullptr;
            }

        }
        return head;
       

    }
};
