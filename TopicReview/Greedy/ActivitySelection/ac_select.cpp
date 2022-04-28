#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> TIME;

// assumption for greedy choice: activities are sorted by finish time-> choose the earlise finish time for each step

bool cmp(TIME a, TIME b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second && a.first < b.first)
        return true;
    else
        return false;
}
vector<TIME> max_num_activity_select(vector<TIME> activity)
{
    vector<TIME> output;
    int f;
    sort(activity.begin(), activity.end(),cmp);
    output.push_back(activity[0]);
    f = activity[0].second;
    cout<<0<<" ";
    for (int i = 1; i < activity.size(); i++)
    {
        if (f < activity[i].first)
        {
            output.push_back(activity[i]);
            f = activity[i].second;
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return output;
}

int main()
{
    vector<TIME> activity;
    vector<TIME> ans;
    int n, s, f;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> f;
        activity.push_back(TIME(s, f));
    }
    ans=max_num_activity_select(activity);
    for (auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}