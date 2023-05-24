#include<bits/stdc++.h>
using namespace std ;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n=5,m=8 ;
bool visited[100][100];
//vector<char>grid[100];
char grid[5][8] ;
bool isvalid(int x,int y)
{
  return x>=0 && x<n && y>=0 && y<m ;
}

int   bfs(int x,int y)
{

int room_count=0 ;
if (grid[x][y] == '.' && !visited[x][y]) {
                room_count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (isvalid(nx, ny, n, m) && map[nx][ny] == '.' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }

 }

return room_count;

}



int main()
{
    //cin>>n>>m ;
    for(int i=0 ;i<n ;i++)
    {
        for(int j=0 ;j<m ;j++)
        {
            char c ;
            cin>>c ;
            grid[i][j]=c ;
        }
    }
    int ans=0 ;
 for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j]=='.' && !visited[i][j]){
                  ans+=bfs(i,j);
                    //ans++ ;

            }

        }
    }
    cout<<ans<<endl ;
 // 5 8
//########
//#..#...#
//####.#.#
//#..#...#
//########

}
