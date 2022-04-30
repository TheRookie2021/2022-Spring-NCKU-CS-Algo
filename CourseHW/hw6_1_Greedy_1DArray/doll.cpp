#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <map>
using namespace std;
void group_dolls(list<int> size_set)
{

    size_set.sort();
    list<int>::iterator itr = size_set.begin();
    int temp = *itr;
    cout << temp << " ";
    itr = size_set.erase(itr);

    while (!size_set.empty())
    {
        if (itr == size_set.end())
        {
            cout << endl;
            itr = size_set.begin();
            temp = *itr;
            cout << temp << " ";
            itr = size_set.erase(itr);
        }
        else
        {
            if (*itr > temp)
            {
                temp = *itr;
                cout << temp << " ";
                itr = size_set.erase(itr);
            }
            else
            { // if: *itr==temp
                itr++;
            }
        }
    }
}
int main()
{
    // constrains: minimize num of grounps
    // rules: Can only accommodate smaller dolls
    int n;
    cin >> n;
    list<int> size_set;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        size_set.push_back(temp);
    }
    group_dolls(size_set);

    return 0;
}