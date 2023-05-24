#include<bits/stdc++.h>
using namespace std ;
const int N=200000 ;
int visited[N];

void bfs(vector<int>graph[],int parent[],int source)
{
    queue<int>q ;
    q.push(source);
    visited[source]=1 ;
    parent[source]=-1 ;
    while(!q.empty())
    {
        int v=q.front();
        for(auto u: graph[v])
        {
            if(!visited[u])
            {
                parent[u]=v ;
                visited[u]=true ;
                q.push(u);

            }
        }
           q.pop() ;
    }

}

void path(int parent[],int src) // using recursion for finding parent ( destination to source)
{

    if(parent[src]==-1){
            printf("%d ",1);
        return ;
    }


   path(parent ,parent[src]);
   printf("%d ",src);
}

int main()
{
 int n ;
 cin>>n ;
 vector<int>graph[n+5];

 int parent[n]={} ;
 //8
 //1 1 2 2 3 2 5

 for(int i=2 ;i<=n ;i++)
 {
     int a;
     cin>>a ;
     graph[i].push_back(a);
     graph[a].push_back(i);
 }

 bfs(graph,parent,1) ;
 path(parent,n);


 //** you can use this path(parent,n) method  or this block of code to print path **

 /*
 int src=n ;
 set<int>path ;
 while(src!=-1)
 {
     path.insert(src);
     src=parent[src] ;
 }
 for(auto u: path)
    cout<<u<<" " ;*/


}
