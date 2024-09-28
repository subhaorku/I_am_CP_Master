#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int>;

vector<vector<int>>graph;
vector<int>visited;
vector<int>dist;
int n,m;

void sssp(int source)
{
queue<int> q;
dist[source]=0;
q.push(source);

while(!q.empty())
{
int node = q.front();
q.pop();
if(visited[node]) continue;
visited[node]=1;
for(auto v:graph[node]){
if(dist[v]>dist[node]+1){
dist[v]=dist[node]+1;
// if distance of any node gets changed then push it in queue so that the change can get propagated ahead
q.push(v);
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
int sc;cin>>sc;
sssp(sc);

for(int i=1;i<=n;i++){
cout<<"Distance of node "<< i<<" from source node "<<dist[i]<<"\n";
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
1  :: 2 5 
2  :: 1 5 3 
3  :: 2 4 
4  :: 3 5 
5  :: 1 2 4 
Distance of node 1 from source node 0
Distance of node 2 from source node 1
Distance of node 3 from source node 2
Distance of node 4 from source node 2
Distance of node 5 from source node 1
*/