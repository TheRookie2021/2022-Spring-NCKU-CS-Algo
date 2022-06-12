    #include <iostream>
    #include <vector>
    #include <queue>
    #include <limits.h>
    using namespace std;
    typedef pair<int, pair<int, int>> E_V;
    int Dijkstra(vector<vector<int>> &graph, int source)
    {
        int sum = 0;
        int n = graph.size();
        priority_queue<E_V, vector<pair<int, pair<int, int>>>, greater<E_V>> pq;
        // initialize record
        vector<int> distance(n, INT_MAX);
        vector<int> node_before(n, -1);
        vector<bool> visited(n,0);
        for (int j = 0; j < n; j++)
        {
            if (graph[source][j] != 0)
            {
                pq.push(E_V(graph[source][j], pair<int, int>(source, j)));
            }
        }
        distance[source] = 0;
        node_before[source] = source; // root

        // start spanning
        while (!pq.empty())
        {
            int cur_node = pq.top().second.first;
            int next_node = pq.top().second.second;
            int weight = pq.top().first;
            visited[cur_node]=true;
            pq.pop();

            // if (node_before[next_node] == -1)
            // {
            //     node_before[next_node] = cur_node;
            //     distance[next_node] = weight + distance[cur_node];
            // }
            // else
            {
                if (distance[next_node] > weight + distance[cur_node])
                {
                    node_before[next_node] = cur_node;
                    distance[next_node] = weight + distance[cur_node];
                }
            }

            if (!visited[next_node])
                for (int j = 0; j < n; j++)
                {
                    if (graph[next_node][j] != 0)
                    {
                        pq.push(E_V(graph[next_node][j], pair<int, int>(next_node, j)));
                    }
                }
        }

        // for (int i = 0; i < n; i++)
        //     cout << distance[i] << " ";
            
        for (int i = 0; i < n; i++)
            if (sum < distance[i])
                sum = distance[i];
        return sum;
    }

    int main()
    {
        int n, temp;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cin >> temp;
                graph[i][j] = temp;
                graph[j][i] = temp;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         cout << graph[i][j] << " ";
        //     cout << endl;
        // }
        cout<<Dijkstra(graph,0);

        return 0;
    }