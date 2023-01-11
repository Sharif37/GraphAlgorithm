#include<bits/stdc++.h>
using namespace std ;

int visited[100];//visited array
vector<int>v[9] ;//number of vector equivalent to edges number
int level[100];
int parent[100];
void bfs(int src,int vx)
{

    cout<<"traverse graph: " <<src<<" " ;
    queue<int>q ;
    q.push(src) ;
    visited[src]=1 ;
    level[src]=0 ;
    while(!q.empty())
    {
        int u=q.front();//1,2 ,3

        for(int i=0;i<v[u].size();i++)
        {
           int vertex=v[u][i];//2
           if(!visited[vertex])
           {
               cout<<vertex<<" " ;
               level[vertex]=level[u]+1 ;//u=1 level=0
               parent[vertex]=u ;
               visited[vertex]=1 ;
               q.push(vertex);
           }
        }
           q.pop();

    }
    cout<<endl ;

    for(int i=1;i<=vx;i++)
    {
        printf("%d to %d distance %d \n",src,i,level[i]);
      // printf("%d parents is %d \n",i,parent[i]);
    }


}
int vis[100]={};
int p[100]={} ;
int depth[100];
void dfs(int src,int vx)
{

 stack<int>s ;
  cout<<"traverse graph: "<<" " ;
 s.push(src);
 vis[src]=1 ;

 while(!s.empty())
 {
     int t=s.top();
     s.pop();
     cout<<t<<" " ;

     for(auto vertex:v[t])
     {

         if(!vis[vertex])
         {
             //cout<<vertex<<" " ;
             vis[vertex]=1 ;
             s.push(vertex) ;
            p[vertex]=t ;
            depth[vertex]=depth[t]+1 ;
         }
     }

 }
cout<<endl ;
  for(int i=1;i<=vx;i++)
    {
        printf("%d to %d distance %d \n",src,i,depth[i]);
       printf("%d parents is %d \n",i,p[i]);
    }

}

void dfs_using_recursion(int src )
{
    vis[src]=1 ;

    cout<<src<<" " ;
    for(auto neighbour: v[src])
    {
        if(!vis[neighbour])
        {
            dfs_using_recursion(neighbour) ;
        }
    }


}
int main()
{


   int vertex,edges ;
   cin>>edges>>vertex ;
   //vector<int>v0,v1,v2,v3,v4,v5 ;
   for(int i=1;i<=edges ;i++)
   {
       int src,des ;
       cin>>src>>des ;
       v[src].push_back(des);
       v[des].push_back(src);

   }

    //bfs(1,vertex);
   //bfs(1,vertex) ;
   //dfs(1,vertex);
   cout<<"***********" <<endl ;
   dfs_using_recursion(5) ;


}
