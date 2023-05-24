#include<bits/stdc++.h>
using namespace std ;

const int Max=100 ;
int V,E ;
vector<int>adj[Max] ;
bool visited[Max] ;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<pair<int ,int>>edges ;
void dfs(int u)
{

    visited[u]=true ;
    for(int v:adj[u])
    {
        if(!visited[v])
        {
            edges.push_back({u,v});
            dfs(v);
        }
    }
}

int main()
{

 cin>>V>>E ;
 for(int i=0 ;i<E ;i++)
 {
     int u,v ;
     cin>>u>>v ;
     addEdge(u,v);
 }

  dfs(1);

  for(auto edge:edges)
  {
      cout<<edge.first<<"-"<<edge.second<<" " ;
  }



}
