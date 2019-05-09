# Solution (Recursive)

## is\_match(text, pattern)
* 1. 글자와 패턴의 첫번째 부분이 같다면, 한글자씩 제한뒤 다시 펑션의 제귀 호출 (is\_match(text[1:], pattern[1:])
* 1-2.  만약 글자와 패턴의 첫번째 글자가 같은데 패턴의 두번째가 '\*' 라면, 글자만 한글자 제한 내용에 대한 펑션 콜, 그리고 '\*' 을 포함한 패턴만 제외한 펑션콜 두개를 호출하여 둘중 하나만 만족하면 매치 하는것으로 한다.
* 2. 패턴중 첫번째 부분이 '.' 라면 글자 패턴 한글자씩 제한뒤 다시 펑션 제귀 호출
* 2-2. 패턴의 첫글자가 '.' 인데 두번째 글자가 '\*' 이라면, 1-2와 마찬가지로, '.\*' 패턴만 제외하고 펑션 제귀 호출, 또는 글자만 하나 제외 후 제귀 호출하여 둘중 하나라도 만족하면 매치 된것으로 한다. 

다음은 리트코드의 솔루션이다. 
https://leetcode.com/problems/regular-expression-matching/solution/

```py
class Solution(object):
    def isMatch(self, text, pattern):
        if not pattern:
            return not text

        first_match = bool(text) and pattern[0] in {text[0], '.'}

        if len(pattern) >= 2 and pattern[1] == '*':
            return (self.isMatch(text, pattern[2:]) or
                    first_match and self.isMatch(text[1:], pattern))
        else:
            return first_match and self.isMatch(text[1:], pattern[1:])
``` 
  
