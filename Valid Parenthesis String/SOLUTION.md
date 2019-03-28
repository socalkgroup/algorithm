# Valid Parenthesis String

```py
class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = []
        st = []
        
        for i in range(len(s)):
            c = s[i]
            
            if c == '(':
                l.append(i)
            elif c == '*':
                st.append(i)
            elif c == ')':
                if len(l) == 0 and len(st) == 0:
                    return False
                else:
                    if len(l) > 0:
                        del l[-1]
                    elif len(st) > 0:
                        del st[-1]
                    else:
                        return False
         
        while len(l) > 0:
            if len(st) == 0:
                return False
            
            if l[-1] < st[-1]:
                del l[-1]
                del st[-1]
            else:
                return False
              
        return True
```
