#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// conquer part: return position of pivot in the subproblem
int partition(vector<int> &vec, int start, int end)
{
    // assume the pivot as end,
    // and try to find the position of pivot in the interval.
    int pivot = vec.at(end);

    // parameter that control the comparison prograss, which acts as the mid line of two groups
    int i = start - 1;

    // compare each entry with the pivot from left to right
    for (int j = start; j < end; j++)
    {
        // put values smaller than pivot on the left side of "i"
        if (vec.at(j) < pivot)
        {
            i++;
            swap(&vec.at(i), &vec.at(j));
        }
    }
    // "i" will end at the boundary of smaller group and larger group
    // (we want to find where the pivot should be)
    swap(&vec.at(i + 1), &vec.at(end));
    return i + 1; // the position of pivot
}

// manipulate the pivot choosing
int rand_partition(vector<int> &vec, int start, int end)
{
    srand(time(NULL));
    if ((start - end + 1) == 0)
        return partition(vec, start, end); // RTE bug! be ware of divid with zero

    int i = start + (rand() % (start - end + 1));
    // int i=start;
    swap(&vec.at(i), &vec.at(end));
    return partition(vec, start, end);
}

// top recursive function
int quick_select(vector<int> &vec, int target, int start, int end)
{
    if (start == end)
    {
        return vec.at(start);
    }
    int mid = rand_partition(vec, start, end); // position of pivot: the mid line of index of the interval
    int k = mid - start + 1;                   // k: the index of kth large value of the interval
    if (target == k)
    {
        return vec.at(mid);
    }
    else if (target < k)
    {
        return quick_select(vec, target, start, mid - 1);
    }
    else
    {
        return quick_select(vec, target - k, mid + 1, end); // must minus k, because we are looking at the right side
    }
}

int main()
{
    int n, kth, temp;
    cin >> n >> kth;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec[i] = temp;
    }
    cout << quick_select(vec, n - kth + 1, 0, n - 1);
    return 0;
}