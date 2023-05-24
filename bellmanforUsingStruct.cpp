#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, weight;
};

void BellmanFord(int n, int s, vector<Edge> edges) {
    vector<int> dist(n, INF);
    dist[s] = 0;
    int c=0 ;
    for (int i = 1; i < n; i++) {
        for (auto edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            cout<<u<<" "<<v<<" "<<w<<endl ;
            c++ ;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
   cout<<"c="<<c<<endl ;
    for (auto edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.weight;
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            cout << "Graph contains negative-weight cycle" << endl;
            return;
        }
    }

    cout << "Shortest distances from node " << s << ":" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n, m, s;
    cin >> m >> n >> s;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    BellmanFord(n, s, edges);

    return 0;
}

