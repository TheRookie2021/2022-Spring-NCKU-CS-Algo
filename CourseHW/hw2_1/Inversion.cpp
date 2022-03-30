#include <iostream>
using namespace std;

int main()
{
    int N;
    int temp;
    unsigned int counter = 0;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    //O(N*N): TLE
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                ++counter;
            }
        }
    }
    cout << counter << endl;

    return 0;
}