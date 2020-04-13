#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

class Foo {};
Foo* pf =new Foo;
delete pf;

template <class Iterator ,class T>
Iterator find( Iterator begin ,Iterator end ,const T& value){
    
    while( begin != end && *begin != value){

        ++begin;
        
    }

    return begin;
}