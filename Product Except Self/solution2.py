def productExceptSelf(nums, m):
  prefixProduct = [1]*len(nums)
  suffixProduct = [1]*len(nums)  

  # setup the cumulative product from left and right
  for i in range(1,len(nums)):
    # Need parenthesis, as % has higher precedence than *
    prefixProduct[i] = (prefixProduct[i-1] * nums[i-1]) % m
    suffixProduct[-i-1] = (suffixProduct[-i] * nums[-i]) % m
  total = 0
  for i in range(len(nums)):
    # start at the end, with prefixProduct -1
    # and scan right
    total += (prefixProduct[i]*suffixProduct[i]) % m

  return total % m