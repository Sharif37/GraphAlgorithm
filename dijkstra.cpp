#include<bits/stdc++.h>
using namespace std ;
#define n 50
const  int INF=numeric_limits<int>::max();

vector<pair<int ,int>>adj[n] ;
vector<int>dist(n,INF);
int parent[100];

void addedge(int u,int v,int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});

}
void dijkstra(int start )
{
   dist[start]=0 ;
   parent[start]=-1 ;
   int u,c,v,weight ;
   priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int ,int>>>pq ;

   pq.push({0,start});

   while(!pq.empty())
   {
       int u=pq.top().second ;
       pq.pop();

       for(auto i: adj[u])
       {
          v=i.first;
          weight=i.second ;
          if(dist[v]> dist[u]+weight)
          {
              dist[v]=dist[u]+weight;
              pq.push({dist[v],v});
              parent[v]=u ;
          }


       }
   }


}
//print path using recursion
void path(int j)
{
    if(parent[j]==-1)
    {
        cout << j << " ";
        return ;
    }
    path(parent[j]);
    cout << j<< " ";

}
//print path using array .
void printPath(int End) {
    vector<int> path;
    for (int i = End; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}

//adj. list print
void adjlist(int vertex)
 {
     for(int i=1 ;i<=vertex ;i++)
     {
         printf("for %d: ",i);
         for(auto u:adj[i])
         {
             cout<<"{"<<u.first<<","<<u.second<<"}" ;
         }
         cout<<endl ;
     }
 }


int main()
{

 int edge,vertex ;
 cin>>edge>>vertex ;
 for(int i=0 ;i<edge;i++)
 {
     int u,v,w ;
    cin>>u>>v>>w ;
     addedge(u,v,w);
 }


 dijkstra(1);

 adjlist(vertex);


  for (int i = 1; i <=vertex; i++)
    {
        std::cout << "Shortest path from 1 to " << i << ": ";
       printPath(i);
        std::cout << " with distance " << dist[i] << std::endl ;
    }

}




