#include<iostream>
#define RANGE 100000
using namespace std;
// assumption: all entries are int, and the range of those are known
void counting_sort(int arr[],int n){
    int counter[RANGE];
    for (int i = 0; i < RANGE; i++)
        counter[i] = 0;
    for (int i = 0; i < n; i++)
        counter[arr[i]]++;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i ; j < n- 1; j++)
        {
            if (arr[i] > arr[j+1])
            {
                sum += counter[arr[j]];
            }
        }
        cout << sum << " ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int min=0;
    for(int i =0;i<n;i++){
        cin>>arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    if(min<0)
    for(int i =0;i<n;i++){
        arr[i] += min;
    }

    counting_sort(arr, n);
    return 0;
}