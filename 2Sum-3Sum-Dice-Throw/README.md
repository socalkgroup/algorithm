# Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you many not use the same element twice

https://leetcode.com/problems/two-sum

## Example
```
Given nums = [2,7, 11, 15], target = 9
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0,1]
```

### Things to consider
* What if the same elements repeat? (e.g [3,3,5] target: 6)
    * How to save the values in the original array of integers

# Three Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c0? Find all unique triplets in the array which gives the sum of zero.

## Note
The solution set must not contain duplicate triplets.

https://leetcode.com/problems/3sum

## Example
```
Given array nums = [-1, 0, 1, 2, -1, -4]

A solution set is :
[
    [-1,0,1],
    [-1,-1,2]
]
```

# Dice Throw
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X, X is the summation of values on each face when all the dice are thrown.