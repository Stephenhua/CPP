#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

/*
题目：
根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<int> dailyTempture( vector<int> tempture){

    int n = tempture.size();

    stack<int> index; 
    vector<int> result(n,0) ;



    for(int i = 0; i< n ;i++){

        while( !index.empty() && tempture[i] >tempture[index.top()]){
            
            int top = index.top();

            index.pop();

            result[top] = i - top;
        }

        index.push(i);
    }

    return result;
}

int main( int argc ,char* argv[]){

    vector<int> temp = {32 ,42,12,23,24,25};

    vector<int> result = dailyTempture( temp);

    for(int i=0 ;i <result.size() ;i++){
        cout<< result[i] ;
    }
    cout <<endl;

    system("pause");
    return 0 ;
}