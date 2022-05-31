#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF COINS : 	";
	cin>>n;
	vector<int> coin(n);
	for(int i=0;i<n;i++){
		cout<<"ENTER THE VALUE OF COIN:   ";
		cin>>coin[i];
	}
	int value;
	cout<<"ENTER THE RUPEES YOU WANT: 	";
	cin>>value;
	sort(coin.begin(),coin.end(),greater<>());
	int minimum_coin=0;
	for(int i=0;i<n;i++){
		int current_coin=coin[i];
		minimum_coin=minimum_coin+(value/current_coin);
		value=value%current_coin;
		if(!value){
			break;
		}
	}
	cout<<"MINIMUM NUMBER OF COINS:    "<<minimum_coin;
	
}