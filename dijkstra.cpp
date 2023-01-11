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
void dijkstra(int start,int vno)
{
   dist[start]=0 ;
   parent[start]=-1 ;
   int u,c,v,weight ;
   priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int ,int>>>pq ;

   pq.push({0,start});

   while(!pq.empty())
   {
       u=pq.top().first ;
       //weight=pq.top().second ;
       pq.pop();
       for(auto i: adj[u])
       {
          v=i.first;
          weight=i.second ;
          if(dist[v]> dist[u]+weight)
          {
              dist[v]=dist[u]+weight;
              pq.push({v,dist[v]});
              parent[v]=u ;
          }


       }
   }
   for(int i=0 ;i<vno ;i++)
   {
      printf("%d : %d \n",i,dist[i]);
   }


}

void path(int j)
{
    if(parent[j]==-1)
    {
        std::cout << j << " ";
        return ;
    }
    path(parent[j]);
    std::cout << j<< " ";

}

void printPath(int end) {
    std::vector<int> path;
    for (int i = end; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        std::cout << path[i] << " ";
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

 void adjlist()
 {
     for(int i=0 ;i<edge ;i++)
     {
         printf("for %d: ",i);
         for(auto u:adj[i])
         {
             cout<<u.first<<" "<<u.second<<endl ;
         }
     }
 }

 dijkstra(0,vertex);




  for (int i = 0; i < vertex; i++)
    {
        std::cout << "Shortest path from 0 to " << i << ": ";
       printPath(i);
        std::cout << " with distance " << dist[i] << std::endl ;
    }

}




