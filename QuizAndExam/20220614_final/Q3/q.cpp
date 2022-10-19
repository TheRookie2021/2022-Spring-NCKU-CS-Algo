
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int MinDis(vector<int> &distance, vector<bool> &mem_set)
{

    // Initialize
    int min = INT_MAX, min_index;

    for (int v = 0; v < distance.size(); v++)
        if (mem_set[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

void dijkstra(vector<vector<int>> &graph, int source)
{
    // Initialize
    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> mem_set(graph.size(), false);

    distance[source] = 0;

    for (int count = 0; count < graph.size(); count++)
    {
        int u = MinDis(distance, mem_set);
        mem_set[u] = true;

        for (int v = 0; v < graph.size(); v++)
            if (!mem_set[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
    }

    int sum = 0;
    for (int i = 0; i < graph.size(); i++)
        if (sum < distance[i])
            sum = distance[i];
       
    cout << sum;
}

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
   
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        graph[a-1][b-1] = w;
        
    }
    // for (int i = 0; i < n ; i++)
    // {
    //     for (int j = 0; j < n ; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dijkstra(graph, 0);

    return 0;
}
