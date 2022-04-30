#include <iostream>
#include <algorithm>
//segmentation fault?
using namespace std;
void MaxGap(unsigned int* arr,unsigned  int num)
{
    unsigned int max = 0;
    sort(arr, arr + num+1);

    for (int i = 0; i < num - 1; i++)
    {
        if (max < arr[i + 1] - arr[i])
        {
            max = arr[i + 1] - arr[i];
        }
    }
    cout<< max;
}

int main()
{
    unsigned int n;
    cin >> n;
    unsigned int* arr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MaxGap(arr,n);
    return 0;
}