#include <iostream>
#include <vector>
using  namespace std;
int Core(vector<vector<int>>& table){

}
int main( int argc ,char* argv[]){
    int N ,M ;
    cin >> N >> M;
    vector<int> w(N,0);
    vector<int> p(N,0);
    
    vector<vector<int>> table(N,vector<int>(M,0));
    for(int i = 0 ;i < N ;i++){
        for(int j = 0 ; j < M;j++){
            int temp ;
            cin>>temp;
            table[i][j]=temp;
        }
    }
    //核心代码；

    int res = Core( table);
    cout << res << endl;
    system("pause");
    return 0;
}