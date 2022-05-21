#include <iostream>
#include <queue>
using namespace std;
#define U 1
#define R 2
#define D 3
#define L 4
typedef int StepCount;
bool maze[1005][1005];

int main()
{
    int n, m, s1, s2, t1, t2;
    cin >> n >> m >> s1 >> s2 >> t1 >> t2;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                maze[i][j] = 0;
            else
                cin >> maze[i][j];

    pair<int, int> cur_pos = pair<int, int>(s1, s2);
    pair<int, int> terminal = pair<int, int>(t1, t2);
    // for (int i = 0; i <= n + 1; i++){
    //     for (int j = 0; j <= m + 1; j++)
    //             cout<< maze[i][j]<<" ";
    //     cout<<endl;
    // }
    bool flag = false;
    StepCount step = 0;
    pair<int, int> temp;
    queue<pair<StepCount, pair<int, int>>> q;

    q.push(pair<StepCount, pair<int, int>>(step, cur_pos));
    while (!q.empty())
    {
        step = q.front().first;
        cur_pos = q.front().second;
        maze[cur_pos.first][cur_pos.second] = 0; // mark
        if (cur_pos == terminal )
        {
            flag = true;
            break;
        }
        else if (!q.empty())
            q.pop();
        else break;

        // push all posible way in terms of the cur position
        for (int dir = 1; dir <= 4; dir++)
        {
            // if all 0, no push occurs
            temp = cur_pos;

            switch (dir)
            {
            case U:
                temp = pair<int, int>(cur_pos.first - 1, cur_pos.second);
                break;
            case R:
                temp = pair<int, int>(cur_pos.first, cur_pos.second + 1);
                break;
            case D:
                temp = pair<int, int>(cur_pos.first + 1, cur_pos.second);
                break;
            case L:
                temp = pair<int, int>(cur_pos.first, cur_pos.second - 1);
                break;
            default:
                break;
            }
            
            // can go: push
            if (maze[temp.first][temp.second] == 1)
            {
                q.push(pair<StepCount, pair<int, int>>(step + 1, temp));
//!!!!!!!!!!!!!!!!!!!!!!!!! we must mark the step here, or it may cause runtime error(infinit loop)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                maze[temp.first][temp.second] = 0; 
            }
        } // for( push all dir )

        cout<<cur_pos.first<<" "<<cur_pos.second<<" step: "<<step<<endl;
        
    } // while queue not empty

    if (flag)
        cout << step;
    else
        cout << -1;
    return 0;
}