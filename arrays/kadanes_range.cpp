#include<bits/stdc++.h>
using namespace std;

void printLongestSumSubarray(int ar[],int size){
	int max_cur = ar[0];int max_val = INT_MIN;
	int start = 0;
	int end = 0;
	for(int i=1;i<size;i++){
		if((max_cur+ar[i])>ar[i]){
			max_cur = max_cur+ar[i];
		}
		else{
			start = i;max_cur = ar[i];
		}
		if(max_cur>max_val){
			max_val = max_cur;
			end = i;
		}
	}
	cout<<start<<" "<<end;
	cout<<"\n";
	cout<<max_val<<"\n";
}
int main(int argc, char const *argv[])
{
	int test;
	cin>>test;
	for(int i=0;i<test;i++){
		int size;
		cin>>size;
		int a[size];
		for(int j=0;j<size;j++)
			cin>>a[j];
		printLongestSumSubarray(a,size);
	}
	return 0;
}