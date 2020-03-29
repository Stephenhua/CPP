#include <iostream>
#include<algorithm>
//#include <cmath>
#include <cstdlib>
//using namespace std;

bool g_InvalidTnput=false;
bool equal(double num1,double num2);
double PowerWriteUnsignedWxport(double base,unsigned int exponent);

double Power(double base, int exponent){
    g_InvalidTnput=false;
    if(equal(base,0.0)&&exponent==0){
        g_InvalidTnput=true;
        return 0.0;
    }

    unsigned int  absExponent=(unsigned int )(exponent);
    if(exponent<0){
        absExponent=(unsigned int )(-exponent);
    }
    double result= PowerWriteUnsignedWxport(base,absExponent);
    if(exponent<0){
        result=1/result;
    }
    return result;
}
//方法二：采用斐波诺数列进行求解；以递归的方法进行求解；

double PowerWriteUnsignedWxport(double base,unsigned int exponent){
    if(exponent==0){
        return 0;
    }
    if(exponent==1){
        return base;
    }
    double result= PowerWriteUnsignedWxport(base,exponent>>1);
    result*=result;
    if((exponent&0x1)==1){
        result*=base;
    }
    return result;

}


//方法三：采用而二进制的形式进行求解；
double PowerWriteUnsigned(double base ,unsigned int exponet){
    if(base==1){
        return 1;
    }
    if (exponet<0 && base==0 ){
        return -1;
    }

    if(exponet== 0 ){
        return 1;
    }

    int number=abs(exponet);
    long sum=1;
    while(number){
        if(number &0x1){
            sum*=base;
        }
        base*=base;
        number=number>>1;
    }
 
    return (exponet>0)?sum:(double)1/sum;
}

bool equal(double num1,double num2){
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false; 
}

void Test(const char*testName ,double base , double exponent,double expectedResult, bool expectedFlag){
    double result=Power(base,exponent);
    double result3=PowerWriteUnsigned(base,exponent);

    if(equal(result,expectedResult)&&g_InvalidTnput==expectedFlag){
        std::cout<<testName<<"passed"<<std::endl;
    }else{
       std::cout<<testName<<"failed"<<std::endl; 
    }

    if(equal(result3,expectedResult)){
        std::cout<<testName<<"passed3"<<std::endl;
    }else{
       std::cout<<testName<<"failed3"<<std::endl; 
    }

}
int main(int argc, char *argv[]){
     // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);
    system("pause");
    return 0;

}


