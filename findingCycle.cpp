#include<bits/stdc++.h>
using namespace std ;
#define V 11
vector<int>adj[V];
bool visited[V];
vector<int>path ;
void dfs(int src,int v)
{
    visited[src]=true ;
     path.push_back(src);
    for(auto vertex: adj[src])
    {
        if(!visited[vertex])
        {
         dfs(vertex,v);
        }
        else{
        cout<<" cycle found: " ;
          for(int i=path.size()-1 ;path[i]!=vertex ;i--)
          {
              cout<<path[i]<<" " ;

          }
         cout<<vertex<<" "<<src<<" " ;
        }

    }
    visited[src]=false ;
    path.pop_back();
     //cout<<endl ;
}

void display()
{
    for(int i=2 ;i<=9 ;i++)
    {
        cout<<i<<" : "  ;
        for(auto u:adj[i])
        {
            cout<<u<<" " ;
        }
        cout<<endl ;
    }
}

int main()
{
int e,v ;
cin>>e>>v ;
for(int i=0 ;i<e ;i++)
{
    int x,y ;
    cin>>x>>y ;
    adj[x].push_back(y);
    //adj[y].push_back(x) ;
}

display();

dfs(2,V);





}
