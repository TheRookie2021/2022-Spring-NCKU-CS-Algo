#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> Pos;
int top_rk = 0;
int btm_rk = 0;
//0314: cannot use map, because the value of ranking may repeat
// insert the new element and change the ranking (value of map)
void ranking(map<int, Pos> *rank, Pos new_element)
{
    // map: <rank, pos>
    //cmp with top and btm
    //1. place top
    //2. place btm, modify ranking above 
    //3. place between, modify ranking above
    if(rank->begin()==rank->end()){
        rank->insert(pair<int, Pos>(0, new_element));
        return;
    }

    map<int,Pos>::iterator max=rank->find(top_rk);
    map<int,Pos>::iterator min=rank->find(btm_rk);
    
    if ((new_element.first - max->second.first >= 0) && (new_element.second - max->second.first >= 0))
    {
        //1. No two points share the same coordinates.
        //2. either one is larger, place on top
        rank->insert(pair<int, Pos>(++top_rk, new_element));
        return;
    }
    else if((new_element.first - min->second.first < 0) && (new_element.second - min->second.first < 0))
    {
        //either one is smaller than the btm
        rank->insert(pair<int, Pos>(--btm_rk, new_element));       
        return;
    }else{
        //between btn and top
        

    }
    // top_rk++; nope! because the ranking may repeat

}
// print out the rank by its oringnal order
void print_rank(map<int, Pos> rank, vector<Pos> original_pos)
{
    // prepare a map for finding ranking of each (x,y)
    map<Pos, int> temp;
    map<int, Pos>::iterator cpy_itr = rank.begin();
    while (cpy_itr != rank.end())
    {
        temp.insert(pair<Pos, int>(cpy_itr->second, cpy_itr->first));
        cpy_itr++;
    }
    // output in original order
    vector<Pos>::iterator itr;
    for (itr = original_pos.begin(); itr != original_pos.end(); itr++)
    {
        // map: internally sort by key
        // map.find(key)
        cout << temp[*itr] + btm_rk << " ";
    }
}
int main()
{
    int N;
    int x, y;
    map<int, Pos> rk;
    vector<Pos> original_pos;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        original_pos.push_back(Pos(x, y));
        ranking(&rk, Pos(x, y));
    }

    return 0;
}