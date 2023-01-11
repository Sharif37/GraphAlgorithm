#include <iostream>
#include <vector>

const int INF = 1e9;

void BellmanFord(const std::vector<std::vector<std::pair<int, int>>>& graph,
                 std::vector<int>& distance,
                 std::vector<int>& predecessor,
                 int source)
{
    // Initialize distances and predecessors
    int V = graph.size();
    distance.resize(V);
    predecessor.resize(V);
    for (int i = 0; i < V; i++)
    {
        distance[i] = INF;
        predecessor[i] = -1;
    }
    distance[source] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V-1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (const auto& [v, w] : graph[u])
            {
                if (distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    predecessor[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < V; u++)
    {
        for (const auto& [v, w] : graph[u])
        {
            if (distance[u] + w < distance[v])
            {
                std::cout << "Graph contains a negative cycle" << std::endl;
                return;
            }
        }
    }
}

void printPath(const std::vector<int>& predecessor, int destination)
{
    if (predecessor[destination] == -1)
    {
        std::cout << destination << " ";
        return;
    }
    printPath(predecessor, predecessor[destination]);
    std::cout << destination << "u ";
}

int main()
{
    // Create an example graph
    int V = 5;
    std::vector<std::vector<std::pair<int, int>>> graph(V);
    graph[0].push_back({1, -1});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 2});
    graph[1].push_back({4, 2});
    graph[3].push_back({1, 1});
    graph[3].push_back({2, 5});
    graph[4].push_back({3, -3});

    // Run the Bellman-Ford algorithm
    std::vector<int> distance, predecessor;
    BellmanFord(graph, distance, predecessor, 0);

    // Print the shortest paths
    for (int i = 0; i < V; i++)
    {
        std::cout << "Shortest path from 0 to " << i << ": ";
        printPath(predecessor, i);
        std::cout << " with distance " << distance[i] << std::endl ;
    }

}
