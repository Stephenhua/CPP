#include  <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
题意：对于两个不同长度的数组，寻找中位数；

解析：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/

时间复杂度：log（n);

*/

double findMedianSortArrays( vector<int>& nums1, vector<int>& nums2){

    int n = nums1.size();

    int m = nums2.size();

    //保证数组1 一定是最短的；
    if( n>m ){
        return findMedianSortArrays(nums2,nums1);
    }
    //Ci表示第i个数组的割，比如C1为2时，表示第1个数组只能有2个元素；LmaxI表示第i个数组割后的左元素，
    //Rmin表示第i个数组割后的右元素；
    //虚拟加了'#'所以数组1是2*n长度

    int LMax1 ,RMin1 , LMax2 ,RMin2,c1 ,c2 ,lo=0, hi = 2*n;

    while( lo <= hi ){

        c1 =(lo+hi)/2;
        c2 = m+n -  c1;//在哪个位置进行切割；
        //根据奇偶性质的不同，然后进行归一化乘以2 ，进行整合；
        
        LMax1 = (c1 == 0)?INT_MIN : nums1[(c1-1)/2];
        RMin1 =( c1 == 2*n)?INT_MAX : nums1[(c1)/2];

        LMax2 = ( c2 == 0) ? INT_MIN :nums2[(c2-1)/2];
        RMin2 = ( c2 == 2*m)?INT_MAX : nums2[c2/2];

        if( LMax1 > RMin2){

            hi = c1 -1;

        }else if(LMax2 >RMin1){

            lo = c1+1;

        }else{
            break ;
        }
    }

    return (max(LMax1,LMax2) +min(RMin2,RMin1))/2;

}

int main(int argc, char *argv[])
{
	vector<int> nums1 = { 2,3, 5 };
	vector<int> nums2 = { 1,4,7, 9 };
	double ret = findMedianSortArrays(nums1, nums2);

    cout <<"result " <<ret <<endl;

    system("pause");

	return 0;
}
