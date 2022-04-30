#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool comparepair(pair<int, char> i1, pair<int, char> i2)
{
    if((i1.first > i2.first))
    return true;
    if((i1.first == i2.first)&&(i1.second < i2.second))
    return true;
    return false;
}
void SortChar(string str)
{
    vector<pair<int, char>> freq;
    vector<char> arr;
    int i;
    for (i = 0; i < str.size(); i++)
    {
        arr.push_back(str[i]);
    }
    sort(arr.begin(), arr.end());

    int counter = 1;

    // O(n)
    for (i = 0; i < arr.size() - 1; i++)
    {
        if (arr.at(i) == arr.at(i + 1))
        {
            counter++;
        }
        else
        {
            freq.push_back(pair<int, char>(counter, arr.at(i)));
            counter = 1;
        }
    }
    freq.push_back(pair<int, char>(counter, arr[i]));
    sort(freq.begin(), freq.end(), comparepair);

    for (i = 0; i < freq.size(); i++)
    {
        for (int j = freq[i].first; j > 0; j--)
        {
            cout << freq[i].second;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false); // need this to reduce input output time
    cin.tie(NULL);                    // need this to reduce input output time

    string str;
    cin >> str;
    SortChar(str);
    return 0;
}