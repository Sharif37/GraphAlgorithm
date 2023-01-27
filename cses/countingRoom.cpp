#include<bits/stdc++.h>
using namespace std ;

void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
bool visited[1000][1000]={false};
bool isValid(int x,int y,int n ,int m)
{
    return x>=0 && x<n && y>=0 && y<m ;
}
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};


int main()
{
optimize() ;


int n,m ;
int room=0 ;
cin>>n>>m ;
char arr[n][m];
//visited.resize(n, vector<bool>(m, false));
for(int i=0 ;i<n ;i++)
{
    for(int j=0 ;j<m ;j++)
    {
        cin>>arr[i][j];

    }
}
queue<pair<int ,int>>q ;
for(int i=0 ;i<n ;i++)
{
    for(int j=0 ;j<m ;j++)
    {

        if(arr[i][j]=='.' && !visited[i][j])
        {
               room++ ;
            q.push({i,j});
            visited[i][j]=true ;
            while(!q.empty())
            {
                auto [x,y]=q.front();
                q.pop();
                for(int i=0 ;i<4 ;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];

                    if(isValid(nx,ny,n,m) && arr[nx][ny]=='.' && !visited[nx][ny]  )
                    {

                        visited[nx][ny]=true ;
                        q.push({nx,ny});
                    }

                }
            }


        }
    }
}


cout<<room<<endl ;





}


