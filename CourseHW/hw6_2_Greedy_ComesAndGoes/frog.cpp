#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
// #include<string.h>
using namespace std;
#define SINKED 0
#define SMALL 1
#define BIG 2

typedef pair<int, int> size_pos; 
// 1 for small, 2 for big

void jump_plan(vector<size_pos> input, vector<int> index_big, int width)
{
    // plan to minimize the distance he jumps each time
    // greedy plan A: choose the smallest every time
    // greedy plan B: if there is big stone, choose the big stone first every time
    // greedy plan C: find the distance of intervals of small stones between two big stone,
    // odd stones within :
    // even stones within:
    // substructure: the interval between two rocks
    // greedy plan D:find the interval of big stone(include the banks) with
        // 1. largest distance and
        // 2. the least number of stones
    // greedy plan E(pass, finally): choose the best step for each step
        //priorty of choice when frog is on index i:
        // 1. look i+1, 
            // if it is big stone, jump
            // if it is small stone, jump the i+2 
            // (no need to consider the boundary for banks are consider big)
        // 2. jump and record the distance(Q: by simply seting a variable or max heap?)


    int max_distance = 0;
    // O(n)
    // jump forth
    for (int i = 0; i < input.size()-1;)
    {
        if (input[i + 1].first == BIG)
        {
            // cout<<"b";
            // cout << max_distance << endl;
            max_distance =
                (max_distance < input[i + 1].second - input[i].second) ? 
                input[i + 1].second - input[i].second : max_distance;
            i++;
        }
        else if (input[i + 1].first == SMALL)
        {
            
            // cout<<"s";
            // cout << max_distance << endl;
            // cout<<input[i + 2].second <<" "<< input[i].second<<endl;
            // cout<<i<<endl;
            max_distance =
                (max_distance < input[i + 2].second - input[i].second) ? 
                input[i + 2].second - input[i].second : max_distance;
            if (input[i + 2].first == SMALL)
                input[i + 2].first = SINKED;
            i += 2;
        }
        
   }
    // jump back
    for (int i = input.size() - 1; i > 0;)
    {
        
        if (input[i - 1].first != SINKED)
        {
            max_distance =
                (max_distance < abs(input[i - 1].second - input[i].second)) ? 
                abs(input[i - 1].second - input[i].second) : max_distance;
            i--;
        }
        else 
        {
            max_distance =
                (max_distance < abs(input[i - 2].second - input[i].second)) ? 
                abs(input[i - 2].second - input[i].second) : max_distance;
            i -= 2;
        }
    }
    // output the maximum distance that needs to be jumped
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
        vector<size_pos> input;
        int temp;
        vector<int> index_big;
        cin >> n >> w;

        input.push_back(size_pos(BIG, 0));
        index_big.push_back(0);
        for (int j = 0; j < n; j++)
        {
            cin >> stone;
            cin >> temp;
            if (stone == 'b')
            {
                input.push_back(size_pos(BIG, temp));
                index_big.push_back(j);
            }
            else if (stone == 's')
            {
                input.push_back(size_pos(SMALL, temp));
            }

        } // for j
        input.push_back(size_pos(BIG, w));
        index_big.push_back(input.size()-1);
        jump_plan(input, index_big, w);

    } // for i
    return 0;
}