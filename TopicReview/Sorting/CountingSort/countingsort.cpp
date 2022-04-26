#include <iostream>
#define RANGE 100
using namespace std;

// assumption: all entries are int, and the range of those are known
void counting_sort(int arr[],int n){
    int counter[RANGE], arr_counter=0;
    for (int i = 0; i < RANGE; i++)
        counter[i] = 0;
    for (int i = 0; i < n; i++)
        counter[arr[i]]++;
    for (int i = 0; i < RANGE; i++)
        if (counter[i] > 0)
        {
            for (int j = 0; j < counter[i]; j++)
                arr[arr_counter++]=i;
        }
}


int main()
{
    int x;
    cin >> x;
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }
    counting_sort(arr, x);

        for (int i = 0; i < x; i++)
        {
            cout << arr[i] << " ";
        }

    return 0;
}