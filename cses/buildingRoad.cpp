#include<bits/stdc++.h>
using namespace std ;

void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
vector<int>adj[100010];
bool visited[200010]={false};
vector<int>connection ;
void dfs(int x)
{
   visited[x]=true ;
   for(auto u:adj[x])
   {
       if(visited[u]==false)
       dfs(u);
   }

}

int main()
{
//optimize() ;

int n,m ;
cin>>n>>m ;
for(int i=0 ;i<m ;i++)
{
    int a,b;
    cin>>a>>b ;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
for(int i=1 ;i<=n ;i++)
{
    if(visited[i]==false)
    {
      connection.push_back(i);
      dfs(i);
    }
}
int l=connection.size();
cout<<l-1<<endl ;
for(int i=1 ;i<l ;i++)
{
    cout<<connection[i-1]<<" "<<connection[i]<<endl ;
}

}
