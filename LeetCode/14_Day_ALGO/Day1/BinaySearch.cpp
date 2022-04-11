#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1; // bug: don't forget to minus 1 for indexing

        while (left <= right)// bug: must be <=, think about the case with one element
        {
            int mid = (right + left) / 2;
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    int x, t;
    cin >> x;
    vector<int> nums;
    for (int i = 0; i < x; i++)
    {
        cin >> t;
        nums.push_back(t);
    }
  
    cin >> t;
    cout<<s.search(nums, t);
    return 0;
}