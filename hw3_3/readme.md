#  10 . Smallest Range Covering Elements from k Lists
給定 k 個 lists ，每個 list 都已經為非遞減排列。
你的工作就是找出一個能至少能包含每個 list 其中一個數字並且為最小的範圍。
我們定義範圍 [a,b] 小於 [c,d] 為 b - a < d - c 或 a < c if b - a == d - c

 Smallest Range Covering Elements from k Lists: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

 heap: https://leetcode.com/tag/heap-priority-queue/

problem:
    a b c  a  b  c a b c
    0 3 10 11 12 18...
    1st. a~c: 10-0
    2nd. b~c: 11-3
    but in current algorithm, the second one would be skipped
    idea for sol.: see string search method in DS 