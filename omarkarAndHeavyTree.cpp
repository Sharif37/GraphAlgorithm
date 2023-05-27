#include<bits/stdc++.h>
using namespace std ;

bool res[100005];
int main()
{

    int t ;
    cin>>t ;
    while(t--)
    {
        memset(res,false,sizeof(res));
        int n,m ;
        cin>>n>>m ;
        int a,b,c ;

        for(int i=1 ; i<=m ; i++)
        {
            cin>>a>>b>>c ;
            res[b]=true ;
        }
        int root ;
        for(int i=1 ; i<=n ; i++)
        {
            if(!res[i])
            {
                root=i ;
                break ;
            }
        }

        for(int i=1 ; i<=n ; i++)
        {
            if(i==root)
                continue ;
            else
            {
                cout<<root<<" "<<i<<endl ;
            }
        }

    }

}
