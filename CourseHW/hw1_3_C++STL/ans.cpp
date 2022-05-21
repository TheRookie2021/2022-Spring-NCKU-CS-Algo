#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
typedef pair<int, int> Chap_Cont;

int main()
{
    int n, m, a, b;
    string str;
    list<Chap_Cont> memory;
    unordered_map<int, list<Chap_Cont>::iterator> mp;
    cin >> n >> m;
    while (cin >> str >> a) {
        if (str == "get") {
            if (mp.find(a) != mp.end()) {
                cout << (*mp[a]).second << endl;
                memory.erase(mp[a]);
                memory.push_front(Chap_Cont( a, (*mp[a]).second ));
                mp[a] = memory.begin();
            } else
                cout << -1 << endl;
        } else {
            cin >> b;
            if (mp.find(a) != mp.end())
                memory.erase(mp[a]);
            memory.push_front(Chap_Cont(a, b)), mp[a] = memory.begin();
            if (memory.size() > n)
                mp.erase(memory.back().first), memory.pop_back();
        }
    }
}