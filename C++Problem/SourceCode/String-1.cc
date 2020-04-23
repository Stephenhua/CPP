#include <cstring>
#include <iostream>
#include "String-1.h"
using  namespace std ;  

int String::num_strings = 0 ;

//静态类方法
int String::HowMany(){
    return num_strings;
}


//构造函数
String::String(const char * s){

    len = strlen(s);

    str = new char[len+1];

    strcpy( str, s);

    num_strings++;

}

//默认构造函数

String::String(){
    int len =4 ;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

//赋值构造函数

String::String(const String& st){
    num_strings++;
    len = st.len;

    str = new char [len+1];

    strcpy(str,st.str);
}

String::~String(){
    num_strings--;

    delete[] str;
 }

 String& String::operator=(const String &st){

     if(this ==&st){
         return *this;
     }

     delete[] str;

     len = st.len();
     str = new char[len+1];
     std::strcpy(str, st.len);
     return *this;
 }

 String& String::operator=(const char* s){
     delete[] str;

     len = std::strlen(s);

     str = new char[len+1];

     std::strcpy(str, s);
     
     return *this;
  }

  char& String::operator[](int i){
      return str[i];
  }

bool operator<(const String &st1 , const String & st2){
    return strcmp(st1.str , st2.str)<0;
}

bool operator>(const String& st1, const String& st2){
    return st2< st1;
}

bool operator==(const String& st1, const String& st2){
    return strcmp(st1.str ,st2.str)==0;
}

ostream & operator<<( ostream& os, const String& st){
    os<< st.str;
    return os ;
}

istream & operator>>( istream& is , String& st){
    char temp[String::CLINLIM];
    is.get(temp , String::CLINLIM);
    if(is){
        st= temp;
    }
    while( is&& is.get() !='\n'){
        continue ; 
    }

    return is ;
}
