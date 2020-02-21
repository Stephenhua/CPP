#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solutions {
    public:
        char FistNotRopeatingChar(char* pString){
            if(pString==nullptr){
                return '\0';
            }

            const int TableSize=256;
            int hashTable[TableSize];

            for(int i=0;i<TableSize;i++)
            {
                hashTable[i]=0;
            }
            char *pHashkey=pString;            
            while(*(pHashkey)!='\0'){
                hashTable[*(pHashkey++)]++;

            }

             pHashkey=pString;
            while (*(pHashkey)!='\0')
            {
                if(hashTable[*pHashkey]==1){
                    return *pHashkey;
                }

                pHashkey++;
                /* code */
            }

            return '\0';            
        }

        void Test(char* pString , char expected){
            if(FistNotRopeatingChar(pString)==expected){
                cout<<"Test passed"<<endl;
            }else{
                cout<<"Test failed"<<endl;
            }
        }
};

int main(int argc, char argv[]){
    Solutions one;
    one.Test("google",'1');
    one.Test("aabccdbd",'\0');
    one.Test("abcdefg",'a');
    one.Test(nullptr,'\0');

    system("pause");
    return 0;

}