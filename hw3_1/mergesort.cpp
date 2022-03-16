#include<iostream>
using namespace std;

//be aware of the index, check every for loop index!

void rmerge_sort(int *arr, int left_index, int right_index)
{
    if (left_index >= right_index)
        return;
   
    int mid_index = (right_index + left_index) / 2;
    rmerge_sort(arr, left_index, mid_index);
    rmerge_sort(arr, mid_index + 1, right_index);
    // mergeing(arr, left_index, mid_index, right_index);
    int L_i = left_index, R_i = mid_index + 1;
    int temp[right_index-left_index+1];
    int counter=0;
    for (int i = 0; i < right_index - left_index + 1; i++)
    {
        temp[i]=0;
    }
    while (L_i < mid_index + 1 && R_i < right_index + 1)
    {
        
        if (arr[L_i] < arr[R_i])
        {
            temp[counter] = arr[L_i];
            L_i++;
        }
        else
        {
            temp[counter] = arr[R_i];
            R_i++;
        }
        counter++;
    }
  
    while(L_i < mid_index + 1){
        temp[counter++] = arr[L_i];
        L_i++;
    }
    while (R_i < right_index + 1)
    {
        temp[counter++] = arr[R_i];
        R_i++;
    }
    for (int i = 0, j = left_index; i < counter ; i++, j++)
    {
        
        arr[j] = temp[i];
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
   
    rmerge_sort(arr,0,N-1);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}