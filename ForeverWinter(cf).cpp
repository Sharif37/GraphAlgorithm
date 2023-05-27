#include<bits/stdc++.h>
using namespace std ;
const int N=210 ;

//vector<int>vis(210,0);
//vector<int>parent(210,-1);
//void bfs(int src)
//{
//    vis[src]=1 ;
//    queue<int>q ;
//    q.push(src);
//    while(!q.empty())
//    {
//        int u=q.front();
//        q.pop();
//        for(auto v:adj[u])
//        {
//            if(!vis[v])
//            {
//                vis[v]=1 ;
//                parent[v]=u ;
//                q.push(v);
//            }
//        }
//    }
//}
//void dfs(int src)
//{
//    vis[src]=1 ;
//    for(auto u: adj[src])
//    {
//        if(!vis[u])
//        {
//            parent[u]=src ;
//            dfs(u);
//        }
//    }
//}
void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}


int main()
{
optimize() ;

int t ;
cin>>t ;
while(t--)
{
    int adj[N]={0};
int n,m ;
cin>>n>>m ;

for(int i=0 ;i<m ;i++)
{
    int x,y ;
    cin>>x>>y ;
     adj[x]++ ;
     adj[y]++ ;

}

int c=0 ;

for(int i=1;i<=n;i++)
{
   if(adj[i]==1)
   {
       c++ ;
   }
}
cout<<m-c<<" "<<c/(m-c)<<endl ;





}

}
