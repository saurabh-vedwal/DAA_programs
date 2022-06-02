//BIPARTITE GRAPH-The graph is two colorable.
//Its vertices can be devided into two disjoint and sets U and V,such that every edge connects a vertex in U to one in V.
//BIPARTITE GRAPH does not contain any odd-length cycle. 
//how to check a graph is bipertite.
	//traverse the graph.
	//if the current node is of red.paint its neigbour as blue.
	//if one able to color the graph successfully,then the graph is bipertite.

#include<bits/stdc++.h>
using namespace std;

bool color_graph(vector<vector<int>> edge,int source,vector<bool> visited,vector<int> color,int curr,bool bipart){
	if(color[source]!=-1 && color[source]==curr){
		return false;
	}
	color[source]=curr;
	if(visited[source]){
		return true;
	}
	visited[source]=true;
	for(auto i: edge[source]){
		bipart=color_graph(edge,i,visited,color,curr xor 1,bipart);
	}
}
int main(){
	bool bipart=true;
	int n;
	cout<<"ENTER THE NUMBER OF VERTICES:	";
	cin>>n;
	vector<vector<int>> edge(n);
	vector<int> color(n,-1);
	vector<bool> visited(n,false);
	for(int i=0;;i++){
		int source,destination,choice;
		cout<<"ENTER SOURCE AND DESTINATION VERTEX";
		cin>>source>>destination;
		edge[source].push_back(destination);
		edge[destination].push_back(source);
		cout<<"ENTER YOUR CHOICE,PRESS 1 FOR EXIT";
		cin>>choice;
		if(choice==1){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			bipart=color_graph(edge,i,visited,color,0,&bipart);
		}
	}
	if(bipart){
		cout<<"BIPARTED GRAPH";
	}
	else{
		cout<<"NOT BIPARTITE GRAPH";
	}
}