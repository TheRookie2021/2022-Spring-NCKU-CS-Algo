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

        while(!q.empty())
        {
            int cur = q.front();
            visited[cur] = true;
            q.pop();

            // bug fix: if the acendent in the spanning tree is modify, we need to update all its decendent
            for (int i = 0; i < V; i++)
            {
                // edge exists
                if ((*adj)[cur][i] != 0)
                {
                    // not visited: push
                    if (!visited[i])
                        q.push(i);
                    
                    // update edge if possible
                    if((ans[i] > ans[cur] + (*adj)[cur][i])){
                        ans[i] = ans[cur] + (*adj)[cur][i];
                        if (visited[i])
                            q.push(i);
                    }
                }

            }
        }
        return ans;
    }
};

int main(){
    int v,e,source;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i =0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b]=w;
        graph[b][a]=w;
    }
    cin>>source;
    Solution ans;
    vector<int> output = ans.dijkstra(v, &graph, source);
    for(auto i: output){
        cout<<i<<" ";
    }
    return 0;
}