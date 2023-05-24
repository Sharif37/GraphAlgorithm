#include<bits/stdc++.h>
using namespace std ;
const int MaxN=1e5+1 ;
void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

vector<int>adj[MaxN];
bool visited[MaxN]={false};
vector<int>road ;
int parent[MaxN];

void dfs(int src)
{
    visited[src]=true ;
    for(int u:adj[src])
    {

    }
}

}

int main()
{
optimize() ;
int n,m ;
cin>>n>>m ;
for(int i=0 ;i<m ;i++)
{
    int a,b;
    cin>>a>>b ;
    adj[a].push_back(b);
    adj[b].push_back(a);
}





}
