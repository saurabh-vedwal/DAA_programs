//one of the problems solved by greedy approache.
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> t1,pair<int,int>t2){
	if(t1.second==t2.second){
		t1.first<t2.first;
	}
	return t1.second<t2.second;
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF ACTIVITES	:";
	cin>>n;
	vector<pair<int,int>> activity;
	for(int i=0;i<n;i++){
		int start_time,finish_time;
		cout<<"ENTER THE START TIME AND FINISH TIME 	:";
		cin>>start_time>>finish_time;
		activity.push_back({start_time,finish_time});
	}
	int ans=1;
	sort(activity.begin(),activity.end(),compare);
	int previous_finish_time=activity[0].second;
	for(int i=1;i<n;i++){
		if(activity[i].first>=previous_finish_time){
			ans++;
			previous_finish_time=activity[i].second;
		}
		
	}
	cout<<"TOTAL NUMBER OF NON OVERLAPPED ACTIVITY ARE		:"<<ans;
}