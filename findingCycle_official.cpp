#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100]; // graph represented as an adjacency list
bool visited[100]; // to keep track of visited vertices
vector<int> path; // to keep track of the current path

void DFS(int vertex) {
    visited[vertex] = true;
    path.push_back(vertex);

    for (auto neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        } else {
            cout << "Cycle found: ";
            for (int i = path.size()- 1; path[i] != neighbor; i--) {
                cout << path[i] << " ";
            }
            cout << neighbor << " " << vertex << endl;
        }
    }
   visited[vertex] = false;
   path.pop_back();
}

void find_cycles(int n) {

   DFS(n);
}

int main()
{
int e,v ;
cin>>e>>v ;
for(int i=0 ;i<e ;i++)
{
    int x,y ;
    cin>>x>>y ;
    graph[x].push_back(y);
    //graph[y].push_back(x) ;
}

find_cycles(6);





}
