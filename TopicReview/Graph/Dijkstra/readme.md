# Implementing Dijkstra Algorithm 
- [geekforgeek](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/)


# input/output
    Input:
    V = 2, E = 1
    u = 0, v = 1, w = 9
    adj [] = {{{1, 9}}, {{0, 9}}}
    S = 0
    Output:
    0 9
...  
    Input:
    V = 3, E = 3
    u = 0, v = 1, w = 1
    u = 1, v = 2, w = 3
    u = 0, v = 2, w = 6
    adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
    S = 2
    Output:
    4 3 0

# adj list or adj matrix
- syntax in c++: [array of vector](https://stackoverflow.com/questions/35501439/array-of-vectors-or-vector-of-arrays)
```
vector<int> adj[N]

```

# bug 
    - if the acendent(the node that has been visited) in the spanning tree is modified, we need to update all its decendent
    - intuitive sol: push that node into the queue again
