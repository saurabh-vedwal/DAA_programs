//FRACTIONAL KNAPSACK PROBLEM;
//greedy approaches;
//sort the number.pick the finest(sbse bdia)first and then repeat furthur.
#include<bits/stdc++.h>
using namespace std;
struct item{
	float weight;
	float value;
	float weightPerValue;
};
bool compare(item i1,item i2){
	return i1.weightPerValue>i2.weightPerValue;
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF ITEMS";
	cin>>n;
	vector<item> items;
	for(int i=0;i<n;i++){
		float weight,value;
		cout<<"ENTER THE WEIGHT AND VALUE of object:	";
		cin>>weight>>value;
		items.push_back({weight,value,value/weight});
	}
	int W;
	cout<<"ENTER THE WEIGHT OF KNAPSACK:		";
	cin>>W;
	float ans=0;
	sort(items.begin(),items.end(),compare);
	for(int i=0;i<n;i++){
		if(W>items[i].weight){
			W=W-items[i].weight;
			ans=ans+items[i].value;
		}
		else{
			ans=ans+(W*items[i].weightPerValue);
			W=0;
			break;
		}
	}
	cout<<"MAXIMUM PROFIT =		:"<<ans;
}