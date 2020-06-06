#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//前缀数的情况和其他情况相似；https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/
/**
 * 通过以上介绍和代码实现我们可以总结出 Trie 的几点性质：

Trie 的形状和单词的插入或删除顺序无关，也就是说对于任意给定的一组单词，Trie 的形状都是唯一的。

查找或插入一个长度为 L 的单词，访问 next 数组的次数最多为 L+1，和 Trie 中包含多少个单词无关。

Trie 的每个结点中都保留着一个字母表，这是很耗费空间的。如果 Trie 的高度为 n，字母表的大小为 m，最坏的情况是 Trie 中还不存在前缀相同的单词，那空间复杂度就为 O(m^n)。

作者：huwt
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */

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