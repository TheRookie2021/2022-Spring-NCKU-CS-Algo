ANS: https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);       
        return *max_element(begin(dp), end(dp));
    }
};
Q:  why it works?
A:  every time we expend the size of subarray by 1, we looks the former, and choose the optimal
Q: why is dp optimal?
A: dp[i] record the optimal maximum subarray decides whether to take the dp[i-1]
Note: this is not fixed size, two pointer is not suggested.

# similar topic:
    2Sum, 3Sum, 4Sum

    - 2sum
``` c++
// 1. sort
// 2. two ptrs
// 3. find original index
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans(2);
            vector<int> temp=nums;
            sort(temp.begin(),temp.end());
            ans[0]=0,ans[1]=temp.size()-1;
            while(ans[0]<ans[1]){
                if(temp[ans[0]]+temp[ans[1]]== target)break;
                else if(temp[ans[0]]+temp[ans[1]]>target){
                    ans[1]--;
                }else if(temp[ans[0]]+temp[ans[1]]<target){
                    ans[0]++;
                } 
            }
            // find index of original arr
            for(int i=0;i<nums.size();i++){
                if(nums[i]==temp[ans[0]]){
                    ans[0]=i;break;
                }
            }
            
            for(int i=nums.size()-1;i>-1;i--){
                if(nums[i]==temp[ans[1]]) {
                    ans[1]=i;
                    break;
                }
            }
            return ans;
        }
};
Runtime: 18 ms, faster than 84.62% of C++ online submissions for Two Sum.
Memory Usage: 10.5 MB, less than 54.88% of C++ online submissions for Two Sum.

```

``` c++
// hashing: let the value be the key of hash table 
//          and the index be the value of the hash table
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans(2,-1);
            unordered_map<int,int> hp;
          for(int i=0;i<nums.size();i++){
            hp[nums[i]]=i;}
          for(int i=0;i<nums.size();i++){
            
            if(hp.find(target-nums[i])!=hp.end()){
                if(hp[target-nums[i]]>i){
                    ans[0]=i,ans[1]=hp[target-nums[i]];
                }else if(hp[target-nums[i]]<i){
                    ans[1]=i,ans[0]=hp[target-nums[i]];
                }
            }
          }
            return ans;
        }
};
Runtime: 19 ms, faster than 83.13% of C++ online submissions for Two Sum.
Memory Usage: 12.2 MB, less than 8.15% of C++ online submissions for Two Sum.
```