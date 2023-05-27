#include<bits/stdc++.h>
using namespace std ;
vector<int>adj[60];
vector<bool>vis(60,false);
void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int c=0 ;
void dfs(int src)
{
  vis[src]=true ;
   c++ ;
  for(auto u: adj[src])
  {
      if(!vis[u])
      {
          dfs(u);
      }
  }
}


int main()
{
optimize() ;

int t=1 ;

while(t--)
{
int n,m ;
cin>>n>>m ;


for(int i=0 ;i<m ;i++)
{
    int x,y ;
    cin>>x>>y ;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

long long  ans=1 ;
for(int i=1;i<=n ;i++)
{
    if(!vis[i])
    {
        dfs(i) ;

    ans*=pow(2,c-1);

    }
    c=0 ;
}


cout<<ans<<endl ;

}

}
