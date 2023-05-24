#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N=1e3+10 ;

int visited[N][N] ;
int n,ax,ay,bx,by,cx,cy ;

bool checkValidMove(int nx,int ny) //new x and new y
{
    if(nx==ax || ny==ay) // check horizontal and vertical
    {
        return true ;
    }
    if(abs(nx-ax)==abs(ny-ay)) //check queen and king are same diagonal or not
    {
        return true ;
    }

    return false ;
}

void dfs(int x,int y) {

    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

        if(x<1 || x>n || y<1 || y>n)
        {
            return ;
        }
        if(visited[x][y])
        {
            return  ;
        }

        if(checkValidMove(x,y))
        {
            return ;
        }
    visited[x][y]=1 ;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            dfs(nx,ny);//check for new cell

        }



}

int main() {

    cin >> n;
   // queen location
    cin >> ax >> ay;
    // king location
    cin >> bx >> by;
    // target location
    cin >> cx >> cy;

    dfs(bx,by);
    if (visited[cx][cy])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

