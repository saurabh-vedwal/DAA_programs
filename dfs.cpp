#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>*adj,int source,int destination){
	adj[source].push_back(destination);
	adj[destination].push_back(source);	
}
void dfs(vector<int>*adj,int source,bool *visited){
	cout<<source;
	visited[source]=true;
	for(auto it=adj[source].begin();it!=adj[source].end();it++){
		if(visited[*it]){
		}
		else{
			dfs(adj,*it,visited);
		}
	}
}
bool cycle_detection(vector<int>*adj,int source,bool *visited,int parent){
	visited[source]=true;
	for(auto it=adj[source].begin();it!=adj[source].end();it++){
		if(!visited[*it]){	
			if(cycle_detection(adj,*it,visited,source)){
				return true;
			}
		}
		else if(*it!=source){
			return true;
		}
	}
	return false;
}
int main(){
	int nodes,source,destination;
	cout<<"ENTER THE NUMBER OF NODES";
	cin>>nodes;
	vector<int> adj[nodes];
	for(int i=0;;i++){
		int choice;
		cout<<"ENTER THE SOURCE VERTEX AND DESTINATION VERTEX";
		cin>>source>>destination;
		cout<<"ENTER YOUR CHOICE 0/1: 0-FOR CONTINUE 1-FOR BREAK";
		addedge(adj,source,destination);
		cin>>choice;
		if(choice==0){
			continue;
		}
		else{
			break;
		}
	}
	bool visited[nodes];
	for(int i=0;i<nodes;i++){
		if(!visited[i]){
			dfs(adj,i,visited);
			cout<<endl;
			cout<<cycle_detection(adj,i,visited,0);
		}
	}
	
}
