#include<bits/stdc++.h>
using namespace std ;
const int MaxN=1e5+1 ;
void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
vector<int>adj[MaxN];
int color[MaxN];

void dfs(int x,int c)
{
    color[x]=c ;
    for(int u:adj[x])
    {
        if(color[x]==color[u])
        {
            cout<<"IMPOSSIBLE"<<endl ;
            exit(0);
        }
        else if(!color[u])
        {
            if(color[x]==1)
                dfs(u,2);
            else
               dfs(u,1) ;
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
for(int i=1 ;i<=n ;i++)
{
    if(!color[i])
    {
        dfs(i,1);
    }
}
for(int i=1 ;i<=n ;i++)
{
   cout<< color[i]<<" " ;
}

}
