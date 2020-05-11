#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

/*
题目：序列化和反序列化

*/

string  serialize( TreeNode* root){

    string res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        auto node =q.front();

        if(node){
            res += to_string(node->val)+' ';
            q.push(node->left);
            q.push(node->right);
        }else{
            res += "null";
        }
        q.pop();
    }

    return res;
}

    TreeNode* deserialize(string data) {
        //切割后的数据
        auto vals = split(data);
        //进行层次遍历法进行遍历，初始化的时候里面为空指针的；
        queue<TreeNode*> q;

        if(vals[0]=="null")return NULL;
        //将根节点放入到其中；

        q.push(new TreeNode(stoi(vals[0])));

        TreeNode *res=q.front();

        //将数据的规模进行缩小；

        for(int i=1;i<vals.size();){
            //依次进行遍历；
            if(vals[i]!="null"){
                auto p=new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->left=p;
            }
            //每次更新一位，则将会右移一位；
            ++i;
            if(vals[i]!="null"){
                auto p=new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->right=p;
            }
            ++i;
            q.pop();
        }
        return res;
    }
    //将字符串进行切割，然后将其放入到vector变量汇中
    vector<string> split(string &data){
        int start=0;
        vector<string> res;
        while(1){
            auto end = data.find(',',start);
            if(end==string::npos)break;
            res.push_back(data.substr(start,end-start));
            start=end+1;
        }
        return move(res);
    }