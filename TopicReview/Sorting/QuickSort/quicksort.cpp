#include <iostream>
using namespace std;

int find_max(int a, int b)
{
    return (a > b) ? a : b;
}
int find_min(int a, int b)
{
    return (a > b) ? b : a;
}
int medien_of_three(int a, int b, int c)
{
    int max = find_max(find_max(a, b), c);
    int min = find_min(find_min(a, b), c);
    int total = a + b + c;
    return total - min - max;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int start, int end){
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        //put the smaller one on the left
        if(arr[j]<pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;

}
void inplace_quicksort(int *arr, int start,int end)
{//algo: chap 7-1
    if(start<end){
        int medien = partition(arr, start, end);
        inplace_quicksort(arr, start, medien - 1);
        inplace_quicksort(arr, medien + 1, end);
    }
}
void recur_outplace_quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int num = end - start + 1;
        int temp[num];
        int mid = (end + start) / 2;
        int medien = medien_of_three(arr[start], arr[end], arr[mid]);

        int m_ptr = (medien == arr[start]) ? start
                    : (medien == arr[end]) ? end
                                           : mid;
        int l_ptr = 0, r_ptr = num - 1;
        int i = start;
        while (l_ptr < r_ptr)
        {
            if (i == m_ptr)
            {
                i++;
                continue;
            }

            if (arr[i] < medien)
            {
                temp[l_ptr++] = arr[i++];
            }
            else
            {
                temp[r_ptr--] = arr[i++];
            }
        }
        temp[r_ptr] = medien;

        for (int i = 0; i < num; i++)
        {
            arr[start + i] = temp[i];
            cout << arr[start + i] << " ";
        }
        cout << endl;
        // cout<<"who";
        recur_outplace_quicksort(arr, start, start + r_ptr - 1);
        recur_outplace_quicksort(arr, start + r_ptr + 1, end);
    }
    // debug: notice that you are using two arr with two uncooresponding index,
    // so make sure which index you are using for recursive or any loop condition
    // and correct the difference between the two.
}
void outplace_quicksort(int *arr, int num)
{
    if (num == 0)
        return;
    recur_outplace_quicksort(arr, 0, num - 1);
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

    // for (int i = 0; i < x; i++)
    // {
    //     cout<<  arr[i]<<" ";
    // }
    // cout<<endl;
    // outplace_quicksort(arr, x);
    inplace_quicksort(arr,0, x-1);
    
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}