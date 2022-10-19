#include <iostream>
#include <algorithm>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int *arr, int i, int top)
{
    // i: parent, L: left child, R: right child
    int L = i * 2 + 1, R = i * 2 + 2;
    int max; // index of max value of the parent and childs

    // if lchild exist, and if lchild is smaller than max
    if (L <= top && arr[L] > arr[i])
    {
        max = L;
    }
    else
    {
        max = i;
    }
    // if rchild exist, and if rchild is smaller than max
    if (R <= top && arr[R] > arr[max])
    {
        max = R;
    }
    // if max is not the parent, swap the values and continue recursion(top-down)
    if (max != i)
    {
        swap(&(arr[max]), &(arr[i]));
        max_heapify(arr, max, top);
    }
}

void build_heapify(int *arr, int top)
{
    // bottom-up checking the child
    for (int i = top / 2; i > -1; i--)
    {
        max_heapify(arr, i, top);
    }
}

void heap_sort(int *arr, int top)
{
    // passing copy of arr (do not change the value)
    int temp[top];
    int counter = top;
    for (int i = 0; i < top + 1; i++)
    {
        temp[i] = arr[0];
        arr[0] = arr[counter--];
        max_heapify(arr,0, counter);
    }
    for (int i = 0; i < top + 1; i++)
        arr[i] = temp[i];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    build_heapify(arr, N - 1);

    for (int i = 0; i < N; i++)
    {

        cout << arr[i] << " ";
    }
    heap_sort(arr,N-1);
    // sort(arr,arr+N,greater<>());
    cout << endl;
    for (int i = N - 1; i > -1; i--)
    {

        cout << arr[i] << " ";
    }

    return 0;
}
