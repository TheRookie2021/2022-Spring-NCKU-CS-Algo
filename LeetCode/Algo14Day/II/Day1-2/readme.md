# 33. Search in Rotated Sorted Array
- [link](https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=study-plan&id=algorithm-ii)
- There is an integer array ```nums``` sorted in ascending order (with distinct values).

- Prior to being passed to your function, ```nums``` is possibly rotated at an unknown pivot index k (1 <= k < ```nums.length```) such that the resulting array is  
 ```[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]``` (0-indexed). 
- For example, ```[0,1,2,4,5,6,7]``` might be rotated at pivot index ```3``` and become ```[4,5,6,7,0,1,2]```.

- Given the array ```nums``` after the possible rotation and an integer target, return the index of target if it is in ```nums```, or -1 if it is not in ```nums```.

- You must write an algorithm with ***O(log n)*** runtime complexity

#### Example 1
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
#### Example 2
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```
#### Example 3
```
Input: nums = [1], target = 0
Output: -1
```

# Solution
1. Get the asendent array(before being rotated) and its rotation point ```k``` (under ***O(log(n))*** )
2. Use binary search to find the index of the targeted number (index ```i```)
3. To output the index of targeted number in the rotated array, adjust the index ```i```(asendent array) with ```k``` (to index of the rotated array): 
    - if ***i < k*** : ```return len(nums)-k+i```
    - if ***i >= k*** : ```return i-k```

# Note 
- implement with the concept of virtual memory mapping 
    - rotated array as real memory address
    - ascending array as virtual memory address
    - binary search is implemented with virtual memory address
- details: 
    - there may be ***out of boundary*** index situation in binary search(which is a case to cease the while loop), so be sure to consider this case when converting the address (both Virtual to Real and Real to Virtual)