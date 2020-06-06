#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
212. 单词搜索 II
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

*/


//=====================================方法一==========================================
/*
思路：首先构建Trie树，将字典中的单词进行Trie话；
2）遍历每一个矩阵作为一个点的起点，backtrack；
        backtrack的主要思路：
        1）首先，回溯的终止条件，到达矩阵的边界或者当前节点遍历 ，直接return；
        2） 将string str 加入当前节点，并将is_visit设置为true；
        3）如果前缀书包含此字节点，且此字节点是前缀树中的最终字符，就将其加入到结果中；
        4）如果前缀树搜索含有这个前缀，就就绪上下搜索；
        5）最后进行回溯，将加进去的字符删除；

*/


class Trie {

private:

    bool isEnd; //该结点是否是一个串的结束
    Trie* next[26];//字母映射表

public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd =false;
        memset( next ,0 ,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        Trie* node = this;

        for( char c :word){
            if( node->next[c-'a'] == nullptr){
                node->next[c-'a'] = new Trie();
            }

           node=  node->next[c-'a'];
        }
        node->isEnd = true;

    }
    
    /** Returns if the word is in the trie. 
     * *描述：查找 Trie 中是否存在单词 word

        实现：从根结点的子结点开始，一直向下匹配即可，如果出现结点值为空就返回false，如果匹配到了最后一个字符，那我们只需判断node->isEnd即可。
     * 
     * 
    */
    bool search(string word) {

        Trie* node = this;

        for( char c :word){
            node = node->next[c-'a'];

            if(node == nullptr){
                return false;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */

/*
*前缀匹配
描述：判断 Trie 中是或有以 prefix 为前缀的单词

实现：和 search 操作类似，只是不需要判断最后一个字符结点的isEnd，因为既然能匹配到最后一个字符，那后面一定有单词是以它为前缀的。
*
*/
    bool startsWith(string prefix) {
        
        Trie* node = this;

        for( char c :prefix){
            node = node->next[c-'a'];
            if( node == nullptr){
                return false;
            }
        }
        return true;

    }
};

vector<string> res;
Trie root ;

void backTrace( int row, int col ,string& str, vector<vector<bool>>& isvisit,vector<vector<char>>& board){

    //退出回溯的条件，到达矩阵的边界或者当前节点遍历 ，直接return；

    if( row > board.size()-1 || row <0 || col <0 || col > board[0].size()-1){
        return;
    }
    //节点访问过，则直接跳过；
    if( isvisit[row][col]){
        return;
    }


    //将当前str加入到string中；

    str.push_back( board[row][col]);

    isvisit[row][col] = true;


    //在root中进行查找，是否存在；

    if( root.search(str)){

        vector<string>::iterator it = find( res.begin() ,res.end() ,str);

        if( it == res.end()){

            res.push_back(str);
        }
    }

    //ru如果前缀搜索树含有这个前缀，就继续进行上下搜索；

    if( root.startsWith(str)){

        backTrace( row-1,col,str,isvisit,board);
        backTrace(row,col+1,str,isvisit,board);
        backTrace(row ,col-1,str,isvisit,board);
        backTrace(row+1,col,str,isvisit,board);

    }

    str.pop_back();
    isvisit[row][col] = false;
    return;


}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {


    //构建Trie树；
    for( string word:words){    
        root.insert(word);
    }
    int rows  = board.size();
    int cols = board[0].size();


    for(int row = 0 ; row < rows ; row++ ){
        for( int col = 0 ; col <cols ; col++){

            string str;
            vector<vector<bool>> isvisit(rows,vector<bool>(cols, false));
            backTrace(row,col,str,isvisit,board);
        }
    }
    return res;
}



//=====================================方法二==========================================

class Tire{
    private:
        bool isEnd;
        Tire * next[26];
        string str;
    public:
        Tire(){

            isEnd = false;

            memset(next,0,sizeof(next));

        }   

        void insert( string  word){
            Tire* node = this;

            for( char c:word){

                if(node->next[c-'a'] == nullptr){
                    node->next[c-'a'] = new Tire();
                }
                node = node->next[c-'a'];
            }
            node->isEnd= true;
            //将word进行存储；
            node->str = word;
        }

        void search( vector<string>& result, vector<vector<char>>& board){

            Tire* node = this;

            for( int i = 0 ;i <board.size() ;i++){
                for( int j = 0 ; j< board[0].size() ;j++){

                    Core( result,board,i,j,node);
                }
            }
        }

        void Core( vector<string>& result, vector<vector<char>>& board, int x, int y ,Tire * node){
            if( node->isEnd == true){

                node->isEnd = false;//为了避免同样的单词重复查找；

                result.push_back( node->str);

                return;

            }

            if( x < 0 || x ==  board.size() || y<0 || y == board[x].size()){
                return;
            }

            if( board[x][y] == '0' ||node->next[board[x][y]-'a'] == nullptr){
                return;
            }


            node = node->next[ board[x][y]- 'a'] ;
            char temp = board[x][y];
            board[x][y] = '0';
            Core( result,board,x+1,y,node);
            Core( result, board, x-1,y,node);
            Core( result, board,x,y+1, node);
            Core( result,board, x,y-1,node);

            board[x][y] = temp;

        }   
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        Tire *root=new Tire();

        vector<string>result;

        for(auto word:words){

            root->insert(word);

        }

        root->search(result,board);

        return result;
    }
};