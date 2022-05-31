#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> *edges,int source,bool *visited){
	queue<int>q;
	q.push(source);
	visited[source]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto i=edges[source].begin();i!=edges[source].end();i++){
			if(!visited){
				q.push(*i);
				visited[*i]=true;
			}
			cout<<u<<"  "; 
		}
	}
}
void add_edge(vector<int>*edges,int source,int destination){
	edges[source].push_back(destination);
	edges[destination].push_back(source);
}
int main(){
	int n;
	cout<<"	ENTER THE NUMBER OF VERTICES ";
	cin>>n;
	int source,destination,choice;;
	vector<int> edges[n];
	for(int i=0;;i++){
		cout<<"ENTER SOURCE VERTIX/DESTINATION VERTIX";
		cin>>source>>destination;
		add_edge(edges,source,destination);
		cout<<"ENTER YOUR CHOICE :	";
		cin>>choice;
		if(choice==1){
			break;
		}
	}
	bool visited[n];
	for(int i=0;i<n;i++){
		if(!visited[i]){
			bfs(edges,i,visited);
		}
	}
}