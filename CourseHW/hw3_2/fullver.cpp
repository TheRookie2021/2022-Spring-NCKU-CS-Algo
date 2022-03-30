#include <iostream>
using namespace std;
#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *arr, int top)
{
    // mid heap
    // bottom up order
    // heap: 0~MAX-1
    for (int i = top; i > -1; i--)
    {
        for (int j = i; j <= top;)
        {
            if ((j * 2) + 2 <= top) // parent with 2 children
            {
                if ((arr)[j * 2 + 1] < (arr)[j * 2 + 2]) // left child
                {
                    if ((arr)[j] > (arr)[j * 2 + 1])
                    {
                        swap(&(arr)[j], &(arr)[j * 2 + 1]);
                        j = j * 2 + 1;
                    }
                    else
                        break;
                }
                else if ((arr)[j * 2 + 1] >= (arr)[j * 2 + 2]) // right child
                {
                    if ((arr)[j] > (arr)[j * 2 + 2])
                    {
                        swap(&(arr)[j], &(arr)[j * 2 + 2]);
                        j = j * 2 + 2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else if ((j * 2) + 1 <= top) // parent with 1 children
            {
                if ((arr)[j] > (arr)[j * 2 + 1])
                {
                    swap(&(arr)[j], &(arr)[j * 2 + 1]);
                    j = j * 2 + 1;
                }
                else
                    break;
            }
            else // else: leaf nodes, skip.`
                break;
        }

    } // heapify done!
}
void printheap(int *arr, int top)
{
    // passing copy of arr (do not change the value)
    int temp[MAX];
    for (int i = 0; i < MAX; i++)
        temp[i] = arr[i];
    for (int i = top; i > -1;)
    {
        printf("%d ", temp[0]);
        temp[0] = temp[i--];
        // top down heapify
        for (int j = 0; j <= i;)
        {
            if ((j * 2) + 2 <= i) // parent with 2 children
            {
                if (temp[j * 2 + 1] < temp[j * 2 + 2]) // left child
                {
                    if ((temp)[j] > (temp)[j * 2 + 1])
                    {
                        swap(&(temp)[j], &(temp)[j * 2 + 1]);
                        j = j * 2 + 1;
                    }
                    else
                        break;
                }
                else if ((temp)[j * 2 + 1] >= (temp)[j * 2 + 2]) // right child
                {
                    if ((temp)[j] > (temp)[j * 2 + 2])
                    {
                        swap(&(temp)[j], &(temp)[j * 2 + 2]);
                        j = j * 2 + 2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else if ((j * 2) + 1 <= i) // parent with 1 children
            {
                if ((temp)[j] > (temp)[j * 2 + 1])
                {
                    swap(&(temp)[j], &(temp)[j * 2 + 1]);
                    j = j * 2 + 1;
                }
                else
                    break;
            }
            else // else: leaf nodes, skip.`
                break;
        }
    }
}

void heap_sort(int *arr, int top)
{
    heapify(arr, top); // O (n log n)
                       // passing copy of arr (do not change the value)
    int temp[MAX];
    for (int i = 0; i < MAX; i++)
        temp[i] = arr[i];
    for (int i = top, counter = 0; i > -1;)
    {
        arr[counter++] = temp[0];
        temp[0] = temp[i--];
        // top down heapify
        for (int j = 0; j <= i;)
        {
            if ((j * 2) + 2 <= i) // parent with 2 children
            {
                if (temp[j * 2 + 1] < temp[j * 2 + 2]) // left child
                {
                    if ((temp)[j] > (temp)[j * 2 + 1])
                    {
                        swap(&(temp)[j], &(temp)[j * 2 + 1]);
                        j = j * 2 + 1;
                    }
                    else
                        break;
                }
                else if ((temp)[j * 2 + 1] >= (temp)[j * 2 + 2]) // right child
                {
                    if ((temp)[j] > (temp)[j * 2 + 2])
                    {
                        swap(&(temp)[j], &(temp)[j * 2 + 2]);
                        j = j * 2 + 2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else if ((j * 2) + 1 <= i) // parent with 1 children
            {
                if ((temp)[j] > (temp)[j * 2 + 1])
                {
                    swap(&(temp)[j], &(temp)[j * 2 + 1]);
                    j = j * 2 + 1;
                }
                else
                    break;
            }
            else // else: leaf nodes, skip.`
                break;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >>   arr[i] ;
    }
    heapify(arr,N-1);
    
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}
