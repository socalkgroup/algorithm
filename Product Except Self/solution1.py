def productExceptSelf(nums, m):
    p = 1
    g = 0
    for x in nums:
        g = (g * x + p) % m
        p = (p * x) % m
    return g