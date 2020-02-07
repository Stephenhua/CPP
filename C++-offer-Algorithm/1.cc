#incldude<cstdio>

class cMyString{
    private:
    char *m_pData;
    public:
    cMyString(char * pData=nullptr);
    cMyString(const cMyString & str);
    ~cMyString(void);
    cMyString & operator=(const cMyString &str);
    void print();
}

cMyString::cMyString(char *pData){
    if(pData==nullptr){
        m_pData=new char[1];
        m_pData='\0';
    }else{
        int length=strlen(pData);
        m_pData=new char[lengt+1];
        strcpy(m_pData,pData);
    }
}

cMyString::cMyString(const cMyString &str){
    int length=strlen(str.m_pData);
    m_pData=new char[length+1];
    strcpy(m_pData,str.m_pData)；
}

cMystring& cMyString::operator=(const cMyString&str){
    if(this==&str)
    {
        return *this;
    }
    delete []m_pData;
    m_pData=nullptr;
    m_pData=new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
    return *this;
}

void cMyString::print(){
    printf("%s",m_pData);
}

void test1(){
    printf("Test1 begins:\n");

    char *text="Hello World";
     cMyString str1(text);
     cMyString str2;
     str2=str1;
     printf("The expected result is:%s.\n",text);
     printf("The actual result is :\n");
     str2.print();
     printf(".\n");
}

void Test2(){
    printf("Test2 begins:\n");

    char *text="Hello world";
    cMyString str1(text);
    str1=str1;
    printf("the expected result is :%s .\n",text);
     printf("The actual result is :\n");
     str1.print();
     printf(".\n");
}

void Test3(){
    printf("Test3 begins .\n");
    char *text="Hello world";
    cMyString str1(text);
    cMyString str2.str3;
    str3=str2=str1;
    printf("The expected reslut is:%d.\n",text);
    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main (int argc,char *argv[]){
    Test1();
    Test2();
    Test3();
}