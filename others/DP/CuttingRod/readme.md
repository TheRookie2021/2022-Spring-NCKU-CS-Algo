# dynamic programming- cutting rod
- How to cut steel rods into pieces in order to maximize the revenue you can get?
- Each cut is free. Rod lengths are always an integral number of inches.(extended: what if the cut is not free?)

# input/output
- Input: A length 𝑛 and table of prices 𝑝_𝑖, for 𝑖=1, 2, …, 𝑛.
- Output: the maximum revenue obtainable for rods whose lengths sum to 𝑛, computed as the sum of the prices for the individual rods .

# algorithm
- top-down recursion  
    - induction on length (optimal solution of each length is based on that of the shorter one(not necessarily the one former) )
    - still need to check the combination of each optimal solution (the current length and the shorter ones ): O(n^2)
    - need a static table to record the prices, and need a memory array to record the optimal ans of each length(so that we can calculate the unknown answer based on the one that had already been found)
    - be carefull of the boundary for iteration  
    - remember to initialize, and don't forget to set the memo[0]=0;
