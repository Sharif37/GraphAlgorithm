#include<bits/stdc++.h>
using namespace std ;
struct node{
int src,des,w ;

bool operator<(const node &others)const {

    return w > others.w ;
}

};

vector<node>MST(vector<node>&edges ,int n)
{
    sort(edges.begin(),edges.end());

    vector<node>graph ;
    int e=0 ;
    for(const node &edge:edges)
    {
        int src=edge.src ;
        int des=edge.des ;

        bool cycle=false ;

        for(node &mstedge:graph)
        {
            if( (mstedge.src==src && mstedge.des==des)|| (mstedge.src==des && mstedge.des==src))
            {
                cycle=true ;
                break ;
            }
        }
        if(!cycle)
        {
            graph.push_back(edge);
            e++ ;
        }

        if(e==n-1)
            {
                break ;
            }

    }
    return graph ;
}

int main()
{
  int n,m  ;
  while(scanf("%d%d",&n,&m) && (m+n)){

  vector<node>g;

  for(int i=0 ;i<m ;i++)
  {
      int u,v,w ;
      scanf("%d%d%d",&u,&v,&w);
      g.push_back({u,v,w});
  }

  vector<node>mst=MST(g,n);

//      int ans=1e9 ;
//  for (int i=0 ;i<mst.size();i++) {
//
//        for(int j=i+1;j<mst.size();j++)
//        {
//            ans=min(ans,abs(mst[i].w-mst[j].w));
//        }
//    }
//    if(ans==1e9)
//        printf("a=%d\n",-1);
//    else
//        printf("a=%d\n",ans);

    for (const node & edge : mst) {
        cout << edge.src << " - " << edge.des << " : " << edge.w << endl;
    }



}
}
