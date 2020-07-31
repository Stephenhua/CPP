#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
题目：
小明已经开始准备放大他的n的恐龙蛋，他把他们放在他自制的n个放大器，其中第i个放大器每天可以使放在上面的恐龙蛋增大i个尺寸；
按照恐龙蛋的大小，从大到小进行排列，如果想要孵化两个一样大的恐龙蛋，最早多少天就可以实现；

输入描述：
第一行：整数n,n表示恐龙蛋的个数；
第二行：n个整数，表示其中第i个整数ai表示放在第i个放大器的恐龙蛋大小；

输出描述：输出一个整数表示最早几天后会有一个恐龙蛋会变成一样大；

3 
8 4 2

*/

/*
解题思路：
作者：tuogy
链接：https://www.nowcoder.com/discuss/462000
来源：牛客网

根据题意，相邻的恐龙蛋增长速度相差为1。因此，如果相邻蛋的大小差异数组d为{d1, d2, …, dn-1}，那么每经过1天，数组d中每个元素都会减少1。
当d中首次出现0元素时，就是首次出现两个相同大小恐龙蛋的时候。这很容易证明，因为根据题设，d中的元素均非负。在d中出现0元素之前，恐龙蛋大小是严格递减的，不存在相同大小的蛋。
很显然，d中首次出现0元素的天数，就是数组d中的最小值。数组d及其最小值可以在O(n)时间内计算得到。算法的时间复杂度为O(n)。
*/

int solve(){
    int n ,ret = INT_MAX;

    cin >> n ;

    for(int i = 0 , prev = INT_MAX, cur = 0 ; i < n ; i++){

        cin >> cur ;
        ret = min( ret, prev-cur);
        prev = cur;
    }

    return ret;
}

int main(){
    
    int res = solve();
    cout << res <<endl;
    system("pause");
    return 0 ;

}