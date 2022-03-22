# Maximum Gap
- 給定一個整數陣列，回傳以升序排列好的陣列中兩個連續元素的最大差，若陣列只有小於兩個元素，回傳 0。
- English Version: Given an integer array, return the maximum difference between two successive elements in its sorted form (ascending) If the array contains less than two elements, return 0.

---
## pitfall(?
    - use the below to avoid TLE
    ```C++
    ios_base::sync_with_stdio(false);//need this to reduce input output time 
    cin.tie(NULL);//need this to reduce input output time 
    ```