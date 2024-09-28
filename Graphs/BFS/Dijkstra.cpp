#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int>;

vector<vector<state>>graph;
vector<int>visited;
vector<int>dist;
int n,m;

void sssp(int source)
{
priority_queue<state> pq;
dist[source]=0;
pq.push(make_pair(0,source));

while(!pq.empty())
{
state x = pq.top();
pq.pop();
int node = x.second;
if(visited[node]) continue;
visited[node]=1;
for(auto v:graph[node]){
int neigh = v.first;
int cost = v.second;
if(dist[neigh]>dist[node]+cost){
dist[neigh]=dist[node]+cost;
pq.push(make_pair(-dist[neigh],neigh));
}
}
}
}

void solve()
{
cin>>n>>m;
graph.resize(n+1);
visited.assign(n+1,0);
dist.assign(n+1,1e9);
for(int i=0;i<m;i++){
int a,b,c;cin>>a>>b>>c;
graph[a].push_back(make_pair(b,c));
graph[b].push_back(make_pair(a,c));
}

cout<<"Printing the adjacency list"<<"\n";
for(int i=0;i<=n;i++){
cout<<i<<"  :: ";
for(auto v:graph[i])
{
cout<<v.first<<" "<<"edgeweight: "<<v.second<<" ,, ";
}
cout<<"\n";
}
int sc;cin>>sc;
sssp(sc);
cout<<"\n\n";
for(int i=1;i<=n;i++){
cout<<"Distance of node "<< i<<" from source node is : "<<dist[i]<<"\n";
}
}

signed main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
solve();
}

/*
Printing the adjacency list
0  :: 
1  :: 2 edgeweight: 1 ,, 5 edgeweight: 0 ,, 
2  :: 1 edgeweight: 1 ,, 5 edgeweight: 1 ,, 3 edgeweight: 0 ,, 
3  :: 2 edgeweight: 0 ,, 4 edgeweight: 1 ,, 
4  :: 3 edgeweight: 1 ,, 5 edgeweight: 1 ,, 
5  :: 1 edgeweight: 0 ,, 2 edgeweight: 1 ,, 4 edgeweight: 1 ,, 


Distance of node 1 from source node is : 0
Distance of node 2 from source node is : 1
Distance of node 3 from source node is : 1
Distance of node 4 from source node is : 1
Distance of node 5 from source node is : 0
*/