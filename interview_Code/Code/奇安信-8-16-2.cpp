#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
https://www.nowcoder.com/discuss/478987?type=post&order=time&pos=&page=1&channel=666&source_id=search_post
输入字符串，然后以空格为切割符 ，通过删除和撤销的操作后，最后输出字符串；
它的undo次数必须大于redo次数，而且如果插入数据，undo次数就归0，undo次数为0的时候redo就直接略过
*/

int main(){

    string str ;

    deque<pair<string,int>> d1,d2;
    int index = 0;
    int cnt = 0 ;

    while (cin>> str)
    {
        if( str == "undo"){
            if( d1.empty() == true){
                continue;
            }

            ++cnt ;
            d2.push_back( d1.back());
            d1.pop_back();
        }else if( str == "redo"){
            if( d2.empty() == true || cnt == 0 ){
                continue;
            }

            d1.push_back(d2.back());
            d2.pop_back();
            --cnt;
        }else{
            d1.push_back({str,index});
            ++index;
            cnt=0;
        }
    }

    vector<pair<string,int>> res;
    while( d1.empty() == false){
        res.push_back(d1.front());
        d1.pop_front();
    }

    for( int i = 0 ; i < res.size() ;i++){
        if(i){
            cout <<" ";
            cout <<res[i].first<<;
        }
    }
    return 0;
    
}