//A Topological sorting is the ordering of the nodes in a directed graph where
//for each directed edge from Node A to Node B,Node A apperas before Node B in the
//ordering.
//topological ordering are not unique(1 se jayda ho skti h 1 graph ki)
//hur graph ki topological sort ni hoti.
//DIRECTED  CYCLIC GRAPH ki topological sorting nai hoti.
//DAG(directed Acyclic Graph ki topological sort kr skte h)
//INDEGREE--number of inward directed edges of the vertex is known as indegree.
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF VERTICES";
	cin>>n;
	vector<vector<int>> edges(n);
	vector<int> indegree(n,0);
	for(int i=0;;i++){
		int source,destination;
		cout<<"ENTER THE SOURCE AND THE DESTINATION";
		cin>>source>>destination;
		edges[source].push_back(destination);
		indegree[destination] ++;
		int choice;
		cout<<"ENTER YOUR CHOICE";
		cin>>choice;
		if(choice==1){
			break;
		}
	}
	queue<int> pq;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			pq.push(i);
		}
	}
	int cnt;
	while(!pq.empty()){
		cnt++;
		int x=pq.front();
		pq.pop();
		cout<<x<<"  ";
		for(auto it: edges[x]){
			indegree[it]--;
			if(indegree[it]==0){
				pq.push(it);
			}
		}
	}
}