#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    int N ,M;

    cin >> N >> M ;

    if( N == 0 || M == 0){
        return 0;
    }

    if( N == 1){
        return 1;
    }

    vector<vector<int>> Scores;
    for(int i = 1 ; i <= N;i++){
        for(int j = 1; j <= M; j++){
            cin >> Scores[i][j];
        }
    }

    set<int> res;
    
    for(int i = 1; i <= M ;i++){

        int max = Scores[1][i];
        int count = 1;
        for(int j =2 ; j <=N ;j++){

            if( max < Scores[j][i]){

                max = Scores[j][i];
                
                count = j;
            }
        }
        res.insert(count);

    }

    int result =res.size();

    return result;
}