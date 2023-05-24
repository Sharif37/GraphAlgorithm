#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max(); // represents infinity

// Number of vertices
const int V = 15;
int edges,vertex ;
// Adjacency list
vector<pair<int, int>> adj[V];

// Function to add an edge to the graph
void addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

// Dijkstra's shortest path algorithm
void dijkstra(int start)
{
    // Create a priority queue to store vertices that are being preprocessed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create a vector for distances and initialize all distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert the source node with distance 0
    pq.push({0, start});
    dist[start] = 0;

    // Looping till priority queue becomes empty (or all
    // distances are not finalized)
    while (!pq.empty())
    {
        int u = pq.top().second;
        cout<<"u= "<<u<<" " ;
        pq.pop();

        // Get all adjacent of u and update the dist[]
        for (auto i : adj[u])
        {
            int v = i.first;
            int weight = i.second;

            // Relaxation step
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the calculated shortest distances
    for (int i = 1; i <= vertex; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
    // Adding edges to the graph

    cin>>edges>>vertex ;
    for(int i=0 ;i<edges ;i++)
    {
        int x,y,w ;
        cin>>x>>y>>w ;
        addEdge(x,y,w);
    }

    // Starting node
    int start = 1;

    dijkstra(start);

    return 0;
}

