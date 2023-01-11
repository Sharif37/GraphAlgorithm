#include<bits/stdc++.h>
using namespace std ;
vector<int>v[10];
bool visited[100];

void dfs(int src,int VertexNo)
{
   printf("%d ",src);
   visited[src]=true ;
  for(auto vertex: v[src])
  {
      if(!visited[vertex])
      dfs(vertex,VertexNo);
  }


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

printf("traverse dfs: ");
  dfs(5,vertex);



}

