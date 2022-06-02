#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
    srand(time(NULL));
    int x = 10;
    cout << x << endl;
    for (int i = 0; i < x; i++)
    {
        cout << rand() % 100-50 << " ";
    }

    return 0;
}