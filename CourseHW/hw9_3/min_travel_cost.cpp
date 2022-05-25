#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
// 移動1000, 修復870000
// 希望用最少的花費，修好所有的村莊
// Q: what is the min steps to travel between the broken villiage

typedef pair<int, int> Level_Child;

int min_step_between_villiage(vector<list<int>> &graph,vector<vector<int>> &graph_matrix, vector<bool> &broken_village, int num_broken)
{
    int steps = 0;
    int visied_broken = 0;
    vector<bool> visited(broken_village.size(), false);
    vector<Level_Child> tree(broken_village.size(), Level_Child(0, 0));
    // bool branch_is_broken=false;// if the branch is not broken till the leaves, retreat with step--
    // where to start?
    // the broken node with min edges

    // there are two moving direction: go and come back
    // we need to mark/delete the visited step

    // 1. decide the root: O(M)
    int min_edge = broken_village.size() + 1;
    int cur_pos, pre_pos;
    for (int i = 0; i < broken_village.size(); i++)
    {
        if (broken_village[i])
        {
            if (min_edge > graph[i].size())
                min_edge = graph[i].size(), cur_pos = i;
        }
    }
    cout<<cur_pos<<endl;
    // 2. build a DFS spaning tree O(n)
    stack<pair<int,int>> s;// node and connected node
    list<int> path;
    int start=1;
    s.push (pair<int,int>(cur_pos,start));
    while (!s.empty())
    {
        if(visied_broken==num_broken) break;
        steps++;
            
        cur_pos = s.top().first;
        start = s.top().second;
        s.pop();

        // cout << cur_pos << " ";
        // cout << cur_pos << " ";

        visited[cur_pos] = true;
        if(broken_village[cur_pos]){
            visied_broken++;
            broken_village[cur_pos] = false;
        }
        for (int j = start; j <= graph_matrix[cur_pos].size(); j++)
        {
            if (graph_matrix[cur_pos][j] == 1 && !visited[j])
            {
                s.push(pair<int, int>(cur_pos, j));
                s.push(pair<int, int>(j, 1));
                break;
            }
        }
    }
    // cout << steps - 1;
    // 3. trim the node without child and not broken O(n)

    // 3. traverse O(n)

    // problem stuck: how to remove the redundent step?(visited the direction/branch with no broken village)
    return steps-1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<list<int>> graph;

    vector<vector<int>> graph_matrix(n+1, vector<int>(n+1, 0));
    vector<bool> broken_village(n + 1); // serve as a hash table, true: broken, false: not broken

    for (int i = 0; i <= n; i++)
        broken_village[i] = false;

    for (int i = 0; i <= n; i++)
    {
        list<int> l;
        graph.push_back(l);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

        graph_matrix[a][b]=1;
        graph_matrix[b][a]=1;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        broken_village[temp] = true;
    }
    // input----------------------------------------
    // output----------------------------------------
    int money = m * 870000;
    int steps;
    steps=min_step_between_villiage(graph,graph_matrix, broken_village, m);
    cout<<money+steps*1000;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j =1; j <= n; j++)
    //         cout << graph_matrix[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}