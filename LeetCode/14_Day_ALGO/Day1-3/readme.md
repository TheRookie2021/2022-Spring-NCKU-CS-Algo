# 35. Search Insert Position
    Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
  
    You must write an algorithm with O(log n) runtime complexity.
# input/output

- Example 1:  
    Input: nums = [1,3,5,6], target = 5  
    Output: 2  
- Example 2:
    Input: nums = [1,3,5,6], target = 2  
    Output: 1  
- Example 3:  
    Input: nums = [1,3,5,6], target = 7  
    Output: 4  
    
# constraints
    1 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    nums contains distinct values sorted in ascending order.
    -10^4 <= target <= 10^4
---
# result
    Runtime: 4 ms, faster than 81.43% of C++ online submissions for Search Insert Position.
    Memory Usage: 9.7 MB, less than 72.66% of C++ online submissions for Search Insert Position.
# pitfalls
- O(lg n): binary search
- return the index where it would be if it were inserted in order: 
    if larger than the last mid, return (mid+1)    
    if smaller, return (mid) (because when inserted before, the index of new element will replace the mid, and that of mid will be mid +1) 