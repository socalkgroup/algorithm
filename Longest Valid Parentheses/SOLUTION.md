# Longest Valid Parentheses



```py

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = []
        for i in range(len(s)):
            c = s[i]
            if c == '(':
                l.append(i)
            elif c == ')':
                if len(l) == 0:
                    l.append(i)
                else:
                    if s[l[-1]] == '(':
                        del l[-1]
                    else:
                        l.append(i)
        
        if len(l) == 0:
            return len(s)
        
        max_len = l[0]
        for i in range(1, len(l)):
            max_len = max(max_len, l[i]-l[i-1]-1)
        
        max_len = max(max_len, len(s) - l[-1]-1)
        
        return max_len


```
