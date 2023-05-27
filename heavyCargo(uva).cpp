#include<bits/stdc++.h>
using namespace std ;

struct city{
  string src,des ;
  int w ;
}edges[20000];
long long n,m ;
string x,y ;
map<string ,string >parent ;

bool cmp(city a, city b)
{
    return a.w>b.w ;
}

string find_root(string r)
{
    if(parent[r]=="")
    {
        return r ;
    }
    return parent[r]=find_root(parent[r]);
}
long long kruskal()
{
    sort(edges,edges+m,cmp);
    long long ans=9999999999;
    for(long long  i=0 ;i<m ;i++)
    {
        string u=find_root(edges[i].src);
        string v=find_root(edges[i].des);
        if(u!=v)
        {
            parent[u]=v ;
            if(ans>edges[i].w)
                ans=edges[i].w ;
        }
        if(find_root(x)==find_root(y))
        {
            return ans ;
        }
    }
    return ans ;
}

int main()
{

    long long  caseno=0 ;
    while(scanf("%lld%lld",&n,&m)==2 &&(n+m)!=0)
    {
        parent.clear();
        for(long long  i=0 ;i<m;i++)
        {
            cin>>edges[i].src>>edges[i].des>>edges[i].w ;

        }
        cin>>x>>y ;
       printf("Scenario #%lld\n%lld tons\n\n",++caseno,kruskal());
    }

}
