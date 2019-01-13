# Longest Palindromic substring of given string

* https://articles.leetcode.com/longest-palindromic-substring-part-i/
* https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

## Solution:
* The longest common suffix has following optimal substructure 

|   | L  | C  | L  | C |
|---|---|---|---|---|
| C | 0 | 1 | 0 | 1 |
| L | 1 | 0 | 2 | 0 |
| C | 0 | 2 | 0 | 3 |
| L | 1 | 0 | 3 | 0 |


```
LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1]  otherwise 0
X = Abccdef , Y = Acdeff 
LCSuff(X,Y,1,1) = LCSuff(X,Y,0,0) + 1 since X[0] == Y[0]
```

* The maximum length Longest Common Suffix is the longest common substring.
```
  LCSubStr(X, Y, m, n)  = Max(LCSuff(X, Y, i, j)) where 1 <= i <= m
                                                     and 1 <= j <= n
```
* Complexity of the above implementation is `O(m*n)` which is much better than the worst case time complexity of Naive Recursive implementation
