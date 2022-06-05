#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<limits.h>
using namespace std;


int distance(string &a, string &b){
    int temp = 0;
    for (int k = 0; k < 7; k++)
    {
        if (a[k] != b[k])
            temp++;
    }
    return temp;
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
    void EdgeCount(vector<string> &v);

public:
    Graph(vector<string> &v);
    int MinSpaningTree();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
Graph::Graph(vector<string> &v)
{
    vertex = v.size();
    parent.resize(vertex, -1);
    EdgeCount(v);
};

void Graph::EdgeCount(vector<string> &v){
    for(int i=0;i<vertex;i++){
        for(int j=i+1;j<vertex;j++){
            int temp = distance(v[i], v[j]);
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
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int mst(vector<string> &v){
    Graph g(v);   
    return g.MinSpaningTree();
}
int main(){
    int n, Q;
    cin>>n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Q = mst(v);
    cout<<"The highest possible quality is 1/"<<Q<<".";
    return 0;
}