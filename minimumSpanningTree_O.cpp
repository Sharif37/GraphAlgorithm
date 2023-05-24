#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
int V, E;
vector<pair<int, int>> adj[MAX];
bool visited[MAX];

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int mst_weight = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        mst_weight += q.top().first;
        for (auto edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (!visited[v]) q.push({w, v});
        }
    }
    return mst_weight;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    cout << "Minimum spanning tree weight: " << prim() << endl;
    return 0;
}

