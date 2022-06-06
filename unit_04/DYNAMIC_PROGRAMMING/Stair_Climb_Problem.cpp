#include<bits/stdc++.h>
using namespace std;
int climb_stairs(int n);
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF STEPS;	";
	cin>>n;
	int x=climb_stairs(n);
	cout<<"THE NUMBER OF WAYS IN WHICH STEPS CAN BE TAKEN :	"<<x;
}
int climb_stairs(int n){
	vector<int> dp(n+1,-1);
	dp[1]=1;
	for(int i=2;i<n+1;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}