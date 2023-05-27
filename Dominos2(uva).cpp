#include<bits/stdc++.h>
using namespace std ;
const int N=10005 ;
bool vis[N];
int c ;
vector<int>adj[N];

void dfs(int src)
{
    c++ ;
    vis[src]=true ;
    //cout<<src<<endl ;
    for(auto u: adj[src])
    {
        if(!vis[u])
        {
           vis[u] =true ;
           dfs(u);
        }
    }

}

int main()
{


    int t ;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,l ;
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0; i<m ; i++)
        {
            int x,y ;
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
        }
        int fallDominos[l];
        for(int i=0 ;i<l ;i++)
        {
            int a ;
            scanf("%d",&a);
            fallDominos[i]=a ;
        }
        for(int i=0 ;i<l ;i++)
        {
             if(!vis[fallDominos[i]])
            dfs(fallDominos[i]);
        }


    printf("%d\n",c);
        c=0 ;
        fill(vis,vis+N,false);
       for(int i=0;i<n ;i++)
       {
           adj[i].clear();
       }



    }

}
