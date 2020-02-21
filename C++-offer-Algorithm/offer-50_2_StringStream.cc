#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>

/*
该方法主要是针对数据流的方式，字符流中第一个只出现一次的字符
*/
using namespace std;

class Solutions{
    private:
        int occurence[256];
        int index;
    public :
    Solutions():index(){
        for(int i=0;i<26;i++){
            occurence[i]=-1;
        }
    }

    void Insert(char ch){
        if(occurence[ch]==-1){
            occurence[ch]=index;
        }else if(occurence[ch]>=0){
            occurence[ch]=-1;
        }

        index++;
    }

    char FistAppearOnce(){
        char ch='\0';
        int minIndex=numeric_limits<int>::max();
        for(int i=0;i<256;i++){
            if(occurence[i]>=0&&occurence[i]<minIndex){
                ch=(char)i;
                minIndex=occurence[i];
            }
        }
        return ch;
    }

};

void Test(const char*testname, Solutions chars, char expected){
    if(testname!=nullptr){
        cout<<testname<<endl;
    }

    if(chars.FistAppearOnce()==expected){
        cout<<"Passed\n"<<endl;
    }else{
        cout<<"Finished\n"<<endl;
    }
}

int main(int argc, char * argv[]){
    Solutions chars;
    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    system("pause");
    return 0;
}