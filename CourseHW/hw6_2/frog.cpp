#include <iostream>
#include <list>
#include <cmath>
// #include<string.h>
using namespace std;
typedef pair<int, int> size_pos; // 1 for small, 2 for big

void jump_plan(list<size_pos> input, int num_big, int width)
{
    // plan to minimize the distance he jumps each time
    // greedy plan A: choose the smallest every time
    // greedy plan B: if there is big stone, choose the big stone first every time

    // output the maximum distance that needs to be jumped
    int max_distance=0;
    // int min_step;
    list<size_pos>::iterator itr;
    for (itr = input.begin(); itr != input.end(); )
    {
        if (itr->first == 2)
        {
            // big stone
            if (max_distance < width - itr->second)
            {
                max_distance = width - itr->second;
            }
            itr++;
        }
        else if (itr->first == 1)
        {
            // small stone
            if (max_distance < width - itr->second)
            {
                max_distance = width - itr->second;
            }
            itr = input.erase(itr);
        }
    } // for i
    list<size_pos>::reverse_iterator ritr;
    if (input.empty())
        max_distance = width;
    else
    {
        for (ritr = input.rbegin(); ritr != input.rend(); ritr++)
        {
            if (ritr->first == 2)
            {
                // big stone
                if (max_distance < width - ritr->second)
                {
                    max_distance = width - ritr->second;
                }
            }
            else if (ritr->first == 1)
            {
                // small stone
                if (max_distance < width - ritr->second)
                {
                    max_distance = width - ritr->second;
                }
                // ritr=input.erase(ritr);
            }
        } // for i
    }

    cout << max_distance << endl;
}
int main()
{
    int t;
    int n, w;
    char stone;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        list<size_pos> input;
        int temp;
        int num_big = 0;
        cin >> n >> w;
        for (int j = 0; j < n; j++)
        {

            cin >> stone;
            cin >> temp;
            if (stone == 'b')
            {
                input.push_back(size_pos(2, temp));
                num_big++;
            }
            else if (stone == 's')
            {
                input.push_back(size_pos(1, temp));
            }
        } // for j
        jump_plan(input, num_big, w);

    } // for i
    return 0;
}