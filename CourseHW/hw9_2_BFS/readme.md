# find the shortest escape route

小邱終於很累地爬到了出口，結果小邱發現原來廁所被包圍在一個迷宮裡面。
所以他要再次想辦法走出這個迷宮。
由於小邱真的很累，所以請你告訴他用最省力的方式，最少要走多少步才能走到迷宮的出口。
# input/output
第一行輸入三個整數 N, M 代表總共有 N *M個格子。  
接下來有 4 個整數，分別為 S_x, S_y, T_x, T_y，代表小邱當前所在座標(S_x, S_y)，以及出口所在的座標(T_x, T_y)。  
注意座標皆從 1 開始編號。  
接下來有 N 行，每行有 M 個數字 X_{ij}。分別代表每一個格子小邱是否能夠通過，1 代表可以通過，而 0 則代表不能夠通過。
請輸出小邱至少要走幾步才能逃出迷宮，若無法逃出請輸出 -1。  

# pitfalls
- crutial tech: use queue to record each layer of the possible way, the dir variable is not recorded in queue 
- different from DFS, we must mark the step as we look it up, not as we actually step on it.
    e.g.  
```
    we are at (1,1) currently, and the terminal is at(2,4)
    1 1 1 1
    ^
    1 1 1 >1 
    1 1 1 1
    1 1 1 1

    if we mark the step only when we step on it, 
    a. mark
        0 1 1 1
        ^
        1 1 1 >1 
        1 1 1 1
        1 1 1 1
    b. push (1,2), (2,1)
        0 1 1 1
        ^
        1 1 1 >1 
        1 1 1 1
        1 1 1 1
    c.  go to (1,2) and pop()   
        0 0 1 1
        ^
        1 1 1 >1 
        1 1 1 1
        1 1 1 1
    d. push(1,3),(2,2)
        0 0 1 1
        ^
        1 1 1 >1 
        1 1 1 1
        1 1 1 1
    ...
    x. we are at (1,3), and the current queue stores:(2,2), (3,1), we will push(1,4),(2,3) 
        0 0 0 1
            ^
        0 1 1 >1 
        1 1 1 1
        1 1 1 1

    x. we are at (2,2), and the current queue stores:(3,1), (1,4), (2,3) we will push(2,3), (3,2) 
        0 0 0 1
        0 0 1 >1 
        ^
        1 1 1 1
        1 1 1 1

    notice: overlapping situation occurs!
    queue stores:(3,1), (1,4), (2,3), (2,3)
    ...
    queue stores:(2,3)... (2,4), (3,3)
    queue stores:... (2,4), (3,3),(2,4), (3,3) 

    redundent steps!!
```
---

<table>
<tr>
<th> bug </th>
<th> better </th>
</tr>
<tr>
<td>

    1 1 step: 0
    1 2 step: 1
    2 1 step: 1
    1 3 step: 2
    2 2 step: 2
    2 2 step: 2
    3 1 step: 2
    1 4 step: 3
    2 3 step: 3
    2 3 step: 3
    3 2 step: 3
    2 3 step: 3
    3 2 step: 3
    3 2 step: 3
    4 1 step: 3
    1 5 step: 4
    2 4 step: 4
    2 4 step: 4
    3 3 step: 4
    2 4 step: 4
    3 3 step: 4
    3 3 step: 4
    4 2 step: 4
    2 4 step: 4
    3 3 step: 4
    3 3 step: 4
    4 2 step: 4
    3 3 step: 4
    4 2 step: 4
    4 2 step: 4
    5 1 step: 4
    2 5 step: 5
    2 5 step: 5
    3 4 step: 5
    2 5 step: 5
    3 4 step: 5
    3 4 step: 5
    4 3 step: 5
    2 5 step: 5
    3 4 step: 5
    3 4 step: 5
    4 3 step: 5
    3 4 step: 5
    4 3 step: 5
    4 3 step: 5
    5 2 step: 5
    2 5 step: 5
    3 4 step: 5
    3 4 step: 5
    4 3 step: 5
    3 4 step: 5
    4 3 step: 5
    4 3 step: 5
    5 2 step: 5
    3 4 step: 5
    4 3 step: 5
    4 3 step: 5
    5 2 step: 5
    4 3 step: 5
    5 2 step: 5
    5 2 step: 5
    3 5 step: 6
    3 5 step: 6
    3 5 step: 6
    4 4 step: 6
    3 5 step: 6
    3 5 step: 6
    4 4 step: 6
    3 5 step: 6
    4 4 step: 6
    4 4 step: 6
    5 3 step: 6
    3 5 step: 6
    3 5 step: 6
    4 4 step: 6
    3 5 step: 6
    4 4 step: 6
    4 4 step: 6
    5 3 step: 6
    3 5 step: 6
    4 4 step: 6
    4 4 step: 6
    5 3 step: 6
    4 4 step: 6
    5 3 step: 6
    5 3 step: 6
    3 5 step: 6
    3 5 step: 6
    4 4 step: 6
    3 5 step: 6
    4 4 step: 6
    4 4 step: 6
    5 3 step: 6
    3 5 step: 6
    4 4 step: 6
    4 4 step: 6
    5 3 step: 6
    4 4 step: 6
    5 3 step: 6
    5 3 step: 6
    3 5 step: 6
    4 4 step: 6
    4 4 step: 6
    5 3 step: 6
    4 4 step: 6
    5 3 step: 6
    5 3 step: 6
    4 4 step: 6
    5 3 step: 6
    5 3 step: 6
    5 3 step: 6
    4 5 step: 7
    4 5 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    4 5 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    5 4 step: 7
    4 5 step: 7
    5 4 step: 7
    5 4 step: 7
    5 4 step: 7
    5 4 step: 7

</td>
<td>

    5 5
    1 1 5 5
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1

    1 1 step: 0
    1 2 step: 1
    2 1 step: 1
    1 3 step: 2
    2 2 step: 2
    3 1 step: 2
    1 4 step: 3
    2 3 step: 3
    3 2 step: 3
    4 1 step: 3
    1 5 step: 4
    2 4 step: 4
    3 3 step: 4
    4 2 step: 4
    5 1 step: 4
    2 5 step: 5
    3 4 step: 5
    4 3 step: 5
    5 2 step: 5
    3 5 step: 6
    4 4 step: 6
    5 3 step: 6
    4 5 step: 7
    5 4 step: 7
    8


</td>
</tr>
</table>
