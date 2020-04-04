#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include "string.h"
using namespace std;

class cMyString{
    friend std::ostream& operator<<(std::ostream& os ,const CMyString& str );

    private:
    char * p_Data;

    public:
        cMyString(const char* str=nullptr);//构造函数

        cMyString(const cMyString& str);//拷贝构造函数；

        ~cMyString(void ) ; //析构函数

        cMyString & operator=(const cMyString& str); // 赋值运算符；

        cMyString operator+( const cMyString& str); //字符创链接；

        bool operator==(const cMyString& str); //值相等；

        char operator[] (int idx); //索引数组；

        int getLength();// 返回长度；
};

cMyString::cMyString(const char* str){
    if(!str){

        this->p_Data = 0;

    }else{

        this->p_Data = new char[strlen(str)+1];

        strcpy(this->p_Data,str);

    }

}

cMyString::cMyString(const cMyString& str){
    if(!str.p_Data){
        this->p_Data = 0;
    }else{
        this->p_Data = new char [strlen(str.p_Data)+1];
        strcpy( this->p_Data , str.p_Data);
    }
}


cMyString::~cMyString(void ){
    if(this->p_Data){
        delete [] this->p_Data;
        this->p_Data = 0;
    }
}

cMyString& cMyString::operator=(const cMyString& str){
    if(this!= &str){
        delete[] this->p_Data;
        if(!str.p_Data){
            this->p_Data = 0;
        }else{
            this->p_Data = new char [strlen(str.p_Data)+1];
            
            strcpy( this->p_Data, str.p_Data);
        }
    }

    return false;
}

//加法运算符
cMyString cMyString::operator+( const cMyString & str){
    
    cMyString newString;
    if(!str.p_Data){
        newString= *this;
    }else if( !this->p_Data){
        newString =str;
    }else{
        newString.p_Data = new char [strlen[str.p_Data]+1]+strlen(this.p_Data)];
        
        strcpy(newString, this->p_Data);
        strcpy( newString.p_Data, str.p_Data);
    }
}

bool cMyString::operator==(const cMyString& str){
    if(strlen(this->p_Data) != strlen(str.p_Data)){
        return false;
    }else{
        return strcmp(this->p_Data , str.p_Data) ? false:true;
    }
}


int cMyString::getLength(){
    return strlen(this->p_Data);
}

std::ostream & operator<<( std::ostream& os ,const cMyString& str){
    os<< str.p_Data;
    return os;
}