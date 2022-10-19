#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void comb(vector<int> &arr, int k, int target,int &subset_counter,int start, int cur_counter, int sum){
    if(cur_counter==k){
        if(sum>=target){
            subset_counter++;
            // cout<<endl<<"s counter: "<<subset_counter<<" sum: "<<sum;
        }
        // cout<<endl;
        return;
    }
    for(int i =start;i<arr.size();i++){
        // cout<<arr[i]<<" ";
        comb(arr, k, target, subset_counter, i + 1, cur_counter + 1, sum + arr[i]);
    }

}

    int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int subset_counter = 0;
    int target = threshold * k;
    
    comb(arr, k, target, subset_counter, 0, 0, 0);
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