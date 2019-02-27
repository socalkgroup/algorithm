from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = defaultdict(lambda: [])
        
        for i, val in enumerate(nums):
            dic[val].append(i)
            other_key = target - val
            
            if other_key == val and len(dic[val]) > 1:
                return dic[val][0:2]
            
            if other_key in dic and other_key != val:
                return [dic[other_key][0], dic[val][0]]
        return []
        