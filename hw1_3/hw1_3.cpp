#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
// internally, map containers keep all their elements sorted
// by their key following the criterion specified by its comparison object.
//-> can not use map
class test
{
private:
    vector<pair<int, int>> memory;
    
    map<int, int> dic;
    int total_memory; // total memory
    int memory_used;  // current used memory

public:
    test(int n)
    {
        total_memory = n;
        memory_used = 0;
    }
    vector<pair<int, int>>::iterator search(int a)
    {
        vector<pair<int, int>>::iterator itr;
        for (itr = memory.begin(); itr != memory.end(); itr++)
        {
            if (itr->first == a)
                return itr;
        }
        return memory.end();
    }
    // if full, return true;
    bool isFull()
    {
        if (total_memory == memory_used)
            return true;
        else
            return false;
    }
    // if chpater existed
    // update the content of existing chapter
    // put the updated node to the top
    void update(int a, int b)
    {
        memory.erase(search(a));
        memory.push_back(pair<int, int>(a, b));
        
        dic.erase(a);
        dic.insert(pair<int, int>(a, b));
    }

    // if full, and chapter not exist
    // delete the oldest node and insert new node
    void flush(int a, int b)
    {
        dic.erase(memory.begin()->first);
        dic.insert(pair<int, int>(a, b));
        memory.erase(memory.begin());
        memory.push_back(pair<int, int>(a, b));
    }
    // user interface function (1)
    // means that professor teaches chapter  and the content of it is .
    // If there are duplicated chapter, (1.) update its content and (2.) the time of mentioning it.
    void set(int a, int b)
    {
        // conditions:
        // chapter existed-> update
        // chapter not existed
        // if not full->insert
        // else flush oldest

        // exist
        if (search(a) != memory.end())
        {
            update(a, b);
            return;
        }

        // not exist
        if (isFull())
        { // is full
            flush(a, b);
        }
        else
        {
            memory.push_back(pair<int, int>(a, b));
            dic.insert(pair<int, int>(a, b));
            ++memory_used;
        }
    }

    // user interface function (2)
    // means that the pop quiz have chapter a .
    // You need to look for it in the content you memorize.
    // If it exists, you need to update time of mentioning it
    void get(int a)
    {
        // if exist return content, and update the node
        // else retun -1
        

        // not exist
        if (dic.find(a) == dic.end())
        {
            cout << -1 << endl;
            return;
        }
        vector<pair<int, int>>::iterator p;
        p = search(a);
        // exist
        cout << p->second << endl;
        update(p->first, p->second);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a, b;

    string str1, str2;
    cin >> N >> M;

    test t(N);
    for (int i = 0; i < M; i++)
    {
        cin >> str1;
        if (str1.compare("set") == 0)
        {
            cin >> a >> b;
            t.set(a, b);
            continue;
        }
        else if (str1.compare("get") == 0)
        {
            cin >> a;
            t.get(a);
        }
    }
    return 0;
}