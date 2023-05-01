# 278. First Bad Version
    you are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
  
    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
  
    You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

# input/output
- Example 1:  
    Input: n = 5, bad = 4  
    Output: 4  
    - Explanation:  
        call isBadVersion(3) -> false  
        call isBadVersion(5) -> true  
        call isBadVersion(4) -> true  
    Then 4 is the first bad version.

- Example 2:  
    Input: n = 1, bad = 1
    Output: 1
   
# constraints
    1 <= bad <= n <= 2^31 - 1  
---
# result
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.  
    Memory Usage: 5.9 MB, less than 68.79% of C++ online submissions for First Bad Version.
# pitfalls
- by description, the index starts at 1 and ends at n
- still, be aware of the boundary in terms of the strategy you use ( peek the element one before the mid element)
- data type: use long long int to avoid overflow (see the constrains of this problem)
