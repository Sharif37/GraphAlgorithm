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
          int c=0 ;
        for (int u = 0; u < V; u++)
        {
            for ( auto [v, w] : graph[u])
            {
                std::cout<<u<<" "<<v<<" "<<w<<std::endl ;
                c++ ;
                if (distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    predecessor[v] = u;
                }
            }
        }
        std::cout<<c<<std::endl ;


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
    std::cout << destination << " ";
}

int main()
{
    // Create an example graph
    int V = 5;
    std::vector<std::vector<std::pair<int, int>>> graph(10);
    int vertex,edges ;
std:: cin>>edges>>vertex ;
 for(int i=1;i<=edges ;i++)
 {
     int x,y,w ;
     std::cin>>x>>y>>w ;
     graph[x].push_back({y,w});
 }

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
