#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//改题目的要求是完成深度拷贝，所以一直现有的一个图，在此基础上进行复制，采用map的形式进行，键值作为一个原来的节点，而后面的值作为复制后的节点，每一个节点的邻居的成员类型都相同
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{

public:
    Node * cloneGraph(Node * node){
        //首先通过广度优先遍历，遍历所有节点（BFS），每遍历到一个节点(Node)创建一个与之对应的新节点（Node_1），并利用map数据结构保存该节点(Node_1)与原节点(Node)的映射关系。

        if(!node){
            return nullptr;
        }
        queue<Node*> m_queue1;
        map<Node* ,Node*> m_map;
        Node* temp;
        Node* p;
        m_queue1.push(node);//第一个节点入队
        while(!m_queue1.empty()){
            temp=m_queue1.front();
            m_queue1.pop();
            //建立新的节点
            p=new Node(temp->val,{});//保存自己节点的值与其邻居节点的值
            m_map.insert({temp,p});

            for(Node *neighboursNode:temp->neighbors){
                if(m_map.find(neighboursNode)==m_map.end()){
                    m_queue1.push(neighboursNode);
                }
            }
        }
        //遍历所有节点 完成边的链接
        map<Node *,Node *>::iterator iter;
        for(iter=m_map.begin();iter!=m_map.end();++iter){
            for(Node *neighboursNode:iter->first->neighbors){
                iter->second->neighbors.push_back(m_map.find(neighboursNode)->second);
            }
        }

        
    }
};

//广度优先
class Solution {
    private:
    map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {

        if(!node){
            return nullptr;
        }

        Node* copy=new Node(node->val,{});

        copies[node]=copy;
        queue<Node*> todo;
        todo.push(node);

        while(!todo.empty()){
            Node* cur=todo.empty();
            todo.pop();
            for(Node* neighbour :cur->neighbors){
                if(copies.find(neighbour)==copies.end()){
                    copies[neighbour]=new Node(neighbour->val,{});
                    todo.push(neighbour);
                }
                copies[cur]->neighbors.push_back(copies[neighbour]);
            }
        }
        return copy;



    }

};

//深度优先
class Solution {
private:
    map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }

        if(copies.find(node)==copies.end()){
            copies[node]=new Node(node->val,{});
            for(Node *neighbour:node->neighbors){
                copies[node]->neighbors.push_back(cloneGraph(neighbour));//采用了递归的形式进行，其速度没有广度优先的速度要快
            }
        }
        return copies[node];
    }
}；

