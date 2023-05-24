#include<bits/stdc++.h>
using namespace std ;


int total_weight ;
int oneItem ;
int weight ;
vector<int>items ;

int main()
{

    int t ;
    cin>>t ;
    while(t--)
    {
        int n,w ;
        cin>>n>>w ;
        int arr[n];
        total_weight=0 ;
        oneItem=0 ;

        for(int i=1 ; i<=n ; i++)
        {
            cin>>weight ;
            if(weight <= w )
            {
                if(weight>=(w/2))
                {
                    oneItem=i ;
                }
                else if ( total_weight < (w/2))
                {
                    items.push_back(i);
                    total_weight+=weight ;
                }
            }

        }

        if(oneItem>0)
        {
            cout<<1<<'\n'<<oneItem<<endl ;

        }
        else
        {
            if(total_weight>=(w/2))
            {
                cout<<items.size()<<endl ;
                for(auto u: items)
                    cout<<u<<" " ;
                    cout<<endl ;
            }
            else
            {
                cout<<-1<<endl ;
            }
        }


        items.clear();

    }

}
