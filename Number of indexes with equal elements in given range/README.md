# Number of indexes with equal elements in given range

* Oct. 4th 2018
* Organizer : Taehyun Kim
* Source : https://www.geeksforgeeks.org/number-indexes-equal-elements-given-range/

## Question
```Given N numbers and Q queries, every query consists of L and R, task is to find the number of such integers i (L<=i<R) such that Ai=Ai+1. Consider 0-based indexing.
Examples :
Input : A = [1, 2, 2, 2, 3, 3, 4, 4, 4] 
        Q = 2 
        L = 1 R = 8 
        L = 0 R = 4 
Output : 5 
         2
Explanation: We have 5 index i which has Ai=Ai+1 in range [1, 8). We have 2 indexes i which have Ai=Ai+1 in range [0, 4]. 

Input :A = [3, 3, 4, 4] 
       Q = 2
       L = 0 R = 3
       L = 2 R = 3 
Output : 2 
         1
```

## Solution
We can answer queries in O(1) time. The idea is to precompute a prefix array prefixans such that prefixans[i] stores the total count of the index from 0 to i that obeys the given condition. prefixans[R-1]-prefix[L-1] returns the total count of index in the range [L, r) for every query.