#include <iostream>
#include <map>
#include <string>
using namespace std;

class test
{
private:
    map<int, int> memory;
    int total_memory; // total memory
    int memory_used;  // current used memory

public:
    test(int n)
    {
        total_memory = n;
        memory_used = 0;
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
        memory.erase(a);
        memory.insert(pair<int, int>(a, b));
    }

    // if full, and chapter not exist
    // delete the oldest node and insert new node
    void flush(int a, int b)
    {
        memory.erase(memory.begin());
        memory.insert(pair<int, int>(a, b));
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
        if (memory.find(a) != memory.end())
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
            memory.insert(pair<int, int>(a, b));
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
        map<int, int>::iterator p;
        p = memory.find(a);

        // not exist
        if (p == memory.end())
        {
            cout << -1 << endl;
            return;
        }

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