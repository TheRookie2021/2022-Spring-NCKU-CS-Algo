#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
    srand(time(NULL));
    int n = 100, m = 10, k = 3;
    cout << n << " ";
    cout << m << " ";
    cout << k << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << rand() % n << " ";

    return 0;
}