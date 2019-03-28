# Valid Parenthesis String

* string을 스캔한다.
* 두개의 리스트 (혹은 스택) 을 만들어 두고 스캔하면서 만난게 되는 스트링에 따라 각각 '(' 의 인덱스 (l), '*'의 인덱스 (st)를 저장한다. 
* 만약 만나게 되는 스트링이 ')' 인 경우, 'l 의 마지막 요소를 제거한다. 만약 l 가 비어있다면 st의 마지막 요소를 제거한다. 만약 둘다 비어있다면 False를 리턴한다.
* 스캔이 끝난 다음 l 의 마지막 요소에 대해 st의 마지막 요소보다 작은지 ( '(*' 가 되어 '()' 로써 valid한 형태를 체크) 를 보고 그렇다면 각각의 요로를 제거한다. 
* 위 단계는 l에 남은 요소가 없을때까지 반복한다. 만약 l의 마지막 요소가 st의 마지막 요소보다 크다면, valid 하지 않은것이 된다. (False 리턴)
* l이 비어있다면 valid 한것으로 간주 True를 리턴한다.

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
