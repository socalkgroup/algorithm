# Longest Valid Parentheses

* DP 로 푸는 방법https://leetcode.com/problems/longest-valid-parentheses/solution/
* DP 로 푸는 방법과 stack 을 이용해서 푸는 방법이 있다. DP는 이해하기도 외우기도 어려우므로 stack 를 이용하는 방법을 추천한다. 
* step1. 주어진 string 을 스캔한다. 스택을 준비 해 놓고, '(' 가 올경우 인덱스를 push, ')'가 올경우 스택의 마지막이 '(' 인 경우 (= '()' 인 경우) 스택의 마지막을 pop 하고, 그렇지 않은 경우 스택에 해당 인덱스를 push 한다.
* step1 을 마치고 나면, 스택에는 valid 하지 않은 괄호의 인덱스가 남게 된다. (e.g. ')()()()(' -> [0, 7])
* step2. step1. 에서 생성한 인덱스들을 스캔하면서 인덱스들의 간격이 가장 넓은 곳을 찾으면 그것이 곧 longest valid parentheses의 길이가 된다. 
* 인덱스에 주의하세요. [0, 7] -> longest length = 6

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
