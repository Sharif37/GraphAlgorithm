#include<bits/stdc++.h>
using namespace std ;


long long  total_weight ;
long long  oneItem ;
long long  weight ;
vector<int>items ;

int main()
{

    int t ;
    cin>>t ;
    while(t--)
    {
        long long n,w ;
        cin>>n>>w ;


        total_weight=0 ;
        oneItem=0 ;

        for(int i=1 ; i<=n ; i++)
        {
            cin>>weight ;
            if(weight <= w )
            {
                if(weight>=(w+1)/2)
                {
                    oneItem=i ;
                }
                else if ( total_weight < (w+1)/2)
                {
                    items.push_back(i);
                    total_weight+=weight ;
                }
            }

        }

        if(oneItem>0)
        {
            cout<<1<<'\n'<<oneItem ;

        }
        else
        {
            if(total_weight>=(w+1)/2)
            {
                cout<<items.size()<<endl ;
                for(auto u: items)
                    cout<<u<<" " ;

            }
            else
            {
                cout<<-1 ;
            }
        }

        cout<<endl;
        items.clear();

    }

}
