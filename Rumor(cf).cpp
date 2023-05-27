#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N=1e5+10 ;
vector<ll>adj[N] ;
vector<bool>visited(N,false) ;
ll cost[N] ;
ll ans=0 ;

ll dfs( ll src)
{

    ll m=cost[src];
    visited[src]=true ;
    for(auto u:adj[src])
    {
        if(!visited[u])
        {
            m=min(m,dfs(u));
        }
    }
return m ;
}



int main()
{
 ll n,m ;
 cin>>n>>m ;
 for(ll i=1;i<=n ;i++)
 {
     ll a ;cin>>a ;
     cost[i]=a ;
 }
 for(ll i=0 ;i<m ;i++)
 {
     ll x,y ;
     cin>>x>>y ;
     adj[x].push_back(y);
     adj[y].push_back(x);
 }

  for(ll i=1 ;i<=n ;i++)
  {
      if(!visited[i])
      {
          ans+=dfs(i);
      }
  }
 cout<<ans<<endl ;

}
