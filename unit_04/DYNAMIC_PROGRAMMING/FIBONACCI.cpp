#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>&dp){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER; 	";
	cin>>n;
	vector<int> dp(n+1,-1);
	cout<<fib(n,dp);
}