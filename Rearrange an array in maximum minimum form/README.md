# Rearrange an array in maximum minimum form

* Given a sorted array of positive integers, rearrange the array alternately i.e first element should be the maximum value, second minimum value, third-second max, fourth-second min and so on.
```
Examples:
Input  : arr[] = {1, 2, 3, 4, 5, 6, 7, 10, 11} 
Output : arr[] = {11, 1, 10, 2, 7, 3, 6, 4, 5}
```

##Solution:
```
even index : remaining maximum element.
odd index  : remaining minimum element.
 
max_index : Index of remaining maximum element
            (Moves from right to left)
min_index : Index of remaining minimum element
            (Moves from left to right)

Initialize: max_index = 'n-1'
            min_index = 0  
            max_element = arr[max_index] + 1 

For i = 0 to n-1            
    If 'i' is even
       arr[i] += arr[max_index] % max_element * max_element 
       max_index--     
    ELSE // if 'i' is odd
       arr[i] +=  arr[min_index] % max_element * max_element
       min_index++
```

* The purpose of this expression is to store two elements at index arr[i]. arr[max_index] is stored as multiplier and “arr[i]” is stored as remainder. For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. With 91, we can get original element as 91%10 and new element as 91/10.

