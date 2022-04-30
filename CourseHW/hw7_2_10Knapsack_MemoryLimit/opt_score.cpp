#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// to get the max scores during the time
// bug: the memory is massive when the deadline is large number: 5*10^4
typedef pair<int, int> PT_MIN;

int max_score(vector<PT_MIN> assignment, int deadline)
{
    /////////////////////////////////////////////////////
    //  memo[size][weight]
    //      W=0, 1, 2, ..., w
    // i=0
    // i=1
    // i=2
    // i=...
    /////////////////////////////////////////////////////
    int size=assignment.size();
    vector<vector<int>> memo(2,vector<int>(deadline+1,0));// to fill in the opt value
    
    // bottom-up: Opt(W(i+1))=Opt(max(W(i+1-w[i])+V(i+1),W(i)))
    for(int i =1;i<size+1;i++){
        for(int j=1;j<deadline+1;j++)
        {
            if (j >= assignment[i - 1].second)
                memo[1][j] = max(assignment[i - 1].first + memo[0][j - assignment[i - 1].second ], memo[0][j]);
            else
                memo[1][j]=memo[0][j];
        }
        for(int j=1;j<deadline+1;j++)
            memo[0][j] = memo[1][j];
    }
    return memo[1][deadline];
}

int main()
{
    vector<PT_MIN> assignment;
    vector<PT_MIN> ans;
    int n,deadline, pt, min;
    cin>>n>>deadline;
    // should we convert minute to hours ?
    for (int i = 0; i < n; i++)
    {
        cin >> pt >> min;
        assignment.push_back(PT_MIN(pt, min));
    }

    cout << max_score(assignment, deadline);
    return 0;
}