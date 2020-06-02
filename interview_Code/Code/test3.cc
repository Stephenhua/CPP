#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main( int argc ,char* argv[]){

    map<int,int> table_map;
    for( int i=0 ;i < 10 ;i++){
        table_map[i] = i;
    }

    int K = 2;
    for (auto it = table_map.begin(); it != table_map.end();) {

        if(0 == it->second % K) {


            table_map.erase(it++);
            
            

        }
    }
    for( int i=0 ;i < table_map.size() ;i++){

        cout <<table_map[i] << endl;

    }

    system("pause");
    return 0;

}

void TheKthSort( vector<int>& nums, int k){

    int num ;

    int n = nums.size();

    int i = 0 ;

    while(i<n){
        if( i < k ){

            BuildMaxHeap( nums, i,k);//构建最大堆；

        }else{
            if( nums[i] > nums[0]){//如果大于堆订的值，则直接跳过
               
                continue；

            }else{

                 HeapSort(nums,i,k)//实现堆排序，将nums[i]元素插入到堆中，将num[i]位置与位置进行交换

            }


        }
    }

}

struct ListNode {
    ListNode(int x):val(x), next(nullptr) {}
    int val;
    ListNode *next;
    ListNode *prev;
};
ListNode* partitionList(ListNode *pHead) {

    ListNode* start = pHead;
    ListNode* reverseList = nullptr;
    ListNode* preNode = nullptr;

    while( start != nullptr){

        ListNode* pNextNode = start->next;

        if( start->next == nullptr ){

            reverseList = start;
        }

        preNode = start->next;
        start->prev = pNextNode;

        preNode = start;
        start = pNextNode ;


    }
    return reverseList;
}
