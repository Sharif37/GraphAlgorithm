#include<bits/stdc++.h>
using namespace std ;
const int vertex=10 ;
const int INF=numeric_limits<int>::max();
vector<pair<int,int>>adj[50];
vector<int>dist(vertex,INF);

void addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void init()
{
    dist[0]=0 ;
}

int bell(int n)
{
    init();
    int v,wt ;
    for(int i=0 ;i<n ;i++)
    {
        for(int u=0 ;u<n ;u++)
        {
            for(int j=0 ;j<adj[u].size();j++)
            {
                v=adj[u][j].first ;
                wt=adj[u][j].second ;
                if(i==n-1 && dist[v]>dist[u]+wt)
                {
                    return 0 ;
                }
                else if(dist[v]>dist[u]+wt)
                {
                    dist[v]=dist[u]+wt ;
                }

            }
        }
    }
    return 1 ;
}


int main()
{
 int vertex,edges ;
 cin>>edges>>vertex ;
 for(int i=1;i<=edges ;i++)
 {
     int x,y,w ;
     cin>>x>>y>>w ;
     adj[x].push_back({y,w});
 }
int  res=bell(vertex);
 if(res)
 {
     cout<<"Not possible"<<endl ;
 }
 else
 {
     cout<<"possible"<<endl ;
     for(int i=0 ;i<vertex ;i++)
     {
         cout << i << " " << dist[i] << endl;
     }
 }




}
