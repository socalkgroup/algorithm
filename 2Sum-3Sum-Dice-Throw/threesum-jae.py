from collections import defaultdict

class Solution:            
    def threeSum(self, nums: List[int]) -> List[List[int]]:        
        nums.sort()
        output = set()
        dict = defaultdict(lambda :0)
        for n in nums:
            dict[n] = dict[n] + 1
            
        for i, n1 in enumerate(nums):
            dict[n1] = dict[n1]-1
            for i2 in range(i+1, len(nums)):
                n2 = nums[i2]
                n3 = -(n1+n2)
                if n3 in dict:            
                    dict[n2] = dict[n2]-1
                    dict[n3] = dict[n3]-1
                    if dict[n1]>=0 and dict[n2]>=0 and dict[n3]>=0:
                        val = [n1,n2,n3]
                        val.sort()
                        val = tuple(val)
                        if val not in output:
                            output.add(val)
                    dict[n2] = dict[n2]+1
                    dict[n3] = dict[n3]+1
            dict[n1] = dict[n1]+1
        
        return list(output)