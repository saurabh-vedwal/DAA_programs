#include<bits/stdc++.h>
using namespace std;
int MAX=1e9+7;
int min_Square(int n,vector<int> &dp){
	if(n==1||n==2||n==3||n==0){
		return n;
	}
	if(dp[n]!=MAX){
		return dp[n];
	}
	for(int i=1;i*i<=n;i++){
		dp[n]=min(dp[n],1+min_Square((n-i*i),dp));
	}
	return dp[n];
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER:	";
	cin>>n;
	vector<int> dp(n+1,MAX);
	int x=min_Square(n,dp);
	cout<<x;
}