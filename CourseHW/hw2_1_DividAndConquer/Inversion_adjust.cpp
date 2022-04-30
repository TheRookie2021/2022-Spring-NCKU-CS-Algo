#include <iostream>
#include <algorithm>
using namespace std;

void conquer(long int *arr, long int front, long int mid, long int end, unsigned long int *counter)
{
    if (front == end)
        return;
    int ptr = front;
    int len = mid - front + 1;

    // start from end half
    for (int i = mid + 1; i < end + 1; i++)
    {
        if (len == 0)
            break;
        // ptr point to the smallest in the front half
        while (1)
        {
            if (len == 0)
                break;

            // front value > end value: counter +len
            if (arr[ptr] > arr[i])
            {
                (*counter) += len;
                break;
            }
            // front value < end value: len--, ptr++
            else
            {
                ptr++;
                len--;
            }
        }
    }
    // sort
    sort(&arr[front], &arr[end + 1]);
}
void divid(long int *arr, long int front, long int end, unsigned long int *counter)
{
    if (front == end)
        return;

    divid(arr, front, (front + end) / 2, counter);
    divid(arr, 1 + (front + end) / 2, end, counter);
    conquer(arr, front, (front + end) / 2, end, counter);
}

int main()
{
    unsigned long int N;
    long int temp;
    unsigned long int counter = 0;
    cin >> N;
    long int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    divid(arr, 0, N - 1, &counter);
    cout << counter % 524287;

    return 0;
}