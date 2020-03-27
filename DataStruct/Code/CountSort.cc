#include <iostream>
#include <vector>
using namespace std;
 
void CountSort(vector<int> &arr, int maxVal) {
	int len = arr.size();
	if (len < 1)
		return;
	vector<int> count(maxVal+1, 0);
	vector<int> tmp(arr);
	for (auto x : arr)
		count[x]++;
	for (int i = 1; i <= maxVal; ++i)
		count[i] += count[i - 1];
	for (int i = len - 1; i >= 0; --i) {
		arr[count[tmp[i]] - 1] = tmp[i];
		count[tmp[i]]--;				//注意这里要减1
	}
}
 
int main()
{
	vector<int> arr = { 1,5,3,7,6,2,8,9,4,3,3 };
	int maxVal = 9;
	CountSort(arr,maxVal);
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
    system("pause");
	return 0;
}