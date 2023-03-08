#include<iostream>
#include<vector>
using namespace std;
// ideas: 
// left and right pointers toward middle
// 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, leftsum=0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        for (int i = 0; i < nums.size(); i++)
        {
            if ((sum - nums[i]) % 2 == 0 &&
                (sum - nums[i]) / 2 == leftsum)
            {
                // assume nums[i] as pivot
                // if it is, we done
                // if it isn't, keep going
                return i;
            }
            else
            {
                leftsum += nums[i];
            }
        }
        return -1;
    }
};

int main(){
    Solution ans;
    vector<int>nums;
 
    ans.pivotIndex(nums);
    return 0;
}