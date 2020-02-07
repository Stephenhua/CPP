 #include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
 
 if(matrix.empty()||matrix[0].empty())
        {
            return false;
        }
        int rows = matrix.size();
        int colums= matrix[0].size();
        bool found=false;
        
        //if(matrix!=nullptr && rows>0 &&colums>0){
            int row=0;
            int colum=colums-1;
            while(row<rows&&colum>=0){
                
                 if(target> matrix[row][colum]){
                     ++row;
                 }else if(target<matrix[row][colum]){
                     --colum;
                 }else{
                     found=true;
                     break;
                 }
                
            }
            return found;
       // }
        