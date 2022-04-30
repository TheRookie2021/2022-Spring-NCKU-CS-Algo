#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp_concentration(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second < b.second)
        return true;
    if ((a.second == b.second)&&(a.first < b.first))//the condition must be tight 
        return true;
    return false;

}
int distance(int target, int b){
    return (target - b >= 0) ? target - b : b - target;
}
void choosing_ct(vector<pair<int, int>> cocktails, vector<pair<int, int>> judges)
{
    sort(cocktails.begin(), cocktails.end(),cmp_concentration);
    //brute force
    for(int i=0;i<judges.size();i++)
    {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > *position_of_valid_concentration= new priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >;
        //cocktail sorted by concentration: find the lower bound
        for (int j = 0; j < cocktails.size(); j++)
        {
            if(cocktails[j].second>= judges[i].second){
                position_of_valid_concentration->push(pair<int,int>(distance(judges[i].first,cocktails[j].first),cocktails[j].first));//push pos into min heap
            }
            
        }
        //then find the closest
        if(position_of_valid_concentration->empty())
            cout<<-1;
        else{
            cout << position_of_valid_concentration->top().second;
        }
        cout<< endl;
        delete position_of_valid_concentration;
    }


}


int main()
{
    ios_base::sync_with_stdio(false);//need this to reduce input output time
    cin.tie(NULL);                   // need this to reduce input output time
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
    choosing_ct(cocktails,judges);
    return 0;
}