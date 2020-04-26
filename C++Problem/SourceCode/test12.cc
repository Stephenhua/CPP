#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

float distance( int x1, int y1, int x2, int y2){
    float result = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return result;
}

float Sum (int x ,int y ){
    int result = x*x+y*y;

}
int main(){
    int n ;
    cin >>n ;

    for(int i=0 ;i<n ;i++){
        int num ;
        cin>>num;

        vector<pair<int,int>> temp_A;
        vector<pair<int,int>> temp_B ;
        for(int i = 0 ;i<num; i++){
            int x,y;
            cin >>x >>y;
            pair<int,int> temp_xy ;
            temp_xy.first =x; 
            temp_xy.second = y ;
            temp_A.push_back(temp_xy);
        }
        for(int i =num ;i<2*num ;i++){
            
            int x,y;
            cin >>x >>y;
            pair<int,int> temp_xy ;
            temp_xy.first =x; 
            temp_xy.second = y ;
            temp_B.push_back(temp_xy);
        }
        unsigned int minValueA =1000000000;
        unsigned int maxValueA =0;
        vector<int> temp_A_Value(num);

        for(int i=0;i<temp_A.size();i++){
            int x =temp_A[i].first;
            int y = temp_A[i].second;
            int result = Sum(x,y);
            if(minValueA >= resultz){
                minValueA = result;
                temp_A_Value.push_back( x);
                temp_A_Value.push_back(y);
            }

            if(maxValueA <=result){
                maxValueA =result ;
                temp_A_Value.push_back( x);
                temp_A_Value.push_back(y);
            }
        }
        
        unsigned int minValueB =1000000000;
        unsigned int maxValueB =0;
        vector<int> temp_B_Value(num);

        for(int i=0;i<temp_B.size();i++){
            int x =temp_B[i].first;
            int y = temp_B[i].second;
            int result = Sum(x,y);
            if(minValueA >= result){
                minValueB = result;
                temp_B_Value.push_back(x);
                temp_B_Value.push_back(y);
            }

            if(maxValueA <=result){
                maxValueB =result ;
                temp_B_Value.push_back(x);
                temp_B_Value.push_back(y);
            }
        }

        int sumAtoB = maxValueA -minValueB ;
        int sumBtoA = maxValueB - minValueA ;

        if(sumAtoB >=sumBtoA){
            float result =distance(temp_A_Value[2],temp_A_Value[3],temp_B_Value[0],temp_B_Value[1]);
            printf("%.3f",result);
        }else{
            float result = distance( temp_B_Value[2],temp_B_Value[3],temp_A_Value[0],temp_A_Value[1]);
            printf("%.3f",result);
        }
   }

    system("pause");
    return 0;
}