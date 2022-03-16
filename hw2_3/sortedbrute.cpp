#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;
typedef pair<long long signed int, long long signed int> Pos;
void print_rank(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void ranking(vector<Pos> rank,int *arr){
    vector<Pos>::iterator itr,jtr;
    int i = 0, j = 0;
    for (itr = rank.begin(); itr != rank.end(); itr++, i++)
    {
        for (jtr = itr+1, j = i + 1; jtr != rank.end(); jtr++, j++)
        {
            long long signed int x,y;
            x=itr->first-jtr->first;
            y=itr->second-jtr->second;
            
            if (x >= 0 && y >= 0){
                arr[i]++;
            }
            else if (x <= 0 && y <= 0)
            {
                arr[j]++;
            }
        }
    }

    print_rank(arr,rank.size());
}

int main()
{
    int N;
    long long signed int x, y;
    vector<Pos> rk;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        rk.push_back(Pos(x, y));
        arr[i]=0;
    }
    ranking(rk,arr);

    return 0;
}