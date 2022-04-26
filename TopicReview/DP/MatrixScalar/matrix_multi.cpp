#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void print_matrix(vector<vector<int>> m)
{
    int n = m.size();

    cout << "\t";
    for (int i = 1; i < n; i++)
        cout << "[" << i << "]\t";
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        cout << "[" << i << "] \t";
        for (int j = 1; j < n; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void min_scalar_multiplication(int n, vector<int> &p)
{

    vector<vector<int>> memo(n + 1, vector<int>(n + 1)), s_memo(n + 1, vector<int>(n + 1));
    // initialize
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            memo[i][j] = 0;
            s_memo[i][j] = 0;
        }
    }
    // iterative calculation(bottom up)
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            memo[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = memo[i][k] + memo[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < memo[i][j])
                {
                    memo[i][j] = q;
                    s_memo[i][j] = k;
                }
            }
        }
    }
    // output
    print_matrix(memo);
    cout << endl;
    print_matrix(s_memo);
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> p;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    min_scalar_multiplication(n, p);
    return 0;
}