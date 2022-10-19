#include <iostream>
#include <vector>
using namespace std;
#include <limits.h>

int mindistanceance(vector<int> &distance, vector<bool> &sptSet)
{

    // Initialize
    int min = INT_MAX, min_index;

    for (int v = 0; v < distance.size(); v++)
        if (sptSet[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

void dijkstra(vector<vector<int>> &graph, int source)
{
    // Initialize
    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> sptSet(graph.size(), false);

    distance[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < graph.size(); count++)
    {
        int u = mindistanceance(distance, sptSet);
        sptSet[u] = true;
        cout<<u<<":"<<endl;
        for (int v = 0; v < graph.size(); v++)
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v], cout<<"update nodes: "<<u<<" "<<v<<" "<<distance[v]<<endl;
    }

    int sum = 0;
    for (int i = 0; i < graph.size(); i++)
        if (sum < distance[i])
            sum = distance[i];
    cout << sum;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            graph[i][j] = temp;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << graph[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}