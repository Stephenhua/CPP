#ifndef STRING_1_H_
#define STRING_!_H_
#include <iostream>
using namespace std;

class String{
    private:

         char* str;
         int len ;

         static int num_strings;

         static const int CLINLIM = 80 ;
    
    public:

        String(const char* s);//构造函数；
        String() ; // default constructor

        String( const String& st ) ;//copy constructor

        ~String() ; // default destructor;

        int length () const { return length; }

        String& operator= (const String & st);

        String& operator= (const char*);

        char & operator[] (int i );

        const char& operator[](int i ) const ;


        friend bool operator<(const String &st1 , const String & st2);
        friend bool operator>(const String& st1, const String& st2);
        friend bool operator==(const String& st1, const String& st2);
        friend ostream & operator<<( ostream& os, const String& st);
        friend istream & operator>>( istream& is , String& st);

        static int HowMany();
        
}