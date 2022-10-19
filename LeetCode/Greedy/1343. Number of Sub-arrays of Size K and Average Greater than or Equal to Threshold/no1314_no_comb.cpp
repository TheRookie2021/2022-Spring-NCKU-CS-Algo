#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int subset_counter = 0,counter=1;
    int target = threshold * k;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        // cout<<arr[i]<<" "<<sum<<" "<<endl;
        if (counter == k )
        {
            if(sum >= target)
                subset_counter++;
            sum -= arr[i - k+1];
        }else counter++;
    }
    
    
    return subset_counter;
}

int main()
{
    vector<int> arr;
    int n, k, threshold;
    cin >> n >> k >> threshold;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout<<numOfSubarrays(arr,k,threshold);
    return 0;
}