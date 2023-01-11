#include<bits/stdc++.h>
using namespace std ;
vector<int>v[10];
bool visited[100];
void bfs(int src,int VertexNo)
{
    queue<int> q ;
    q.push(src);
    visited[src]=true ;
    printf("traverse graph:%d ",src);

    while(!q.empty())
    {
        int u=q.front();
        for(int i=0 ;i<v[u].size();i++)
        {
            int vertex=v[u][i];
            if(!visited[vertex]){
            printf(" %d ",vertex);
            visited[vertex]=true ;
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


bfs(5,vertex);



}
