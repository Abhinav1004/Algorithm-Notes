// Program to find the minimum number of coins needed to make up a number n
//Technique used
/*
1. Conventional
2. Memoization
3. Tabulated
*/
#include<bits/stdc++.h>
using namespace std;

int minCoins(int value,int cm[],int m){
	if(value==0)
		return 0;
	else
		{
		int res = INT_MAX;
		for(int i=0;i<m;i++){
			if(value>=cm[i])
			{
				int sub_res = minCoins(value-cm[i],cm,m);
				// cout<<sub_res<<"\n";
				if(sub_res!=INT_MAX && sub_res+1<res){
					res = sub_res+1;
				} 
			}
		}
		return res;
	}
}
int minCoinsDp(int value,int cm[],int m,int dp[]){
	if(dp[value]!=-1)
		return dp[value];
	else{
		int res = INT_MAX;
		for(int i=0;i<m;i++){
			if(value>=cm[i])
			{
				int sub_res = minCoinsDp(value-cm[i],cm,m,dp);
				// cout<<sub_res<<"\n";
				if(sub_res!=INT_MAX && sub_res+1<res){
					res = sub_res+1;
				} 
			}
		}
		dp[value] = res;
		return dp[value];
	}
}

int minCoinsTab(int value,int cm[],int m){
	int dp[value+1];
	fill_n(dp,value+1,INT_MAX);
	dp[0] = 0;
	for(int i=1;i<=value;i++){
		// int res = INT_MAX;
		for(int j=0;j<m;j++){
			if(i>=cm[j]){
				int sub_res = dp[i-cm[j]];
				if(sub_res!=INT_MAX && sub_res+1<dp[i])
					dp[i] = sub_res+1;	
			}
		}
	}
	if(dp[value]==INT_MAX)
		return -1;

	return dp[value];
}
void printArray(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<"\n";
}
int main(int argc, char const *argv[])
{
	int test;
	cin>>test;
	for(int i=0;i<test;i++){
		int value;
		cin>>value;
		int currency[]={2000,500,200,100,50,20,10,5,2,1};
		// int num_coins = minCoins(value,currency,10);
		int dp[value+1];
		fill_n(dp,value+1,-1);
		dp[0]=0;
		// int num_coins = minCoinsDp(value,currency,10,dp);
		int num_coins = minCoinsTab(value,currency,10);
		cout<<num_coins<<"\n";
	}
	return 0;
}