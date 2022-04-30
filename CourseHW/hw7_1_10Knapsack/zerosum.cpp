#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
// find the subset whose sum is closest to the half of the total sum
int max(int a, int b){
    return (a > b) ? a : b;
}
int min_d_to_zero(int arr[],const  int n)
{
    // memo[n+1][n+1]
    // ******* sum=0, 1, 2, 3, ..., total/2
    // index 1
    // index 2
    // index 3
    // index 4
    // index ..
    // index n
    int sum = 0;
    // why we do not need to sort?
    // sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int half = sum / 2;
    int memo[n + 1][half + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < half + 1; j++)
            memo[i][j] = 0;
    // loop: # of items, start from one item //
    for (int i = 1; i < n + 1; i++)
    {
        // loop: weight, start from weight == 1 //
        for (int j = 1; j < half + 1; j++)
        {
            int q;
            // confusing part: why "arr[i - 1] + memo[i - 1][j - arr[i - 1]]"
            if (j >= arr[i - 1]) // targeted weight=j, maybe could take arr[i-1]
                q = max(arr[i - 1] + memo[i - 1][j - arr[i - 1]],// take arr[i-1]: W is the optimal sol for weight at Wx, W-Wi is the optimal one for Wx-Wi
                                     memo[i - 1][j]);            // not take
            else
                q = memo[i - 1][j];

            memo[i][j] = q;
            cout<<q<<" ";
        }
        cout<<endl;
    }
    return abs(sum -2* memo[n][half]);// must minus twice of memo[n][half] because we transfer from 0 to half
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << min_d_to_zero(arr, n);
    return 0;
}