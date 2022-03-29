#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp_concentration(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    if ((a.second == b.second) && (a.first < b.first)) // the condition must be tight
        return true;
    return false;
}
bool cmp_pos(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    if ((a.first == b.first) && (a.second < b.second)) // the condition must be tight
        return true;
    return false;
}
int distance(int target, int b)
{
    return (target - b >= 0) ? target - b : b - target;
}
void choosing_ct(vector<pair<int, int>> cocktails, vector<pair<int, int>> judges)
{
    sort(cocktails.begin(), cocktails.end());
    // brute force
    for (int i = 0; i < judges.size(); i++)
    {
        bool flag=false;
        int lo = 0;
        int hi = cocktails.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (cocktails[mid] == judges[i])
            {
                flag = true;
                break;
            }else if((cocktails[mid].second < judges[i].second)){

            }

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // need this to reduce input output time
    cin.tie(NULL);                    // need this to reduce input output time
    int n, q;
    cin >> n >> q;
    int x, y;
    vector<pair<int, int>> cocktails; //(pos, concentration)
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cocktails.push_back(pair<int, int>(x, y));
    }
    vector<pair<int, int>> judges; //(pos, min concentration)
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        judges.push_back(pair<int, int>(x, y));
    }
    choosing_ct(cocktails, judges);
    return 0;
}