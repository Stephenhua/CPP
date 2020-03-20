
/*#二维数组中的查找
# 在一个二维数组中，每一行都按照从左到右递增得顺序排序，每一列都按照从上到下递增的顺序进行排序，判断一个数是否在该二维数组中

#解题思路：
# 首先判断矩阵最右上角的元素，如果该元素时是直接查找的值，则直接进行返回，否则进行下一个环节；
# 在第二个环节中，如果元素大于有上角的元素，则进行直接进行相加，则剔除该行；
# 如果元素大于要找的元素，则直接将该列删除，从而在此循环；
*/

#include<unordered_map>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

bool Find(int *matrix, int rows ,int columns ,int number){
    bool found =false;

    int column=columns-1;
    int row=0;
    if(matrix==nullptr || rows<0 ||columns<0){
        return false;
    }
    //加上边界限定
   if(number<matrix[0]|| number>matrix[(rows-1)*(columns-1)]){
        return false;
    }

    while(row<rows &&column>=0){
        if (matrix[row*columns+column]==number){
            return true;
            break;
        }else if(matrix[row*columns+column]>number){//如果大于右上角，则同一行的元素都不适合，则进行加加运算
            --column;
        }
        else{
            ++row;
        }
    }
}

//测试代码

void Test(char* testName, int *matrix ,int rows ,int columns ,int number, bool expected){

    if(testName!=nullptr){
        cout<<"begins"<<testName<<endl;
    }

    bool result=Find(matrix,rows,columns,number);

    if(result ==expected){
        cout<<"passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }

}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
    Test("Test7", nullptr, 0, 0, 16, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    system("pause");
    return 0;
}