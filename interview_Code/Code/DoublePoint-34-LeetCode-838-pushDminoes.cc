#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
838. 推多米诺
一行中有 N 张多米诺骨牌，我们将每张多米诺骨牌垂直竖立。

在开始时，我们同时把一些多米诺骨牌向左或向右推。



每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。

同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果同时有多米诺骨牌落在一张垂直竖立的多米诺骨牌的两边，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为正在下降的多米诺骨牌不会对其它正在下降或已经下降的多米诺骨牌施加额外的力。

给定表示初始状态的字符串 "S" 。如果第 i 张多米诺骨牌被推向左边，则 S[i] = 'L'；如果第 i 张多米诺骨牌被推向右边，则 S[i] = 'R'；如果第 i 张多米诺骨牌没有被推动，则 S[i] = '.'。

返回表示最终状态的字符串。

示例 1：

输入：".L.R...LR..L.."
输出："LL.RR.LLRRLL.."
示例 2：

输入："RR.L"
输出："RR.L"
说明：第一张多米诺骨牌没有给第二张施加额外的力。
提示：

0 <= N <= 10^5
表示多米诺骨牌状态的字符串只含有 'L'，'R'; 以及 '.';

*/


/*
双指针法进行讨论：
1） L R；中间的部分不改变；
2） L L ; 中间的部分都为LL；
3) R R ; 中间的部分都为R；
4) R L ;中间的部分需要讨论： 
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;

        char temp1 = 'N' ;//用于识别上一个是什么字符；

        int  index = -1; 

        for( int i = 0 ;i < dominoes.size() ;i++){

            if( dominoes[i] == 'L'){

                if( temp1 == 'N'){
                    trans(dominoes,0,i-1,'L');

                }else if( temp1 == 'L'){

                    trans(dominoes,index+1,i-1,'L');

                }else {//此时需要分类讨论
                    int mid = ( i-index-1)/2;

                    trans( dominoes,index+1,index+mid,'R');
                    trans( dominoes,i-mid,i-1,'L');
                }
                temp1 = 'L';
                index = i;
            }else if( dominoes[i] == 'R'){
                if( temp1 == 'R'){
                    if( index+1 <= i-1 ){
                        trans(dominoes,index+1,i-1,'R');
                    }

                }
                temp1 = 'R';
                index = i;
            }
        }

        if( temp1 == 'R'){
            trans( dominoes,index+1, dominoes.size()-1,'R');
        }

        return dominoes;

    }

        void trans( string& s, int left , int right , char lr){
        if( left <= right){

            for( int i = left ;i <= right ;i++){
                s[i] = lr;
            }
        }
    }
};

//方法二：
class Solution {
public:
    string pushDominoes(string dominoes) {

        //用于存放前一个L和R的下标；

        int startR = -1, startL = -1;

        //遍历整个字符串；
        for (int i = 0; i < (int)dominoes.size(); i++) {
            //如果当前状态为L，
            if (dominoes[i] == 'L') {
                //判断前一个L和R的位置关系，如果L大于R，那么直接复制为L，并更新L和R的位置；
                if (startL >= startR) {
                    while (startL < i) {
                        dominoes[startL + 1] = 'L';
                        startL++;
                    }
                    startR = startL;
                }//如果当前L小于R的话，那么则R。。。 L之间将会发生移动。更新了StartL和STartR的位置；
                else if (startL < startR) {
                    //更新startL的位置；
                    startL = i;
                    for (int j = startR, k = startL; j < k; j++, k--) {
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                    }
                }
            }//如果当前状态是人R；
            else if (dominoes[i] == 'R') {
                //如果R大于L的话，那么直接全部都是R；
                if (startR > startL) {
                    while (startR < i) {
                        dominoes[startR + 1] = 'R';
                        startR++;
                    }
                }
                //更新R位置；
                startR = i;
            }
        }
        //遍历完之后，如果R最后，那么最后部分的位置将会重新赋值；
        if (startR > startL) {
            while (startR < (int)dominoes.size() - 1) {
                dominoes[startR + 1] = 'R';
                startR++;
            }
        }
        return dominoes;
    }
};