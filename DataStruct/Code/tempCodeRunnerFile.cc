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
