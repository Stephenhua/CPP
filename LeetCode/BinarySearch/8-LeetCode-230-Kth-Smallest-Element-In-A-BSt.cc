#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：二叉树中第k个数；
*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };