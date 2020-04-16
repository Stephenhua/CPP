#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stack>
#include <set>
#include "BinaryTreeNode.h"
using namespace std;

int main(){
    
    while (cin>>N>>M)
    {
        set<int> temp;
        for(int i=0;i<M ;i++){
            int a,b,c;
            cin >> a >> b >> c;

            if(c===1){
                temp.insert(a);
                temp.insert(b);
            }

        }

        if(temp.find(1) != temp.end)
        {
            cout <<" num"<< temp.size() <<endl;
        }else
        {
            cout<< 0 << endl;
        }
        
         /* code */
    }
    return 0;
    

}