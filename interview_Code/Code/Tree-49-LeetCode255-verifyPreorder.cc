#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

/*
题目：验证前序遍历序列二叉所搜索树；
*/
/*
方法一：单调栈，
结论
维护一个单调递减的栈，以及最新pop出来的值。待push进栈的节点值必须大于已经pop出来的所有元素的值，才能是合法的BST。
思路
BST的性质是左子树小于root，右子树大于root，所以校验这个性质即可。
单调递减栈的单调性用来假设root到左子树的性质正确，再用待push进栈的节点值必须大于已经pop出来的所有元素的值来校验root到右子树的性质
得益于单调性，已经pop出来的所有元素的值是不断递增的，所以用最新的值来校验即可


链接：https://leetcode-cn.com/problems/verify-preorder-sequence-in-binary-search-tree/solution/dan-diao-zhan-xiao-yan-bstqian-xu-bian-li-by-shinn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

于一个搜索二叉树的前序序列来说, 如果某段序列为一个递减序列, 
说明这是一段沿着左子树的路径. 直到碰到一个比前一个大的值, 说明此时已经来到某个结点的右子树上了, 
而此时可以得出一个此后序列的下界值, 也就是此后序列的任意一个值必须要比这个结点的父结点的值大, 
因为对于搜索二叉树来说根节点左边的都比根节点小, 而根节点右边的都比根节点大, 
所以既然现在已经来到某个结点(设为A)的右子树上, 那么此后任何结点的值必然比A的值大. 

那么当我们碰到一个比之前结点大的值如何找到他的父结点呢? 可以借助一个栈, 即如果当前结点比栈顶元素小, 就入栈, 如果当前值大于栈顶值, 则让所有比当前结点小的值都出栈, 直到栈顶元素比当前结点大, 则最后一个出栈的比当前结点小的值就是当前结点的父结点, 我们只要在栈元素出栈的时候更新最小下界再将当前元素入栈即可. 另外这样的时间和空间复杂度都是O(n), 但是对于空间复杂度来说, 很容易复用原数组模拟栈来优化.
————————————————
版权声明：本文为CSDN博主「小榕流光」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq508618087/article/details/50929129
作者：shinnqy
*/
bool verifyPreorder(vector<int>& preorder) {

    int k =-1 ,Min = INT_MIN;

    for( auto val : preorder){
        if( val <Min){
            return false;
        }

        while( k>=0 && val >preorder[k]){
            Min = preorder[k--];
        }

        preorder[++k] = val;
    }

    return true;

}

//方法二：新建一个栈，从而速度更快；

bool verifyPreorder( vector<int>& preorder){

    int low  = INT_MIN;

    stack<int> s;

    for( auto v:preorder){
        if(  v < low){
            return false;
        }

        while( !s.empty() && v > s.top()){
            low = s.top();
            s.pop();
        }

        s.push(v);
    }

    return true;
}