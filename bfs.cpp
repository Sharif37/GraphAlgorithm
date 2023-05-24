#include<bits/stdc++.h>
using namespace std ;
#define n 100
vector<int>v[n];
bool visited[n];
int level[n] ;
int parent[n] ;

void init(int vertex)
{
    for(int i=0 ;i<vertex ;i++)
    {
        level[i]=0 ;
        parent[i]=-1 ;
        visited[i]=false ;
    }
}

void path(int v)
{
    if(parent[v]==-1){
        cout<<v<<" " ;
        return ;

    }
    path(parent[v]);
    printf(" %d ",v);

}

void bfs(int src )
{

    queue<int> q ;
    q.push(src);
    visited[src]=true ;
    printf("traverse graph:%d ",src);
    parent[src]=-1 ;
    while(!q.empty())
    {
        int u=q.front();

        for(auto neighbour:v[u])
        {
            int vertex=neighbour;
            if(!visited[vertex]){

            printf(" %d ",vertex);
            visited[vertex]=true ;
            level[vertex]=level[u]+1 ;
            parent[vertex]=u ;
            q.push(vertex);

            }

        }
        q.pop();

    }
    printf("\n");
}
int main()
{

int edge,vertex ;
cin>>edge>>vertex ;
for(int i=0 ;i<edge;i++)
{
    int x,y ;
    cin>>x>>y ;
    v[x].push_back(y);
     v[y].push_back(x);

}

 init(vertex) ;


bfs(1);
printf("\n\n");
for(int i=1 ;i<=vertex ;i++)
{
    printf("%d is parent of %d \n",parent[i],i);
}
printf("\n\n");
for(int i=1 ;i<=vertex ;i++)
{
    printf("%d is in level:%d \n",i,level[i]);
}
printf("\n\n");
for(int i=1 ;i<=vertex ;i++)
{
    printf(" shortest path from source to %d is: ",i);
    path(i) ;
    printf("\n");
}


}
