
  #include <iostream>
  #include <vector>
  using namespace std;
  
  //盖房子直接进行匹配就可以实现；

    int getHouses(int t, int* xa, int xaLen) {
        // write code here
        int res = 2 ;
        int cur = 0;
        int prev =0 ;
        if(xaLen == 2 ){
            return res;
        }
        vector<pair<int,int>> temp;
        for(int i =1 ;i <= xaLen ;i+=2,xa+=2){
            temp.push_back(make_pair(*xa,*(xa+1)/2));
        }
        vector<pair<int,int>>::iterator it;
        for( it=temp.begin() ; it!=temp.end()-1 ;it++){
            int d1  = it->first +it->second;
            int d2 = (it+1)->first -(it+1)->second;
            if(d2-d1 >t ){
                res+=2;
            }else if(d2-d1==t){
                res+=1;
            }
        }
        return res ;
    }

    int main(int argc ,char argv[]){
        int a[4] = {-1,4,5,2};
        int *xa =a; 
        int res = getHouses(2,xa,4);
        cout <<res <<endl;
        system("pause");
        return 0 ;
    }

    、、