#include<bits/stdc++.h>
using namespace std ;
#define  s second
#define f first
pair<int,int>src ,des ;
char mp[1010][1010];
queue<pair<int ,int>>q ;
string path="DURL";
vector<char>v ;
bool visited[1010][1010]={false};
int dis[1010][1010]={-1};
int dir[1010][1010] ;

bool isValid(int x,int y,int n ,int m)
{
    return x>=0 && x<n && y>=0 && y<m ;
}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int  bfs(int n,int m)
{
    q.push(src);
    visited[src.f][src.s]=true ;
    int ans=0 ;
   while(!q.empty())
   {
    int x=q.front().f ;
    int y=q.front().s ;
     if(mp[x][y]=='B')
           {
            return dis[x][y] ;
           }
    q.pop() ;
    for(int i=0 ;i<4 ;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

       if(isValid(nx,ny,n,m) && !visited[nx][ny])
         {
       dis[nx][ny]=dis[x][y]+1 ;
       dir[nx][ny]=i ;
       visited[nx][ny]=true ;
       q.push({nx,ny});
         }
    }

   }
   return -1 ;
}
void print_path() {
    pair<int,int>A=src ;
    pair<int,int>B=des ;

    while (B != A){
            //cout<<B.first<<" "<<B.second<<endl ;
        v.push_back(path[dir[B.first][B.second]]);
        pair <int, int> nxt = {B.first - dx[dir[B.first][B.second]], B.second - dy[dir[B.first][B.second]]};
        B = nxt;
    }
    reverse(v.begin(), v.end());
    for (auto i:v){
        cout << i;
    }
}

int main()
{

int n,m ;
cin>>n>>m ;


 for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if(mp[i][j]=='#')
            {
                visited[i][j]=true ;
            }

            if(mp[i][j]=='A')
            {
                src={i,j};
            }
            if(mp[i][j]=='B')
            {
                des={i,j};
            }
        }
    }

int d = bfs( n,m);
    if (d == -1) {
        puts("NO");
    } else {
        puts("YES");
        printf("%d\n", d);


        print_path() ;
//        for(int i=0 ;i<n ;i++)
//        {
//            for(int j=0 ;j<m ;j++)
//            {
//                cout<<dir[i][j]<<" " ;
//            }
//            cout<<endl ;
//        }

}
}
