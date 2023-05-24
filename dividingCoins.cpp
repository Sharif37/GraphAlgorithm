#include<bits/stdc++.h>
using namespace std ;
const int N = 110;
const int MAXN = 102*500;
int weight[N];
int dp[N][MAXN] ;

int sum ;

//used 2D array

int knapSack(int m)
{
    int max_weight=sum/2 ; // here max capacity will be half of  total weight

    for(int i=0; i <=max_weight; i++)
     dp[0][i] = 0;


    for(int i=1 ;i<=m;i++)
    {
        for(int w=0 ;w<=max_weight ;w++)
        {
            if(weight[i]<=w)
            {
               dp[i][w]=max(dp[i-1][w],(dp[i-1][w-weight[i]]+weight[i]));
            }
            else
            {
                dp[i][w]=dp[i-1][w] ;
            }

        }
    }


    return dp[m][max_weight];
}

//using 1D Array (memory optimization)
//int  knapSack(int m)
//{
//    int w=sum/2 ;
//  for(int i=1 ;i<=m ;i++)
//  {
//      for(int j=w ;j>0 ;j--)
//      {
//          if(weight[i]<=j)
//          {
//              dp[j]=max(dp[j],weight[i]+dp[j-weight[i]]);
//          }
//      }
//  }
//    return dp[w];
//}
//

int main()
{

int t ;
scanf("%d",&t);
while(t--)
{
int m ;
scanf("%d",&m);

sum=0 ;
for(int i=1 ;i<=m ;i++)
{
    scanf("%d",&weight[i]) ;
    sum+=weight[i] ;
}

  printf("%d\n", sum - 2*knapSack(m) );
}
return 0 ;
}
