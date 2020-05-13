#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
using namespace std;


/*
题目：简化路径
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//方法一：采用栈的形式
string simplifyPath( string path){

    path += '/';

    stack<string> temp_stack;
    string temp_string;

    for( auto c:path){
        
        //两个'/'之间为单级目录子串
        if( c == '/'){
        //地址从前向后跳转，如两个'/'之间的地址字符串是“..”，切换上一级目录，即将最后压入的一级目录弹出
            if( temp_string == ".."){
//考虑特殊情况，如果前面没有进入子目录，一开始就是".."，此时既不能压入栈也无法弹出，需要排除，不做操作即可
                if( !temp_stack.empty()){
                    temp_stack.pop();
                }
//其他情况，如两个'/'之间的地址字符串存在，且不为'.'（同级目录，无变化），必为字母组成的地址，因此压入栈
            }else if( temp_string !="." && !temp_string.empty()){
                temp_stack.push( temp_string);
            }

//清空单级目录字符串，准备记录下两个'/'之间的目录字符串
            temp_string.clear();
//记录单级目录字符串
        }else{
            temp_string +=c;
        }
    }

    string result;

    while( !temp_stack.empty()){
        result ='/'+temp_stack.top() + result;
        temp_stack.pop();
    }

    if( result.empty()){
        result= "/";
    }

    return result;
}