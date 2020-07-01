#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main ( int argc, char* argv){
    ifstream readFile("Text.txt");
    char tmep[1024] = {0};
    readFile >>tmep;
    cout<<tmep;
    readFile.close();

    system("pause");
    return 0 ;
}

