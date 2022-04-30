# classic 0 1 knapsack problem with possible massive input number


# sol i have tried
- divide by 10 (don't work, there may be floating point)
- convert to hour format(don't work, min/60 may have floating pt, also how to deal with the remainder)
- minus by minimal input(don't work, not enough)
- convert to string(don't work, still exceeding)
- finally, change vector by using the property of the math structure [where i find the sol](https://www.quora.com/What-are-some-good-methods-for-saving-memory-in-dynamic-programming)
    - detail: we always and only look the row i-1, so the original memoization keeps too much unnecessary   information. In conclusion, we only need two rows. 
