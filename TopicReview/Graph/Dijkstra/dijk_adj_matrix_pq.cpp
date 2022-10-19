#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#define node pair<int, int>

using namespace std;


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> ans(V,INT_MAX);

        priority_queue<node, vector<node>, greater<node>> pq;
        pq.push(node(0, S));
        ans[S]=0;
        for (int i = 0; i < V; i++)
        {
            if ((*adj)[S][i] != 0)
            {
                pq.push(node((*adj)[S][i], i));
            }else{
                pq.push(node(INT_MAX, i));
            }
        }

        while (!pq.empty())
        {
            // got stuck: how to update the ans and update the queue at the same time
            // previous method: don't care, whenever we update a node, push it into the queue
                // (since the graph has no negative weight, it promise that each time we update,
                //  we will only get the shortest version of that node)
            // correct_previous: i accidentally took queue as priority queue, so wrongggggg!
            node cur=pq.top();
            pq.pop();
            
            // visit_counter++;// cannot use counter to bound the while loop since i didn't eraser previos push of a node once it is update
            // how to update pq? STL dose not supply update or erase function
            // Ahh! what if we empty the queue every iteration? than there will be no redundent node
            // no it doesn't work, what if in some iteration, there is no new node to be updated?

            // Relax part
            for (int i = 0; i < V; i++)
            {
                // if there is an edge connected with cur which is not yet visited
                if ((*adj)[cur.second][i] != 0)
                {
                    if ((ans[i] > ans[cur.second] + (*adj)[cur.second][i]))
                    {
                        ans[i] = ans[cur.second] + (*adj)[cur.second][i];
                        pq.push(node(ans[i], i));
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