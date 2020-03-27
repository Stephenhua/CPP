#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&v,int min,int mid,int max){
	vector<int>s;
	int i=min,j=mid+1;
	while(i<=mid&&j<=max){
		if(v[i]>=v[j]) 
		s.push_back(v[j++]);
		else 
		s.push_back(v[i++]); 
	}
	while(i<=mid) 
	s.push_back(v[i++]);
	while(j<=max)
	 s.push_back(v[j++]);
	for(int l=min,k=0;l<=max;k++,l++)
		v[l]=s[k];
		cout<<"输出v";
	for(int oo=0;oo<v.size();oo++){
			
		cout<<v[oo];
	}
	cout<<endl<<"--------------------"<<endl;
	for(int p=0;p<s.size();p++)
	cout<<s[p];
	cout<<endl;
	s.clear();
}
void Msort(vector<int>&v,int min,int max){
	
	if(min>=max)
	return;
	else{
		Msort(v,min,(max+min)/2);
		Msort(v,(min+max)/2+1,max);
		merge(v,min,(min+max)/2,max);
	}
}
int main(){
	vector<int>v(10);
	for(int i=0;i<10;i++)
	v[i]=9-i;
	Msort(v,0,9);
    system("pause");
    return 0;
}