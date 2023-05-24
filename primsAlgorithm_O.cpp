#include<bits/stdc++.h>
using namespace std ;

const int MAX = 1e4 + 5;
const int INF = 1e9;

int n, m; // number of vertices and edges
vector<pair<int, int> > adj[MAX]; // adjacency list
int key[MAX]; // minimum weight of an edge from a vertex to a vertex in the tree
int pi[MAX]; // parent of a vertex in the tree
bool in_tree[MAX]; // whether a vertex is in the tree or not

void prim(int start) {
    // initialize key values and pi values
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        pi[i] = -1;
    }

    key[start] = 0; // start vertex has key 0

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // priority queue

    pq.push(make_pair(0, start)); // insert start vertex into priority queue

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (in_tree[u]) continue; // skip if vertex is already in the tree

        in_tree[u] = true; // add u to the tree

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
             cout<<weight<<" "<<key[v]<<endl ;
            // update keys of u's non-tree neighbors
            if (!in_tree[v] && weight < key[v]) {
                key[v] = weight;
                pi[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }
}

void print_path(int start, int end) {
    stack<int> path;
    for (int i = end; i != start; i = pi[i]) {
        path.push(i);
    }
    path.push(start);

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main() {
    // read in the number of vertices and edges
    cin >> n >> m;

    // read in the edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    prim(1); // find MST starting from vertex 1

    // print MST
    for (int i = 2; i <= n; i++) {
            //print_path(1,i);
    }
}

