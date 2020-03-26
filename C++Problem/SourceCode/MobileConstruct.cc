#include <iostream>
#include <stdlib.h>    
#include <crtdbg.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <vector>

using namespace std;
class String;
ostream& operator<<(ostream& out,String& s);
class String{
public:
    friend ostream& operator<<(ostream& out, String& s);
public:
    String(const char* data = "")
    {
        if (data == NULL)
        {
            m_data = new char[1];
            m_data[0] = '\0';
        }
        else
        {
            m_data = new char[strlen(data) + 1];
            strcpy(m_data, data);
        }
        cout << "constructor execute..." << endl;
    }

    String(String &&s)noexcept//移动构造函数；
    {
        cout << "move constructor execute..." << endl;
        m_data = NULL;
        this->m_data = s.m_data;
        s.m_data = NULL;
    }

    ~String()
    {
        cout << this<<"free execute..." << endl;
        if(m_data != NULL)
            delete[] m_data;
    }
private:
    char* m_data;

};

ostream& operator<<(ostream& out, String& s)
{
    out << s.m_data;
    return out;
}

int main()
{
    String s = "hello";
    vector<String> vs(1);
    vs.push_back(std::move(s));
    system("pause");
    return 0;
}