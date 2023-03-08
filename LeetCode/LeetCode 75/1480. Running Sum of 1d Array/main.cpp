#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if( nums.size()==1) return nums;

        for (int i = 1; i < nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};

int main(){
    Solution ans;
    vector<int> nums;
    //IO

    //funct
    ans.runningSum(nums);


    return 0;
}