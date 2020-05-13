#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
给出一个数组A，找出一对 (i, j)使得A[i] <= A[j] (i <= j)并且j-i最大 ，若有多个这样的位置对，返回i最小的那一对。
*/

//方法一：每个i从数组最尾端开始向前找到第一个大于等于A[i]的位置j,时间复杂为O(n2)
int maxWidth(vector<int>& A){

    int n = A.size();

    int right = 0;
    int left = 0;

    int maxLength = 0;

    for( int i=0 ;i< n ;i++){

        int j ;

        for(  j = n-1 ;j > i ;j++){
            if( A[j] > A[i]){
                break;
            }
        }

        if( j-i+1 > maxLength){
            maxLength = j-i+1;
        }
    }
    return maxLength;
}

//方法二：当i=0时，我们假设找到的大于A[i]的最右位置是j0，那么对于i=1时，
//我们根本就不需要考虑小于j0的位置，因为它们的区间长度都小于j0+1，不可能成为最优解。

int maxWidth(vector<int>& A){

    int n = A.size();

    int right = 0;
    int left = 0;

    int maxLength = 0;

    for( int i=0 ;i< n ;i++){

        int j ;

        for(  j = n-1 ;j > right ;j++){
            if( A[j] > A[i]){
                break;
            }
        }

        if( j-i+1 > maxLength){
            left = i;
            right = j;
            maxLength = j-i+1;
        }
    }
    return maxLength;
}

//方法三：
/*
对于 i ，我们先找到 i 及其右端的最大元素的位置 j ，检查是否比当前记录的最优解更优，更新。
然后考虑 j+1及其右端的最大元素位置是否大于等于A[i]，若是，令 j 等于该位置，
重复如上过程，若否，那么从位置i+1重新开始，但j仍然从当前位置考虑即可，原因上面已说明。这样时间复杂度就成O(n)的了。

*/
pair<int, int> find(const vector<int> &A) 
{
	int n = A.size();
	if(n == 0)
		throw new invalid_argument("Array's size can't be 0!");

	vector<int> right_max_pos(n);
	right_max_pos[n-1] = n-1;
	for(int i = n-2; i >= 0; --i)
	{
		if(A[i] > A[right_max_pos[i+1]])
			right_max_pos[i] = i;
		else
			right_max_pos[i] = right_max_pos[i+1];
	}

	int max_len = 0;
	int target_i, target_j;
	int i = 0, j = 0;
	while(j < n)
	{
		j = right_max_pos[j];
		if(A[j] >= A[i])
		{
			if(j-i+1 > max_len)
			{
				target_i = i;
				target_j = j;
				max_len = j-i+1;
			}
			++j;
		}
		else
			++i;
	}

	return make_pair<int, int>(target_i, target_j);
}