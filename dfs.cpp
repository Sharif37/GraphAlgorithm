#include<bits/stdc++.h>
using namespace std ;
#define n 100
vector<int>adj[n];
bool visited[n];
int depth[n] ;
int parent[n] ;
void dfs_visit(int src)
{
    visited[src]=true ;
    cout<<src<<" " ;
    for(auto u: adj[src])
    {
        if(visited[u]==false)
        {
            parent[u]=src ;
            depth[u]=depth[src]+1 ;
            dfs_visit(u) ;
        }
    }



}
void dfs(int vertex )
{
  for(int i=1 ;i<=vertex ;i++)
  {
    visited[i]=false ;
    parent[i]=-1 ;
     depth[i]=0 ;
  }
  dfs_visit(1);
  for(int i=1 ;i<=vertex ;i++)
  {
      if(visited[i]==false)
      {
          //dfs_visit(i);
      }
  }


}

int main()
{

int edge,vertex ;
cin>>edge>>vertex ;
for(int i=0 ;i<edge;i++)
{
    int x,y ;
    cin>>x>>y ;
    adj[x].push_back(y);
     adj[y].push_back(x);

}

printf("traverse dfs: ");
  dfs(vertex);
cout<<endl ;
  for(int i=1 ;i<=vertex ;i++)
  {
      cout<<"depth for "<<i<<" is : " <<depth[i]<<endl;
  }
cout<<endl ;
for(int i=1 ;i<=vertex ;i++)
{
    printf("%d is parent of %d \n",parent[i],i);
}

}

