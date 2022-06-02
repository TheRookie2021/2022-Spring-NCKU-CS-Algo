#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef pair<int, int> X_Y;

int distance(X_Y a, X_Y b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

class Graph
{
private:
    int vertex;
    vector<int> parent;
    // min heap: pair<edge weight, node name>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 


    bool SameUnion(int a, int b);
    int Find(int a);
    void Union(int a, int b);
    void EdgeCount(vector<X_Y> &coordinate);

public:
    Graph(vector<X_Y> &coordinate);
    int MinSpaningTree();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
Graph::Graph(vector<X_Y> &coordinate)
{
    vertex = coordinate.size();
    parent.resize(vertex, -1);
    EdgeCount(coordinate);
};

void Graph::EdgeCount(vector<X_Y> &coordinate){
    for(int i=0;i<vertex;i++){
        for(int j=i+1;j<vertex;j++){
            int temp = distance(coordinate[i], coordinate[j]);
            // cout << "w: " <<temp << " node: " << i << " " << j << endl;
            pq.push(pair<int, pair<int, int>>(temp, pair<int, int>(i, j)));
        }
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graph::SameUnion(int a, int b){
    return (Find(a)==Find(b));// same root == same union => cycle occurs
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
    while(parent[temp]>=0){ // bug: the index 0 sould be include!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        temp=parent[temp];
    }
    return temp;// return the root not the height
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int Graph::MinSpaningTree(){
    // kruskal's
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
    return cost;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n, a, b;
    vector<X_Y> coordinate;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin >> a >> b, coordinate.push_back(X_Y(a, b));
    Graph g(coordinate);
    cout<<g.MinSpaningTree();
    return 0;
}