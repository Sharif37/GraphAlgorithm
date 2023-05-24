#include<bits/stdc++.h>
using namespace std ;


bool find_negative_cycle(vector<pair<int,int>>adj[],int noVertices,int source)
{
    vector<int>distance(noVertices,numeric_limits<int>::max());
    distance[source]=0 ;

    //Relaxation
    for(int i=0 ; i<noVertices-1; i++)
    {
        for(int u=0; u<noVertices; u++)
        {
            for(auto edges: adj[u])
            {
                int v=edges.first ;
                int weight=edges.second ;
                if(distance[u]!=numeric_limits<int>::max() && distance[u]+weight<distance[v])
                {
                    distance[v]=distance[u]+weight ;
                }
            }
        }
    }

    //additional iteration to check negative cycle
    for(int i=0 ; i<noVertices ; i++)
    {
        for(auto edges: adj[i])
        {
            int v=edges.first ;
            int weight=edges.second ;
            if(distance[i]!=numeric_limits<int>::max() && distance[i]+weight<distance[v])
            {
                return true ;
            }
        }
    }
    return false ;

}


int main()
{

    int t,n,m; //star system , wormholes
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        vector<pair<int,int>>adj[n+10] ;
        for(int i=0 ; i<m ; i++)
        {
            int u,v,w ;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back({v,w});

        }

        if(find_negative_cycle(adj,n,0))
        {
            printf("possible\n");
        }
        else
        {
            printf("not possible\n");
        }
    }

    return 0 ;
}
