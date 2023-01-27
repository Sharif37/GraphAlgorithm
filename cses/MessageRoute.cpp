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
vector<int>connection ;
int parent[MaxN];
int level[MaxN];
queue<int>q ;
void bfs(int x)
{
   q.push(x);
   visited[x]=true ;
   while(!q.empty()){
        int v=q.front();
        q.pop();
   for(auto u:adj[v])
   {
       if(visited[u]==false)
       {
           visited[u]=true ;
          parent[u]=v ;
          level[u]=level[v]+1 ;
           q.push(u);
       }
   }
   }

}
void path(int n)
{
    if(n==-1) {
        return  ;
    }
    connection.push_back(n);
    n=parent[n]  ;
    path(n);

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

bfs(1);
   parent[1]=-1 ;

  if(!visited[n])
  {
      cout<<"IMPOSSIBLE"<<endl ;
      return 0 ;
  }
  path(n);
int l=connection.size();
cout<<l<<endl ;
for(int i=l-1 ;i>=0 ;i--)
    cout<<connection[i]<<" ";
//for(int i=1 ;i<=n ;i++)
//    cout<<parent[i]<<" " ;
}
