#include<bits/stdc++.h>
using namespace std ;

void optimize()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int col=0 ,row=0 ;
pair<int ,int>beg ,ed ;
string path="ULRD";
bool visited[1000][1000]={false};
bool isValid(int x,int y,int n ,int m)
{
    return x>=0 && x<n && y>=0 && y<m ;
}
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};
int pystep[1000][1000];
queue<pair<int,int> >q ;

int main()
{
optimize() ;

int n,m ;
cin>>n>>m ;
char arr[n][m];
//visited.resize(n, vector<bool>(m, false));
for(int i=0 ;i<n ;i++)
{
    for(int j=0 ;j<m ;j++)
    {
        cin>>arr[i][j];
        if(arr[i][j]=='A')
        {
            beg=make_pair(i,j);
        }
        if(arr[i][j]=='B')
        {
            ed=make_pair(i,j);
        }

    }
}



   q.push(beg);
    visited[beg.first][ed.second]=true ;
    while(!q.empty())
    {
        auto [x,y]=q.front() ;
        q.pop();
        for(int i=0 ;i<4 ;i++)
        {
            int nx=x+dx[i];
            int ny=y+dx[i];
            if(isValid(nx,ny,n,m) || arr[nx][ny]=='#' || visited[nx][ny] )
            {
                continue ;
            }
            visited[nx][ny]=true ;
            pystep[nx][ny]=i ;
            cout<<"g"<<pystep[nx][ny]<<endl ;
            q.push({nx,ny});
        }
    }

    if(arr[ed.first][ed.second]){
        cout<<"YES"<<endl ;
        vector<int>steps ;
        while(ed!=beg)
        {
            int p=pystep[ed.first][ed.second];
            //cout<<p<<" " ;
            steps.push_back(p);
            ed=make_pair((ed.first-dx[p]),(ed.second-dy[p]));

        }
        reverse(steps.begin(),steps.end());
        cout<<steps.size()<<endl ;

        for(auto u: steps)
        {
            cout<<path[u];
        }
        cout<<endl ;

    }else
    {
        cout<<"NO"<<endl ;
    }


}
