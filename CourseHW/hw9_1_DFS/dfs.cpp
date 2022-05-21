#include <iostream>
#include <stack>
using namespace std;
#define U 1
#define R 2
#define D 3
#define L 4
typedef int LastDirection;

int main()
{
    int n, m, s1, s2, t1, t2;
    cin >> n >> m >> s1 >> s2 >> t1 >> t2;
    int maze[n + 2][m + 2];
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                maze[i][j] = 0;
            else
                cin >> maze[i][j];

    pair<int, int> cur_pos = pair<int, int>(s1, s2);
    pair<int, int> terminal = pair<int, int>(t1, t2);
    stack<pair<LastDirection, pair<int, int>>> s;
    // for (int i = 0; i <= n + 1; i++){
    //     for (int j = 0; j <= m + 1; j++)
    //             cout<< maze[i][j]<<" ";
    //     cout<<endl;
    // }
    LastDirection dir;
    bool flag = false;
    s.push(pair<LastDirection, pair<int, int>>(0, cur_pos));
    while (!s.empty())
    {
        dir = s.top().first;
        cur_pos = s.top().second;
        maze[cur_pos.first][cur_pos.second]=0;
        s.pop();
        
        if (cur_pos == terminal)
        {
            flag = true;
            break;
        }
        // next step
        dir++;
        s.push(pair<LastDirection, pair<int, int>>(dir, cur_pos));

        // cout<<dir<<" "<<cur_pos.first<<" "<<cur_pos.second<<" step: "<<step<<endl;
        if (dir <= 4)
        {
            // still some dir to be explored
            switch (dir)
            {
            case U:
                cur_pos = pair<int, int>(cur_pos.first - 1, cur_pos.second);
                break;
            case R:
                cur_pos = pair<int, int>(cur_pos.first, cur_pos.second + 1);
                break;
            case D:
                cur_pos = pair<int, int>(cur_pos.first + 1, cur_pos.second);
                break;
            case L:
                cur_pos = pair<int, int>(cur_pos.first, cur_pos.second - 1);
                break;
            default:
                break;
            }
            if (maze[cur_pos.first][cur_pos.second] == 1)
            {
                // can go
                s.push(pair<LastDirection, pair<int, int>>(0, cur_pos));
            }
        }else{
            if(!s.empty())
                s.pop();
        }

    } // while
    // cout<<step<<endl;
    if (flag)
        cout << "Success!";
    else
        cout << "Fail!";
    return 0;
}