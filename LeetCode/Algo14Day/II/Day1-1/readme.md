# 34. Find First and Last Position of Element in Sorted Array

- [link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=study-plan&id=algorithm-ii)

- Given an array of integers <code>nums</code> sorted in non-decreasing order, find the starting and ending position of a given <code>target</code> value.

- If target is not found in the array, return [-1, -1].
- You must write an algorithm with ***O(log n)*** runtime complexity.

#### Example 1
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
#### Example 2
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
#### Example 3
    Input: nums = [], target = 0
    Output: [-1,-1]

# Solution
- use binary search to search for target
- if the target does not exist, return -1,-1
- if the target exist, it may be in the center of a series of the targeted number 
    - binary search the left and right part respectively
    - details:
        - the search area approaches to two ends from the center of the array
        - use two flags to control the process of each part of the searching 
#### Note
- ```while(front<=end):```
    don't forget "<="(instead of "<") or the special case with one element will fail
- negation of !(a == b ***and*** a == c) is (a!=b ***or*** a!=c) 