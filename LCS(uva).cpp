#include<bits/stdc++.h>
using namespace std ;

void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int dp[1001][1001];
int lcs(string text1,string text2)
{
    int s=text1.size();
    int o=text2.size();

    for(int i=0 ;i<=s ;i++)
        dp[i][0]=0 ;
    for(int i=0 ;i<=o ;i++)
        dp[0][i]=0 ;

    for(int i=1 ;i<=s ;i++)
    {
        for(int j=1 ;j<=o ;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }


    }

    return dp[s][o];
}

int main()
{
optimize() ;
char s[1010],t[1010];

while(gets(s) && gets(t))
{

 printf("%d\n",lcs(s,t));

}

}
