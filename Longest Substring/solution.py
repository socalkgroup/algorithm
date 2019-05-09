## template에 따라 다시 만들어 본 버젼
class Solution:
    def lengthOfLongestSubstringKDistinct(self, input, k):

        if not input or k == 0:
            return 0

        begin = 0
        interval,counter = 0,0
        storage = {}

        for end in range(len(input)):
            ch = input[end]
            if ch not in storage:
                counter += 1
            storage[ch] = storage.get(ch,0)+1

            while counter > k:
                new_ch = input[begin]
                storage[new_ch]-=1
                if storage[new_ch]==0:
                    storage.pop(new_ch)
                    counter -= 1
                begin += 1
            interval = max(end-begin, interval)

        return interval+1

solution = Solution()
print(solution.lengthOfLongestSubstringKDistinct('eceba',2))