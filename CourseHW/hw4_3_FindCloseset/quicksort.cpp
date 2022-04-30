
int median_of_tree(int a, int b, int c)
{
    if ((a <= b && a >= c) || (a <= c && a >= b))
    {
        return a;
    }
    if ((b <= a && b >= c) || (b <= c && b >= a))
    {
        return b;
    }
    if ((c <= a && c >= b) || (c <= b && c >= a))
    {
        return c;
    }
}

void quick_sort(int *arr, int left_index, int right_index)
{
    // method1. use two arr
    // method2. in place partitioning (only original arr)
    // select pivot: median of three
    if (left_index < right_index)
    {
        // use two arr
        int temp[MAX];
        // median-of-tree
        int pivot;
        int mid;
        if ((left_index + right_index) % 2 == 0)
        {
            pivot = median_of_tree((arr)[left_index], (arr)[(left_index + right_index) / 2], (arr)[right_index]);
            mid = (left_index + right_index) / 2;
        }
        else
        {
            pivot = median_of_tree((arr)[left_index], (arr)[(left_index + right_index) / 2 + 1], (arr)[right_index]);
            mid = (left_index + right_index) / 2 + 1;
        }
        int pivot_ind;
        int L, R;
        L = left_index;
        R = right_index;
        if (pivot == (arr)[left_index])
        {
            pivot_ind = left_index;
        }
        else if (pivot == (arr)[mid])
        {
            pivot_ind = mid;
        }
        else if (pivot == (arr)[right_index])
        {
            pivot_ind = right_index;
        }

        int i = L;
        // start sorting
        do
        {
            if (pivot < (arr)[i])
            {
                temp[R--] = (arr)[i];
            }
            else if (pivot >= (arr)[i] && pivot_ind != i)
            {
                temp[L++] = (arr)[i];
            }
            i++;

            // will stop when L==R, where is the place for pivot
        } while (L < R);

        temp[R] = pivot;

        for (i = left_index; i < right_index + 1; i++)
        {
            (arr)[i] = temp[i];
        }

        quick_sort(arr, left_index, R - 1);
        quick_sort(arr, R + 1, right_index);
    }
    // debug note: when processing dynamicly moving index, be aware of the boundry setting in each variable
    //(expecialy looping variable)
}