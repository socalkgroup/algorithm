class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        #Tokenizing
        token = []
        
        for i in range(len(p)):
            pp = p[i]
            if pp != '*':
                token.append((pp, False))
            else:
                token[-1] = (token[-1][0], True)
        
        return self.mm(s, token)
    
    def mm(self, s, t):
        if len(t) == 0: 
            return len(s) == 0
        
        is_match = bool(s) and ((s[0] == t[0][0]) or (t[0][0] == '.'))
        
        if t[0][1]: #if there is star
            return self.mm(s, t[1:]) or (is_match and self.mm(s[1:], t))
        else:
            return is_match and self.mm(s[1:], t[1:])
