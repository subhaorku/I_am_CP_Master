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
cout<< 0 <<"\n";
cin>>n>>m;cout<<n<<m;
graph.resize(n+1);
visited.assign(n+1,0);

for(int i=0;i<m;i++){
int a,b;cin>>a>>b;
graph[a].push_back(b);
graph[b].push_back(a);
}
for(int i=0;i<n;i++){
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
cout<<"Printing the Component sizes :: ";
for(auto v:compSz){
cout<<v<<" ";
}
cout<<"\n";

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