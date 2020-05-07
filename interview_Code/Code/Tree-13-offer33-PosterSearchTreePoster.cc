#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
using namespace std;

/*
题目：二叉搜索树的后序遍历
*/
bool VerifySquenceOfBSTCore( vector<int>& nums, int start ,int end){

    if( start >= end){
        return true;
    }

    int root =  nums[end-1];

    int  i = start ;
    for(;i<end ;i++){
        if( nums[i] > root){
            break;
        }
    }

    int j = i;
    int mid = i;

    for( ; j<end;j++){
        if( nums[j] < root){
            return false;
        }
    }


    return VerifySquenceOfBSTCore( nums,start,i-1) && VerifySquenceOfBSTCore( nums, i,end -1);  

}
bool VerifySquenceOfBST( vector<int>& nums){

    if( nums.empty()){
        return false;
    }
    
    if( nums.size() == 1){
        return true;
    }
    int start = 0 ;
    int end= nums.size();
    return VerifySquenceOfBSTCore( nums, start ,end);
}



// ====================测试代码====================
void Test(const char* testName, vector<int>& sequence, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    vector<int> data = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    vector<int> data= {4, 6, 7, 5};
    Test("Test2", data,true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    vector<int> data = {1, 2, 3, 4, 5};
    Test("Test3", data, true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    vector<int> data = {5, 4, 3, 2, 1};
    Test("Test4", data,true);
}

// 树中只有1个结点
void Test5()
{
    vector<int> data = {5};
    Test("Test5", data, true);
}

void Test6()
{
    vector<int> data = {7, 4, 6, 5};
    Test("Test6", data, false);
}

void Test7()
{
    vector<int> data = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data,  false);
}
/*
void Test8()
{
    Test("Test8", nullptr,  false);
}

*/
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    //Test8();

    system("pause");
    return 0;
}