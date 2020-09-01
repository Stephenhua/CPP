#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;
const int MAX=10000;


int main( int argc ,char* argv[]){
    int N ,M ;
    cin >> N >> M;
    vector<int> w(MAX,0);
    vector<int> p(MAX,0);
    for(int i = 1 ;i <= N ;i++){
        cin >> w[i] >>p[i];
    }
    vector<vector<int>> dp(MAX,vector<int>(MAX,0));

    for(int i =1 ;i <= N ;i++){
        for(int j =1 ;j <=M ;j++){
            if(j<w[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j-w[i]]+p[i]);
            }
        }
    }
    ;
    cout << dp[N][M] << endl;
    return 0;
}
