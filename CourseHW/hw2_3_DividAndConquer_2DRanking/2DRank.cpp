#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> Pos;
int top_rk = 0;
int btm_rk = 0;
void ranking(map<Pos, int>* rank){
    map<Pos, int>::reverse_iterator ritr;
    for (ritr = rank->rbegin(); ritr != rank->rend(); ritr++)
    {
        
        ritr->second=top_rk;

    }

}
void print_rank(map<Pos, int> rank, vector<Pos> original_pos)
{
   // output in original order
    vector<Pos>::iterator itr;
    for (itr = original_pos.begin(); itr != original_pos.end(); itr++)
    {
        cout << rank[*itr] + btm_rk << " ";
    }
}

int main()
{
    int N;
    int x, y;
    map<Pos,int> rk;
    vector<Pos> original_pos;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        original_pos.push_back(Pos(x, y));
        rk.insert(pair<Pos,int>(Pos(x, y),i));
    }


    return 0;
}