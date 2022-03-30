#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <climits>
using namespace std;
bool static cmp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}
vector<int> choosecocktail(vector<vector<int>> &cocktails, vector<vector<int>> &judges)
{
    int i = 0;
    for (auto &q : judges)
        q.push_back(i++);
    vector<int> res(i, -1);
    sort(cocktails.begin(), cocktails.end(), cmp);
    sort(judges.begin(), judges.end(), cmp);
    i = 0;
    set<int> s;
    for (auto &q : judges)
    {
        while (i < cocktails.size() && q[1] <= cocktails[i][1])
        {
            s.insert(cocktails[i][0]);
            i++;
        }
        if (!s.empty())
        {
            auto it = s.lower_bound(q[0]);
            int p1 = INT_MAX, p2 = INT_MAX;
            if (it != s.begin())
                p1 = *prev(it);
            if (it != s.end())
                p2 = *it;
            res[q[2]] = abs(q[0] - p1) <= abs(q[0] - p2) ? p1 : p2;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); // need this to reduce input output time
    cin.tie(NULL);                    // need this to reduce input output time
    int n, q;
    cin >> n >> q;
    int x, y;
    vector<vector<int>> cocktails; //(pos, concentration)
    vector<vector<int>> judges;    //(pos, min concentration)
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        cocktails.push_back(temp);
    }
    for (int i = 0; i < q; i++)
    {
        vector<int> temp;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        judges.push_back(temp);
    }
    ans = choosecocktail(cocktails, judges);
    vector<int>::iterator itr;
    for (itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << endl;
    }
    return 0;
}