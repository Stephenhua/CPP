#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


/*
https://www.nowcoder.com/discuss/500649


*/
int main(int argc,char* argv[]){
    int n ;
    cin >>n;
    vector<int> nums(n+1,0);
    for(int i =1 ;i <=n ;i++ ){
        cin >> nums[i];
    }
    vector<int> temp(n+1,0);
    int res = 0 ;
    for(int i = 1 ;i <= n ;i++){
        for(int j = 1 ; j <=n ;j++){
            nums[i] ^= (i%j);
        }
    }

    for(int i = 2 ;i <=n ;i++){
        temp[i]^= temp[i-1];
    }
    
    cout <<temp[n]<<endl;
    system("pause");
    return 0 ;

}

int main(int argc,char* argv[]){
    int n ;
    cin >>n;
    vector<int> nums(n+1,0);

    for(int i =1 ;i <=n ;i++ ){
        cin >> nums[i];
    }
    vector<int> preNum(n+1,0);
    
    for(int i = 1 ;i<=n ;i++){
        preNum[i]= preNum[i-1]^i;
    }
    
    int ans = 0 ;
    //遍历j，然后竖着看的话，就可以更具n/j的就特性就可以进行抵消；
    for(int i =1 ;i <= n ;i++){
        ans ^= preNum[n%i];
        if((n/i)%2){
            ans ^= preNum[i-1];
        }
    }

    for(int i = 0 ;i <= n ;i++){
        ans ^= nums[i];
    }
    
    cout << ans <<endl;
    return 0 ;

}




int main(int argc,char* argv[]){
    int n ;
    
    while(cin >> n){
        vector<int> nums(n,0);
        for(int i = 0 ;i < n ;i++){
            cin >> nums[i];
        }
        int res = 0 ;
        for(int i = 0 ;i < n ;i ++){
            if(nums[i]%2!=0){
                res++;
            }
        }

        if(res %2 ==0 ){
            cout <<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0 ;

}