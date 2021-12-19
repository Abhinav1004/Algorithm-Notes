// Program to find the minimum number of coins needed to make up a number n
//Technique used
/*
1. Conventional
2. Memoization
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
		int num_coins = minCoinsDp(value,currency,10,dp);
		cout<<num_coins<<"\n";
	}
	return 0;
}