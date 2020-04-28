#include <iostream>
#include <string.h>
#include <cmath>

using  namespace std ;
/*
题目：满二叉树的祖先节点
有一个无穷高的满二叉树，层次遍历从小到大编号，根结点从1开始，
第二行是“2 3”，第三行是“4 5 6 7”……对于编号为n的结点，
求其高度为k的祖先节点，若不存在则返回-1.
http://www.360doc.com/content/19/0303/18/32937624_818850914.shtml
*/

int main (){

    int Q ;
    cin >>Q ;

    for( int i = 0;i <Q ;i++){

        long long x; 
        int k ;
        cin >> x >> k;

        int height  = (log(x)/log(2)+1);

        if( k >= height){
            cout << "-1" <<endl;
        }else{
            long long ret = x >>(height-k);
            cout <<ret <<endl;
        }
    }

    system("pause");
    return 0;

}
