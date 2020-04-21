#include<stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
题目：两个字符串的编辑距离-动态规划方法
链接：https://blog.csdn.net/ac540101928/article/details/52786435

问题描述：给定两个字符串A和B，求字符串A至少经过多少步字符操作变成字符串B。 

建立动态规划方程：用edit[i][j]表示A串和B串的编辑距离。
edit[i][j]表示A串从第0个字符开始到第i个字符和B串从第0个字符开始到第j个字符，
这两个字串的编辑距离。字符串的下标从1开始
 dis[0][0]表示word1和word2都为空的时候，此时他们的Edit Distance为0。
 很明显可以得出的，dis[0][j]就是word1为空，word2长度为j的情况，此时他们的Edit Distance为j，也就是从空，
 添加j个字符转换成word2的最小Edit Distance为j；同理dis[i][0]就是，word1长度为i，word2为空时，
 word1需要删除i个字符才能转换成空，所以转换成word2的最小Edit Distance为i。

动态规划方程：
edit[i-1][j]+1相当于给word2的最后插入了word1的最后的字符，插入操作使得edit+1，之后计算edit[i-1][j]；

edit[i][j-1]+1相当于将word2的最后字符删除，删除操作edit+1，之后计算edit[i][j-1];

edit[i-1][j-1]+flag相当于通过将word2的最后一个字符替换为word1的最后一个字符。flag标记替换的有效次数。

*/
char s1[1000],s2[1000];

int min ( int a, int b,int c){
    int temp = a>b?b :a;
    return temp>c ?c :temp;
}

void editDistance( int len1 ,int len2){

    int **d  = new int*[len1+1];
    for(int i=0; i<=len1 ;i++){
        d[i] = new int [len2+1];
    }

    int i,j ;

    for(int i=0;i<=len1 ;i++){
        d[i][0] = i;
    }

    for(int j=0 ;j<=len2 ;j++){
        d[0][j] = j;
    }

    for(int i =1 ;i <=len1 ;i++){
        for( int j=1 ; j<=len2 ;j++){
            int temp = s1[i-1] == s2[i-1] ? 0 :1 ;

            int deletion = d[i-1][j]+ 1;

            int insertion = d[i][j-1] +1;

            int substitution = d[i-1][j-1] + temp;

            d[i][j] = min( deletion , insertion , substitution);
        }
    }
    cout <<"Distance"<< d[len1][len2];

    for(int i= 0 ;i <= len1 ;i++){
        delete [] d[i];
    }
    delete[] d;
 }

 int main(){
     while(scanf("%s %s",s1,s2)!=EOF){

         editDistance(strlen(s1) , strlen(s2));
     }
     system("pause");
     return 0;
 }