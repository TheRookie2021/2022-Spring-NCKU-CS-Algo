#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

typedef struct RKList{
     map<pair<int,int>,int> list;
     map<pair<int,int>,int>::iterator max;
     map<pair<int,int>,int>::iterator min;
};
int main(){
    // map<pair<int,int>,int> pool;
    RKList pool;
    int x, y;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pool.list[{x, y}] = i;
        if(pool.max!=pool.list.end()){
            if(pool.list.find({x, y})->second >pool){
                
            }
        }
        else
        {
            pool.max=pool.list.begin();
        }
    }
    map<pair<int, int>, int>::iterator itr = pool.list.begin();
    cout << "x"
         << " "
         << "y"
         << " "
         << "value" << endl;
    for (; itr != pool.list.end(); itr++)
    {
        cout << itr->first.first << " "
             << itr->first.second << " "
             << itr->second << endl;
    }
    cout<<pool.max->first.first<<endl;
    cout << pool.max->first.first << " "
             << pool.max->first.second << " "
             << pool.max->second << endl;
    return 0;
}