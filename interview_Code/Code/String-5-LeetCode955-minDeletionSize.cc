#include <string.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
/*
题目：删列造序 
给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。

选取一个删除索引序列，对于 A 中的每个字符串，删除对应每个索引处的字符。

比如，有 A = ["abcdef", "uvwxyz"]，删除索引序列 {0, 2, 3}，删除后 A 为["bef", "vyz"]。

假设，我们选择了一组删除索引 D，那么在执行删除操作之后，最终得到的数组的元素是按 字典序（A[0] <= A[1] <= A[2] ... <= A[A.length - 1]）排列的，然后请你返回 D.length 的最小可能值。

 

示例 1：

输入：["ca","bb","ac"]
输出：1
解释： 
删除第一列后，A = ["a", "b", "c"]。
现在 A 中元素是按字典排列的 (即，A[0] <= A[1] <= A[2])。
我们至少需要进行 1 次删除，因为最初 A 不是按字典序排列的，所以答案是 1。
示例 2：

输入：["xc","yb","za"]
输出：0
解释：
A 的列已经是按字典序排列了，所以我们不需要删除任何东西。
注意 A 的行不需要按字典序排列。
也就是说，A[0][0] <= A[0][1] <= ... 不一定成立。
示例 3：

输入：["zyx","wvu","tsr"]
输出：3
解释：
我们必须删掉每一列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-columns-to-make-sorted-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：用时最短；
//分为两种情况讨论，如果第i行和第i+1行直接是大于关系，则直接进行判断下一列；
//如果是相等关系，则需要进行辅助vector进行判断，为下一列的判断提供依据，为false情况，true的时候表明当前是没有问题的
//前一列的判断依旧可以作为下一列的判断依据；如果前一列已经判断是这个是递增的，那么下一列对于递增和递减将不会发生变化；
int minDeletionSize( vector<string>& A){
    int res = 0 ;
    int n= A.size();//获得行
    int m = A[0].length();//获得列
    int i,j;
    vector<bool> sorted( n-1, false);//用于标记行有问题；

    for( j = 0 ;j < m ;++j){
        for( i= 0 ;i <n-1 ;++i){
            //如果不符合条件，则进行标记；只是对A[i][j]和 A[i+1][j]进行大于判断，只要大于肯定不符合条件，直接进行break退出；
            if( !sorted[i] && A[i][j] >A[i+1][j]){
                res++;
                break;
            }
        }
        //前面不符合条件，则i< n -1 ；所以下面无须做判断，直接进行下一列的判断；
        //如果当前的i小于最后的行时，表明中间就出现了上述的问题；
        if( i < n-1){
            continue;
        }
        //对于存在想等的情况进行判断，需要进行下一轮的判断；
        for( i = 0; i< n-1 ;i++){
            sorted[i] = sorted[i] || A[i][j] < A[i+1][j];
        }
    }
    return res;
}

	void setFlag(bool *flag, int index, vector<string>& A) {
		for (int i = 1; i < A.size(); i++) {
			if (A[i][index] > A[i - 1][index]) {
				flag[i] = true; // 表明第i行和第i-1行之间严格的大小关系已经确定了。
			}
		}
	}

	int minDeletionSize2(vector<string>& A) {
		bool *flag = new bool[A.size()]{ false }; // flag[i]表明第i个元素和第i-1个元素之间形成了严格的大小关系
		// 找出start点
		int start = -1;
		for (int i = 0; i < A[0].size() && start<0; i++) {
			int j = 1;
			for (; j < A.size(); j++) {
				if (A[j][i] < A[j - 1][i]) {
					break;
				}
			}
			if (j == A.size()) start = i; // 表明第i列首先出现非递减序列
		}
		if (start < 0) return A[0].size(); // 不存在该序列
		setFlag(flag, start, A); // 更新flag表

		// 开始遍历string
		int count = (start > 0) ? start : 0; // 开始计数
		for (int i = start + 1; i < A[0].size(); i++) {
			int j = 1;
			for (; j < A.size(); j++) {
				if (A[j][i] < A[j-1][i] && flag[j] == false) {
					count++; // 出现递减序列但是之前记录的信息表明A[k][i]和A[k-1][i]并非严格递增关系
					break; // 即A[k][i] <= A[k-1][i]，所以此列不符合条件。
				}
			}
			if (j == A.size()) { // 若当前列满足条件，更新flag表
				setFlag(flag, i, A);
			}
		}
		return count;
	}

//方法三：利用一个set进行去存；
/*
1） 当 a[i] < a[i+1]时， 直接break，进行下一行的必较；
2）当存在a[i] == a[i+1]时 ，表明其需要比较后的列，则采用continue的方法；
3）但是当出现递减时，则直接将列的序号插入到当中，并且令行为0 ；重新开始遍历；
4) 每一次都要进行比较，；
*/
int minDeletionSize3( vector<string>& A){
    unordered_set<int> di ;

    for( auto i = 1 ;i <A.size() ;++i){
        for( auto  j= 0 ;j <A[i].size() ;++j){

            if( di.count(j) >0 ||A[i-1][j] == A[i][j]){
                continue;
            }

            if( A[i-1][j] > A[i][j]){
                di.insert(j);
                i = 0;
            }
            break;
        }
    }
        return di.size();
}

int main( int argc , char* argv[]){
    string s1=  "aabg";
    string s2 = "adch";
    string s3 = "badi";
    string s4 = "baaj"; 

    vector<string> s;
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    s.push_back(s4);

    int result = minDeletionSize(s);
    int result2 = minDeletionSize2(s);
    int result3 =minDeletionSize3(s);


    cout << result <<endl;
    cout <<result2 <<endl;
    cout <<result3 <<endl;
    
    system("pause");
    return 0 ;
}