#include<bits/stdc++.h>
using namespace std ;
int price[25][25];
int dp[205][25];
int M,C ;
int shop(int money,int g)
{
    //cout<<"shop("<<money<<","<<g<<")"<<endl ;
    if(money<0)
        return -1e9 ;
    if(g==C)
        return M-money ;
    if(dp[money][g]!=-1)
        return dp[money][g];
    int ans=-1 ;
    for(int k=1; k<=price[g][0]; k++)
    {
        ans=max(ans,shop(money-price[g][k],g+1)) ;
    }
    return dp[money][g]=ans ;


}

int main()
{

    int t ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&M,&C);
        for(int i=0 ; i<C ; i++)
        {
            scanf("%d",&price[i][0]);
            for(int j=1; j<=price[i][0]; j++)
            {
                scanf("%d",&price[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=shop(M,0);
        if(ans<0)
        {
            printf("no solution\n");
        }
        else
            printf("%d\n",ans);

    }
    return 0 ;
}
