#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;

const int BUCKET_NUM=10;
struct ListNode{
    explicit ListNode(int i=0):mData(i),mNext(NULL) {}
    ListNode* mNext;
    int mData;
};

ListNode * insert(ListNode * head, int val){
    ListNode dummyNode;
    ListNode *newNode=new ListNode(val);
    ListNode *pre,*curr;
    dummyNode.mNext=head;
    pre=&dummyNode;
    curr=head;
    while(curr!=NULL && curr->mData<=val){
        pre=curr;
        curr=curr->mNext;
    }

    newNode->mNext=curr;//将加入的节点指向大于它的节点
    pre->mNext=newNode;//将前一个节点指向新加入的节点；
    return dummyNode.mNext;
}


ListNode* MergeList(ListNode* head1,ListNode* head2){//两个链表进行插入
    ListNode  dummynode ;
    ListNode *dummy=&dummynode;

    while( head1!= nullptr && head2!=nullptr){
        if(head1->mData <= head2->mData){
            dummy->mNext=head1;
            head1=head1->mNext;
        }else{
            dummy->mNext =head2;
            head2=head2->mNext;
        }
        dummy=dummy->mNext;
    }

    if(head1 != nullptr){
        dummy->mNext=head1;
    }
    if(head2!=nullptr){
        dummy->mNext=head2;
    }
    return dummynode.mNext;
}

void BucketSort(int n ,vector<int>& arr){
    vector<ListNode*> buckets(BUCKET_NUM,(ListNode*)(0));
    for(int i=0;i<n;i++){
        int index=arr[i]/BUCKET_NUM;
        ListNode*head= buckets.at(index);
        buckets.at(index)=insert(head,arr[i]);//节点后面构成一个链表；
    }

    ListNode *head=buckets.at(0);
    
    for(int i =1;i<BUCKET_NUM;i++){//将预先分好的桶进行排序合并；
        head=MergeList(head,buckets.at(i));
    }

    for(int i=0;i<n;++i){
        arr[i]=head->mData;
        head=head->mNext;
    }
}


//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){

    int size=arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    BucketSort(size,arr);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int number=0;
    for(int i=0;i<size;i++){
        if(arr[i]==arr_sort[i]){
            number++;
            cout<<arr[i]<<"  "<<arr_sort[i]<<endl;
        }
    }
    if(number==size){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
    Test(arr,arr_sort);
}

void Test2(){
    vector<int> arr={};
    vector<int> arr_sort={};
    Test(arr,arr_sort);

}
void Test3(){
    vector<int> arr={1};
    vector<int> arr_sort={1};
    Test(arr,arr_sort);
}
void Test4(){
    vector<int> arr={6,72,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
    Test(arr,arr_sort);
}
int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    Test4();
    system("pause");
    return 0;
}
