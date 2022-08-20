#include <iostream>
#include <vector>
#include <algorithm>
// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task.
// In each round, you can complete either 2 or 3 tasks of the same difficulty level.
// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

// special case: 2222,
//  valid: 22 22
//  invalid: 2 222, 222 2
using namespace std;
class Solution
{
public:
    int min(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int minimumRounds(vector<int> &tasks)
    {
        sort(tasks.begin(), tasks.end());
        vector<int> memo(tasks.size(), 0);
        memo[0] = 0;
        if (tasks[1] != tasks[0])
            return -1;
        else memo[1]=1;

        for (int i = 2; i < tasks.size(); i++)
        {
            // i-1 not same
            if (tasks[i - 1] != tasks[i])
            {
                memo[i] = -1;
            }
            else//i-1 same
            {
                if (i - 2 > -1)// boundary detection
                {
                    // i-2 not same
                    if (tasks[i - 2] != tasks[i])
                    {
                        memo[i] = memo[i - 2] + 1;
                    }
                    else// i-2 same
                    {
                        if (i - 3 > -1)// boundary detection
                        {
                            // i-3 not same
                            if (tasks[i - 3] != tasks[i])
                            {
                                memo[i] = memo[i - 2] + 1;
                            }
                            else // i-3 same
                            {
                                if (i - 4 > -1)// boundary detection
                                {
                                    if (memo[i - 4] == 0) // if memo[0]
                                        memo[i] = memo[i - 4] + 2;
                                    else if (memo[i - 4] == -1)
                                        memo[i] = memo[i - 4] + 1;
                                    else
                                        memo[i] = memo[i - 3] + 1;
                                }
                                else // out of bound
                                    memo[i] = memo[i - 3] + 1;
                            }
                        }
                        else// out of bound
                        {
                            memo[i] = memo[i - 2] + 1;
                        }
                    }
                }
                else// out of bound
                {
                    memo[i] = memo[i - 1] + 1;
                }
            }
        }
        return memo[tasks.size()-1];
    }

};
int main()
{
    int n;
    cin >> n;
    vector<int> task(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }
    Solution sol;
    cout << sol.minimumRounds(task);
    return 0;
}