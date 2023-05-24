#include<bits/stdc++.h>
using namespace std ;
#define  n 1e4
#define pr pair<int,int>
int INF=1e9 ;
vector<pair<int,int>>adj[n];
int dist[n] ;
bool in_tree[n];
int parent[n];
void init()
{
    for(int i=0 ;i<n ;i++)
    {
        dist[i]=INF ;
        in_tree[i]=false ;
        parent[i]=-1 ;
    }
}

void print_path(int start, int end) {
    stack<int> path;
    for (int i = end; i != start; i = parent[i]) {
        path.push(i);
    }
    path.push(start);

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout <<endl;
}

void prims(int start)
{
  priority_queue<pr,vector<pr>,greater<pr>>pq ;
  pq.push({0,start});
   dist[start]=0 ;
  while(!pq.empty())
  {
      int u=pq.top().second ;
      pq.pop();
      if(in_tree[u])
        continue ;
        in_tree[u]=true ;
        for(int i=0 ;i<adj[u].size();i++)
        {
            int v=adj[u][i].first ;
            int weight=adj[u][i].second;
            if(!in_tree[v] && weight<dist[v])
            {
                dist[v]=weight ;
                parent[v]=u ;
                pq.push({dist[v],v});
            }

        }

  }

}
int main()
{
    init();
    int v,e ;
    cin>>v>>e ;
    for(int i=1;i<=e ;i++)
    {
        int u,v,w;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    prims(1);
    for(int i=2 ;i<=v ;i++){
    print_path(1,i);
    }
}
