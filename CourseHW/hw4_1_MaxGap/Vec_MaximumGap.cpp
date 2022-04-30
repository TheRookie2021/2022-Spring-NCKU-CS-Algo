#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void MaxGap(vector<int> arr)
{
    int max = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (max < arr[i + 1] - arr[i])
        {
            max = arr[i + 1] - arr[i];
        }
    }
    cout<< max;
}

int main()
{
    
    ios_base::sync_with_stdio(false);//need this to reduce input output time 
    cin.tie(NULL);//need this to reduce input output time 

    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    MaxGap(arr);
    return 0;
}