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
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }
        if(denominator==0){
            retrun " ";
        }

        string result;

        long long numer=static_cast<long long> numerator;
        long long denom= static_cast<long long > denominator;

        //处理正负号
        if((numer>0)^(denom>0)){
            result.push_back("-");
        }
        numer=abs(numer);
        denom=abs(denom);

        //处理整数部分

        result.append(to_string(numer/denom));

        //处理小数部分
        numer%=denom;
        if(numer==0){
            return result;
        }
        result.push_back(".");
        int index=result.size()-1;
        unordered_map<int ,int > record;
        while(num&& record.count(num)){
            record[num]=++index;
            num*=10;
            result+=to_string(numer/denom);
            num%=denom;
        }

        if(record.count(num)==1){
            result.insert(record[num],'(');
            result.push_back(")");
        }
        return result;       
    }
};

//方法二：class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        if(denominator==1) return to_string(numerator);
        int sign = (numerator>=0 && denominator>0 || numerator<0 && denominator<0)?1:-1;
        string res;
        res+=(sign==-1?"-":"");
        long n = labs(numerator);
        long d = labs(denominator);
        res+=(to_string(n/d));
        if(n%d==0) return res;
        res+=".";
        unordered_map<int, int> myMap;
        long r = n%d;
        for(; r; r%=d){
            if(myMap.count(r)!=0){
                res.insert(myMap[r], 1, '(');
                res+=')';
                return res;
            }
            myMap[r]=res.length();
            r*=10;
            res+=to_string(r/d);
        }
        return res;
    }
};