/* Find Number of pairs (i,j) such that if u add and edge b/w 'i' to 'j' then number of components decreases */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
vector<int>visited;
int n,m;
int numNodes;

void dfs(int node,int col){
visited[node]=col;
numNodes++;
for(auto v:graph[node]){
if(!visited[v])
dfs(v,col);
}
}

void solve()
{
cin>>n>>m;
graph.resize(n+1);
visited.assign(n+1,0);

for(int i=0;i<m;i++){
int a,b;cin>>a>>b;
graph[a].push_back(b);
graph[b].push_back(a);
}

cout<<"Printing the adjacency list"<<"\n";
for(int i=0;i<=n;i++){
cout<<i<<"  :: ";
for(auto v:graph[i])
{
cout<<v<<" ";
}
cout<<"\n";
}


int numOfComp=0;
vector<int>compSz;

for(int i=1;i<=n;i++){
if(!visited[i]){
    numNodes=0;
    numOfComp++;
    dfs(i,numOfComp);
    compSz.push_back(numNodes);
}
}
cout<<"Number of components : "<<numOfComp<<"\n";
cout<<"Printing which nodes belong to which component : "<<"\n";
for(int node=1;node<=n;node++){
cout<<"Node "<<node<<" belongs to "<<visited[node]<<" component"<<"\n";
}
cout<<"Printing the Component sizes :: ";
for(auto v:compSz){
cout<<v<<" ";
}
cout<<"\n";

// All pair sum in fast way 
int runningSum=0;int ans=0;
for(auto v:compSz){
ans+=runningSum*v;
runningSum+=v;
}
cout<<"Number of pairs (i,j) such that if we add an edge b/w i and j then number of Components decreases : "<<ans<<"\n";
}

signed main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
solve();
}

/*
Output : 

Printing the adjacency list
0  :: 
1  :: 2 5 
2  :: 1 3 5 
3  :: 2 4 
4  :: 5 3 
5  :: 1 2 4 
6  :: 7 
7  :: 6 8 
8  :: 7 
9  :: 10 
10  :: 9 11 12 
11  :: 10 
12  :: 10 
Number of components : 3
Printing which nodes belong to which component : 
Node 1 belongs to 1 component
Node 2 belongs to 1 component
Node 3 belongs to 1 component
Node 4 belongs to 1 component
Node 5 belongs to 1 component
Node 6 belongs to 2 component
Node 7 belongs to 2 component
Node 8 belongs to 2 component
Node 9 belongs to 3 component
Node 10 belongs to 3 component
Node 11 belongs to 3 component
Node 12 belongs to 3 component
Printing the Component sizes :: 5 3 4 
Number of pairs (i,j) such that if we add an edge b/w i and j then number of Components decreases : 47
*/