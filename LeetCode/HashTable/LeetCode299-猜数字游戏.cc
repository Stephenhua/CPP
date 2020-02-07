#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int * temp=new int [10]();
        int A =0;
        int B=0;
        string result ;
        //寻找公牛
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                A++;
                guess[i]='A';
                continue;
            }
            temp[secret[i]-'0']++;
        }

        //寻找母牛
        for(int j=0;j<secret.size();j++){
            if(guess[i]=='A'){
                continue;
            }else if(temp[secret[i]-'0']>0){//如果这个值大于1，比表明该值存在于答案中
                B++;
                temp[guess[i]-'0']--;
            }

        }

        result.append(to_string(A)+"A"+to_string(B)+"B");
        return result;

    }

};

//方法一：采用排除法的形式进行判断；

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0,cows = 0;
        int rec[10] = {0};
        for(auto c:secret) rec[c - '0']++;
        for(int i = 0;i < secret.size();i++){
            if(secret[i] == guess[i]){ 
                bulls++;
                if(rec[secret[i] - '0'] <= 0) cows--;
                rec[secret[i] - '0']--;//去掉公牛的的元素；
              }else if(rec[guess[i] - '0'] > 0 ){
                cows++;//增加母牛的数量；
                rec[guess[i] - '0']--;//去掉元素
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};