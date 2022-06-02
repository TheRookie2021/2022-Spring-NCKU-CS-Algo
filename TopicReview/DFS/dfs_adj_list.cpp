#include <iostream>
#include <list>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first>b.first)return true;
    if(a.first==b.first && a.second<b.second)return true;
    return false;
}

class Graph
{
private:
    int V;
    vector<list<int>> adj_list;
    vector<bool> visited;
    vector<int> cut_point;
    
    void init();
    void countCut();

public:
    Graph(int n);
    int DFS(int source);
    void addEdge(int a, int b);
    void printCut();
    
    void countImportance(int m);
};

Graph::Graph(int n)
{
    V = n;
    adj_list.resize(n);
    visited.resize(n, false);
    cut_point.resize(n, 0);
};

void Graph::init()
{
    for (int i = 0; i < V; i++)
        visited[i] = false;
};

void Graph::addEdge(int a, int b)
{
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
};

int Graph::DFS(int source)
{
    int child_temp = 0;
    visited[source] = true;
    // cout << source << " ";
    list<int>::iterator i;
    for (i = adj_list[source].begin(); i != adj_list[source].end(); i++)
    {
        if (!visited[*i])
        {
            child_temp++, DFS(*i);
        }           
    }
    return child_temp;
};

void Graph::countCut()
{
    for(int i =0;i<V;i++){
        cut_point[i]+=DFS(i);
        init();
    }
}
void Graph::printCut()
{
    for (auto i : cut_point)
        cout << i << " ";
}

void Graph::countImportance(int m)
{
    countCut();
    vector<pair<int,int>> boom;
    for(int i =0;i<V;i++){
        boom.push_back(pair<int, int>(cut_point[i],i));
    }
    sort(boom.begin(),boom.end(),cmp);
    for(int i =0;i<m;i++)
        cout<<boom[i].second<<" "<<boom[i].first<<endl;

}
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    Graph g(n);
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        g.addEdge(a,b);
    }
    
    g.countImportance(m);
    return 0;
}