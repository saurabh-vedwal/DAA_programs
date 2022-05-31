//kruksal algorithm use hoti h minimum spannin tree find krne k liye.
//MST ka use google maps mein hota like id=f we want to know the shortest distance
//or networking mein bhi hota like minimum distance between two points k lie.
#include<bits/stdc++.h>
using namespace std;
vector<int>parent(10);
vector<int>size(10);
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void make(int V){
	parent[V]=V;
	size[V]=1;
}
int find(int V){
	if (V==parent[V]){
		return V;
	}
	return parent[V]=find(parent[V]);//return find(parent[V])ata agr optimal solution nai chie hota to)
}
void union_set(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(size[a]<size[b]){//this reduce time complexity
			swap(a,b);//because we have to search in lower tree.
		}
		parent[b]=a;
		size[a]=size[a]+size[b];
	}
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF VERTICES";
	cin>>n;
	for(int i=0;i<n;i++){
		make(i);
	}
	vector<vector<int>>edges;//edges put krwane k lie.
	for(int i=0;;i++){
		int choice, source,destination,weight;
		cout<<"ENTER THE SOURCE AND THE DESTINATION/WEIGHT OF THE EDGE";
		cin>>source>>destination>>weight;
		edges.push_back({weight,source,destination});
		cout<<"enter your choice press 1 for exit";
		cin>>choice;
		if(choice==1){
			break;
		}
	}
	sort(edges.begin(),edges.end());//array sort hojaygi weight k hisaab se.
	int cost=0;
	for(auto i:edges){
		int w=i[0];
		int u=i[1];
		int v=i[2];
		int x=find(u);
		int y=find(v);
		if(x==y){//agr x,y same set mein belong krte h to wo cycle form krnge 
			continue;//or MST mein hum cycle include nai krte isliye isko MST mein add nai krnge.
		}
		else{
			cout<<u<<"  "<<v<< endl;
			union_set(u,v);
			cost=cost+w;
		}
	}
	cout<<"MINIMUM COST OF THGE TREE IS "<<cost;
}