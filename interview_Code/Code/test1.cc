#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int MaxProfit(priority_queue<pair<int,int>>& Applic, vector<int>& server){
    int result  = 0;


    while(!Applic.empty() && !server.empty()){
        int profit = Applic.top().first;
        int mem = Applic.top().second;

        int size = server.size();
        
        if( Applic.top().second > server[size-1]){
            
            Applic.pop();

            continue;
        }
        std::vector<int>::iterator index = lower_bound(server.begin() , server.end() ,mem);



        result += profit;
        Applic.pop();
        server.erase(index);
    }
}

int main(int argc , char* argv[]){
    int N ;
    cin >>N; 
    priority_queue<pair<int,int>> Applic;
    while( N--){
        int a , b ;
        cin >> a >> b;
        
        pair<int,int>temp;
        //表示收益在前，内存大小在后；
        temp.first = b ;
        temp.second = a;
        Applic.push(temp);
    }

    int M ;
    cin >>M ;
    vector<int> server ;
    while(M--){
        int serverMe;
        cin >> serverMe;

        server.push_back( serverMe);
    }

    sort( server.begin() ,server.end());

    int result = MaxProfit( Applic ,server);
    cout <<result <<endl;

    system("pause");
    return 0 ;
}