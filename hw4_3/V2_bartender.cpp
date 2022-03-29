#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> Pos_Concen;
bool cmp_concentration(pair<Pos_Concen, int> a, pair<Pos_Concen, int> b)
{
    // sort by concentration
    if (a.first.second < b.first.second)
        return true;
    if ((a.first.second == b.first.second) && (a.first.first < b.first.first)) // the condition must be tight
        return true;
    if ((a.first.second == b.first.second) && (a.first.first == b.first.first) && (a.second > b.second)) // label
        return true;

    return false;
}
int distance(int target, int b)
{
    return (target - b >= 0) ? target - b : b - target;
}
void choosing_ct(vector<pair<Pos_Concen, int>> cocktails_and_judges, vector<Pos_Concen> judges)
{
    sort(cocktails_and_judges.begin(), cocktails_and_judges.end(), cmp_concentration);
    // sort priority: concentration, pos, lable
    for(int i=0;i<cocktails_and_judges.size();i++)
        cout<<cocktails_and_judges[i].first.first<<" "
            <<cocktails_and_judges[i].first.second<<" "
            <<cocktails_and_judges[i].second<<" " <<endl;
            
    for (int i = 0; i < judges.size(); i++)
    {
        int pos_of_j;
        int low = 0, high = cocktails_and_judges.size();
        // bin search the pos of judge in the mix sequence
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (judges[i] == cocktails_and_judges[mid].first)
            {
                pos_of_j = mid;
                break;
            }
            else if (judges[i].second > cocktails_and_judges[mid].first.second)
            {
                low = mid + 1;
            }
            else if ((judges[i].second == cocktails_and_judges[mid].first.second) &&
                     (judges[i].first > cocktails_and_judges[mid].first.first))
            {
                low = mid + 1;
            }
            else if (judges[i].second < cocktails_and_judges[mid].first.second)
            {
                high = mid - 1;
            }
            else if ((judges[i].second == cocktails_and_judges[mid].first.second) &&
                     (judges[i].first < cocktails_and_judges[mid].first.first))
            {
                high = mid - 1;
            }
        } // bin search
        int j = 1;
        bool flag = false;
        while (pos_of_j + j < cocktails_and_judges.size())
        {
            if (cocktails_and_judges[pos_of_j + j].second != 0)
                j++;
            else
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << cocktails_and_judges[pos_of_j + j].first.first << endl;
        else
        {
            j = 1;
            while (pos_of_j - j >= 0)
            {
                if (cocktails_and_judges[pos_of_j - j].second != 0)
                    j++;
                else if (cocktails_and_judges[pos_of_j - j].first.second >= cocktails_and_judges[pos_of_j].first.second)
                {
                    flag = true;
                    break;
                }
                else
                    break;
            }
            if (flag)
                cout << cocktails_and_judges[pos_of_j - j].first.first << endl;
            else
                cout << -1 << endl;
        }
    } // for loop
    // problem: what if judge's pos is largest?
}

int main()
{
    ios_base::sync_with_stdio(false); // need this to reduce input output time
    cin.tie(NULL);                    // need this to reduce input output time
    int n, q;
    cin >> n >> q;
    int x, y;
    vector<pair<Pos_Concen, int>> cocktails_and_judges; //(pos, concentration),labke(0 for cocktail, other for judges)
    vector<pair<int, int>> judges;                      //(pos, min concentration)
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        ;
        cocktails_and_judges.push_back(pair<Pos_Concen, int>(Pos_Concen(x, y), 0));
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        judges.push_back(Pos_Concen(x, y));
        cocktails_and_judges.push_back(pair<Pos_Concen, int>(Pos_Concen(x, y), 1));
    }
    choosing_ct(cocktails_and_judges, judges);

    return 0;
}