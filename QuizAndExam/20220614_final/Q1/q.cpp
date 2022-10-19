#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <limits.h>
using namespace std;

class Graph
{
private:
    int vertex;
    vector<int> parent;
    // min heap: pair<edge weight, node name>
    priority_queue<pair<unsigned long long int, pair<int, int>>> pq; 

    bool SameUnion(int a, int b);
    int Find(int a);
    void Union(int a, int b);
    void EdgeCount(vector<vector<unsigned long long int>> &g);
    
public:
    Graph(vector<vector<unsigned long long int>> &g);
    unsigned long long int MaxSpaningTree();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
Graph::Graph(vector<vector<unsigned long long int>> &g)
{
    vertex = g.size();
    parent.resize(vertex, -1);
    EdgeCount(g);
};

void Graph::EdgeCount(vector<vector<unsigned long long int>> &g)
{
    for(int i=0;i<vertex;i++){
        for(int j=i+1;j<vertex;j++){
            if(g[i][j]!=ULONG_MAX)
                pq.push(pair<int, pair<int, int>>(g[i][j], pair<int, int>(i, j)));
        }
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graph::SameUnion(int a, int b){
    return (Find(a)==Find(b));
};

void Graph::Union(int a, int b){
    if(SameUnion(a,b)) return;
    int root_a=Find(a), root_b=Find(b);
    int height_a = -parent[root_a], height_b = -parent[root_b];
    // cout<<"union node: "<<a<<" "<<b<<endl;
    // cout<<"root: "<<root_a<<" "<<root_b<<endl;
    // cout<<"height: "<<height_a<<" "<<height_b<<endl;
    
    if(height_a==height_b){
        parent[root_b]=root_a;
        parent[root_a]--;
    }else if(height_a>height_b){
        parent[root_b]=root_a;
    }else{
        parent[root_a]=root_b;
    }
};

int Graph::Find(int a){
    int temp=a;
    while (parent[temp] >= 0)
    {
        temp = parent[temp];
    }
    return temp;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned long long int Graph::MaxSpaningTree(){

    unsigned long long int cost=0;
    int visit=vertex-1;
    int a, b;

    while(visit)
    {
        a = pq.top().second.first;
        b = pq.top().second.second;
            
        if (!SameUnion(a, b))
        {
            // cout<<"take cost: "<<pq.top().first<<" node: "<<a<<" "<<b<<endl;
            Union(a, b);
            
            visit--;
            cost += pq.top().first;
        }
        pq.pop();
    }
    cout<<cost;
    return cost;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n, m,a, b;
    unsigned long long int w;
    cin >> n >> m;
    vector<vector<unsigned long long int>> graph(n,vector<unsigned long long int>(n,ULONG_MAX));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    Graph g(graph);
    g.MaxSpaningTree();
    return 0;
}