#include <iostream>

#include <algorithm>
#include <vector>


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

// top recursive function
int quick_select(vector<int> &vec, int target, int start, int end)
{
    if (start - end <= 4)
    {
        return vec.at((start + end) / 2);
    }
    int mid = partition(vec, start, end); // position of pivot: the mid line of index of the interval
    cout<<"pivot: "<<vec[mid]<<endl;
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
    int n;
    cin>>n;
    vector<int> v;
    
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        v.push_back(temp);
    }
    cout << quick_select(v, n / 2, 0, n - 1);
    return 0;
}