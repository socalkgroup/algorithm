# ProductExceptSelf

* You have an array nums. We determine two functions to perform on nums. In both cases, n is the length of nums:
* fi(nums) = nums[0] · nums[1] · ... · nums[i - 1] · nums[i + 1] · ... · nums[n - 1]. (In other words, fi(nums) is the product of all array elements except the ithf.)
* g(nums) = f0(nums) + f1(nums) + ... + fn-1(nums).
* Using these two functions, calculate all values of fmodulo the given m. Take these new values and add them together to get g. You should return the value of g modulo the given m.
```
Example
For nums = [1, 2, 3, 4] and m = 12, the output should be
productExceptSelf(nums, m) = 2.
The array of the values of f is: [24, 12, 8, 6]. If we take all the elements modulo m, we get:
[0, 0, 8, 6]. The sum of those values is 8 + 6 = 14, making the answer 14 % 12 = 2.
```
* Input/Output
    * `[input]` array.integer nums
    * Guaranteed constraints:
    * 2 ≤ nums.length ≤ 2 · 105,
    * 1 ≤ nums[i] ≤ 100.
    * `[input]` integer m
    * Guaranteed constraints:
    * 2 ≤ m ≤ 105.
    * `[output]` integer

## 솔루션1
* 왼쪽과 오른쪽을 각각 구해서 서로 곱해주면 된다
* 이때 아끼지 않고 modular 연산을 틈날때마다 해주면 된다
```
    prefixProduct[i] = (prefixProduct[i-1] * nums[i-1]) % m
    suffixProduct[-i-1] = (suffixProduct[-i] * nums[-i]) % m
```
* 마지막에 prefix와  suffix product을 곱해주면서 또 모듈라 연산을 해준다
```
  for i in range(len(nums)):
    # start at the end, with prefixProduct -1
    # and scan right
    total += (prefixProduct[i]*suffixProduct[i]) % m
```
* 너무 나이브한 접근 방식. 두번 돌아야 한다. 한번만 돌려서 풀수도 있다
* 아래 코드 참고
```py
def productExceptSelf(nums, m):
    p = 1
    g = 0
    for x in nums:
        g = (g * x + p) % m
        p = (p * x) % m
    return g
```