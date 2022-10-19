#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool DFS(vector<vector<bool>> &graph, vector<bool> &ambush, int source, int desti)
{
    // notice: how to use DFS in bidirected edge
    int n = graph.size();
    int cur_pos, i_start;
    bool safe=true;
    
    vector<bool> visited_node(n, false);
    stack<pair<bool, pair<int, int>>> s;
    s.push(pair<bool,pair<int,int>>(!ambush[source],pair<int,int>(source,0)));

    while(!s.empty()){
        safe = s.top().first;
        cur_pos=s.top().second.first;
        i_start=s.top().second.second;
        // cout << cur_pos << " " << i_start << endl;
        s.pop();
        if (cur_pos == desti )
            return true;
        for(int i =i_start;i<n;i++){
            if (graph[cur_pos][i] && !visited_node[i] && !ambush[i])
            {

                s.push(pair<bool, pair<int, int>>(safe, pair<int, int>(cur_pos, i)));
                s.push(pair<bool, pair<int, int>>(safe, pair<int, int>(i, 0)));
                
                visited_node[i]=true;
                break;
            }
        }
    }

    return false;
}

int main(){
    int n,m,k,a,b;
    int source, desti;
    cin>>n>>m>>k;
    cin>>source>>desti;
    vector<vector<bool>> graph(n, vector<bool>(n, 0));
    vector<bool> ambush(n,0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b ;
        graph[a-1][b-1] = 1;
    }
    for (int i = 0; i < k; i++)
        cin >> a, ambush[a-1]=1;


   if(DFS(graph,ambush,source-1,desti-1))
       cout << "SAFE";
   else
       cout << "UNSAFE";

    return 0;
}