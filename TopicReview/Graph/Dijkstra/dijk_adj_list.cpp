#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> ans(V,INT_MAX);
        vector <bool> visited(V,false);
        
        queue<int> q;
        q.push(S);
        ans[S]=0;

        // bug fix: if the acendent in the spanning tree is modify, we need to update all its decendent
        while(!q.empty())
        {
            int cur = q.front();
            visited[cur] = true;
            q.pop();
            // cout<<"cur: "<<cur<< " dis: "<<ans[cur]<<"\n";
            // cout<<"ans38: "<<ans[38]<<endl;
            for (int i = 0; i < adj[cur].size(); i++)
            {
                int next_node = adj[cur][i][0];
                int next_weight = adj[cur][i][1];

                // cout << "neighbor: " << next_node << " weight: "<< next_weight<<endl;
                // not visited: push
                if (!visited[next_node])
                    q.push(next_node);

                // update edge if possible
                if((ans[next_node] > ans[cur] + next_weight)){
                    ans[next_node] = ans[cur] + next_weight;
                    if(visited[next_node])
                        q.push(next_node); // we need to update the decendent of node that has been visited, so push into queue again
                }
            }
        }
        return ans;
    }
};

int main(){
    int v,e,source;
    cin>>v>>e;
    vector<vector<int>> graph[v];
    for(int i =0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        
        vector<int> v1,v2;
        v1.push_back(b);
        v1.push_back(w);
        v2.push_back(a);
        v2.push_back(w);
        
        graph[a].push_back(v1);        
        graph[b].push_back(v2);
    }
    cin>>source;
    Solution ans;
    vector<int> output = ans.dijkstra(v, graph, source);
    for(auto i: output){
        cout<<i<<" ";
    }
    return 0;
}