#include <iostream>
#include <vector>
#include <list>
#include<stack>
using namespace std;
void printGraph(vector<vector<bool>> &graph)
{
    int n = graph.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

stack<int> DFS(vector<vector<bool>> &graph,int source)
{
    // notice: how to use DFS in bidirected edge
    int n = graph.size();
    int cur_pos, i_start;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<bool> visited_node(n, false);
    vector<bool> finish_node(n, false);
    
    stack<int> finish;

    stack<pair<int,int>> s;
    s.push(pair<int,int>(source,1));
    
    while(!s.empty()){
        cur_pos=s.top().first;
        i_start=s.top().second;
        s.pop();
        for(int i =i_start;i<n;i++){
            if (graph[cur_pos][i] && !visited[cur_pos][i] && !visited_node[i])
            {
                s.push(pair<int, int>(cur_pos, i));
                s.push(pair<int, int>(i, 1));
                visited[cur_pos][i] = true;
                visited_node[i]=true;
                break;
            }
            else if (i == n - 1 && !finish_node[cur_pos])
            { // no node to be visited next
                finish_node[cur_pos] = true;
                finish.push(cur_pos);
                // cout<<"finish: "<<cur_pos<<" ";
            }
        }
    }

    return finish;// increasing order of the finish time of each node
}

bool DFS_SCC(vector<vector<bool>> &graph, stack<int> &finish)
{
    int n = graph.size();
    int cur_pos, i_start;
    vector<vector<bool>> visited_edge(n,vector<bool>(n,false));
    vector<bool> finish_node(n, false);
    int component=0;

    stack<pair<int,int>> s;
    while (!finish.empty())
    {
        if (finish_node[finish.top()]==false)
        {
            s.push(pair<int, int>(finish.top(), 1));
            finish.pop();
            component++;
        }
        else
        {
            finish.pop();
            continue;
        }
        if (component > 1) break;
        //--------------------------------------------------------------
        while (!s.empty())
        {
            cur_pos = s.top().first;
            i_start = s.top().second;
            s.pop();
            for (int i = i_start; i < n; i++)
            {
                if (graph[cur_pos][i] && !visited_edge[cur_pos][i])
                {
                    s.push(pair<int, int>(cur_pos, i));
                    s.push(pair<int, int>(i, 1));
                    visited_edge[cur_pos][i] = true;
                    break;
                }else if(i==n-1){
                    finish_node[cur_pos]=true;
                }
            }
        }
    }

    return (component==1);// increasing order of the finish time of each node
}
void Transpose(vector<vector<bool>> &graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 1 1, 1 0, 0 1, 0 0
            if (graph[i][j] != graph[j][i])
                graph[i][j] = !graph[i][j], graph[j][i] = !graph[j][i];
        }
    }
}

bool isStronglyConnected(vector<vector<bool>> &graph)
{
    int n = graph.size() - 1;
    stack<int> finish_orig,finish_trans;
    finish_orig=DFS(graph,1);
    // cout<<"size"<<finish_orig.size();
    if(finish_orig.size()!=n)return false;
    Transpose(graph);
    return DFS_SCC(graph,finish_orig);
    
}

int main()
{
    int n, m, a, b, c;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 || m == 0)
            break;

        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false)); // node start from 1
        while (m--)
        {
            cin >> a >> b >> c;
            graph[a][b] = true;
            if (c == 2)
                graph[b][a] = true;
        }
        // printGraph(graph);
        // cout<<endl;
        // Transpose(graph);
        // printGraph(graph);
        // cout << endl;
        // Transpose(graph);

        if (isStronglyConnected(graph))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}