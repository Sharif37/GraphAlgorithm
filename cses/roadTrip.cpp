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
vector<int>path ;
int parent[MaxN];
int flag=0 ;
int cyc_start ;
int cyc_end;
void  dfs(int src,int par=-1)
{
    parent[src]=par ;
    for(auto u:adj[src])
    {
        if(u==par)
            continue ;
       if(parent[u])
        {
            path.push_back(u);
            for(int i=src ;i!=parent[u];i=parent[i])
            {
                path.push_back(i) ;
            }
            reverse(path.begin(),path.end());
            cout<<path.size()<<"\n" ;
            for(auto u:path)
                cout<<u<<" " ;
            cout<<endl ;
            exit(0);

        }else
        {
            dfs(u,src);
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

  for(int i = 1; i <= n; i++)
        if (!parent[i])
            dfs(i);
    cout << "IMPOSSIBLE\n";





}
