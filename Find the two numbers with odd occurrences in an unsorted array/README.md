# Find the two numbers with odd occurrences in an unsorted array

> Given an unsorted array that contains even number of occurrences for all numbers except two numbers. Find the two numbers which have odd occurrences in O(n) time complexity and O(1) extra space.

```
Examples:
Input: {12, 23, 34, 12, 12, 23, 12, 45}
Output: 34 and 45

Input: {4, 4, 100, 5000, 4, 4, 4, 4, 100, 100}
Output: 100 and 5000

Input: {10, 20}
Output: 10 and 20
```


## Solution: 

The followings are xor basic properties 

1) XOR of any number n with itself gives us 0, i.e., n ^ n = 0
2) XOR of any number n with 0 gives us n, i.e., n ^ 0 = n
3) XOR is cumulative and associative.

### Algorithm summary: 

First step is that  doing xor operate for all elements in input array. 

Let’s say that x and y are two numbers with odd occurrences, then xor2=x^y = a1^a2^...aN  where a1, a2..aN.are in unsorted array. 

Next step is that getting the rightmost set bit of xor2 to divided array elements into two groups. x and y will be in these two groups. 
Then using the rightmost set bit of xor2, divide the elements two group. One group is corresponding bit 0 and other other group is corresponding bit 1.  And if you doing XOR operate for each group, then you will get the solution x, y   from each group. 


