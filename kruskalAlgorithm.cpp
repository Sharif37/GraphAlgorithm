#include<bits/stdc++.h>
using namespace std ;

struct Edge{
    int src,des,w ;
};

struct Compare{
    bool operator()(const Edge &a,const Edge &b){
        return a.w>b.w ;
    }
};
int findParent(int node,vector<int>&parent)
{
    if(parent[node]==-1)
        return node ;

    return findParent(parent[node],parent);

}
vector<Edge>kruskalMst(vector<Edge>&edges ,int numVertex)
{
    vector<Edge>mst ;
    vector<int>parent(numVertex,-1);

    priority_queue<Edge ,vector<Edge>,Compare>pq(edges.begin(),edges.end());
    while(!pq.empty() && mst.size()<numVertex-1)
    {
        Edge nextEdge=pq.top();
        pq.pop();
        int x=findParent(nextEdge.src,parent);
         int y=findParent(nextEdge.des,parent);
        if(x!=y)
        {
            mst.push_back(nextEdge);
            parent[x]=y ;
        }
    }
    return mst ;
}

int main()
{
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    vector<Edge>mst=kruskalMst(edges,4);

    for(auto edge:mst)
    {
        cout << edge.src << " -- " << edge.des << " : " << edge.w << endl;
    }

}
