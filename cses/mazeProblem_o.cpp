
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int x,int y ,int n)
    {
        return (x>=0 && x<n && y>=0 && y<n ) ;
    }
     bool vis[10][10];
      int dx[4]={1,-1,0,0} ;
      int dy[4]={0,0,1,-1} ;
     vector<string>result ;
     string path ;
     char dir[4]={'D','U','R','L'} ;
     void  dfs(vector<vector<int>> &m,int x,int y,int n)
     {
         if(!isValid(x,y,n) || m[x][y]==0 || vis[x][y]==true)
         {
             return ;
         }
         if(x==n-1 && y==n-1)
         {
             result.push_back(path);
         }
         vis[x][y]=true ;
         for(int i=0 ;i<4 ;i++)
         {
             int nx=x+dx[i];
             int ny=y+dy[i];
             path.push_back(dir[i]);
             dfs(m,nx,ny,n);
             path.pop_back();
         }
             vis[x][y]=false;




     }


    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       for(int i=0 ;i<n ;i++)
       {
           for(int j=0 ;j<n ;j++)
           {
               vis[i][j]=false ;
           }
       }
       if(m[0][0]==1)
       dfs(m,0,0,n);
      return result;

    }

};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
