#include<iostream>
using namespace std;

void recur_mergesort(int *arr, int *temp, int start, int end)
{
    if(start==end) return;
    int mid=(start+end)/2;

    recur_mergesort(arr, temp, start, mid);
    recur_mergesort(arr, temp, mid + 1, end);
    int left=start, right=mid+1, counter=start;
    while (left <= mid && right <= end){
        if(arr[left]<arr[right]){
            temp[counter]=arr[left];
            left++;
        }else{
            temp[counter] = arr[right];
            right++;
        }
        counter++;
    }

    if(left>mid){
        for (; right <= end; right++, counter++)
        {
            temp[counter] = arr[right];
        }
    }else if(right>end)
    {
        for (; left <= mid; left++, counter++)
        {
            temp[counter] = arr[left];
        }
    }

    for(int i =start;i<=end;i++){
        arr[i]=temp[i];
    }

}

void mergesort(int *arr, int n){
    int temp[n];
    recur_mergesort(arr, temp, 0, n - 1);
}


int main(){
    int arr[10];
    for(int i =0;i<10;i++){
        cin>> arr[i];
    }

    mergesort(arr,10);

    for(int i =0;i<10;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}