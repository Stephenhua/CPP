#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int Core(vector<int>& nums){
    int res = 0 ;
    stack<int> st;
    for(int i = 0 ; i< nums.size() ; i++){
        while( !st.empty() && nums[st.top()] < nums[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }

            int l = st.top();
            int r = i ;
            int h = min(nums[r],nums[l]-nums[cur]);
            res+= (r-l-1)*h;
        }
        st.push(i);
    }
    return res;
}
int main(int argc, char*argv[]){
    int W ,L ;
    cin >>W >>L;
    vector<int> arr(L,0);
    for(int i = 0 ;i <L ;i++){
        cin >>arr[i];
    }
    vector<int> temp = arr;
    sort(temp.begin(),temp.end());

    int maxVal = temp[temp.size()-1];

    for(int i = 0 ;i <L ;i++){
        arr[i] = maxVal - arr[i];
    }

    int res = Core(arr);

    if( arr[0] < arr[1]){
        res += (arr[1]-arr[0]);
    }
    int size = arr.size();
    if(arr[size-1] > arr[size]){
        res+= (arr[size-1] - arr[size]);
    }
    res *= W;
    cout << res << endl;
    system("pause");
    return 0 ;

}