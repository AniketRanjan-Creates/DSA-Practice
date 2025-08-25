class Solution(object):
    def isPalindrome(self, s):
        cleaned = []
        for ch in s:
            if ch.isalnum():
                cleaned.append(ch.lower())
        str_cleaned = "".join(cleaned)
        st, end = 0, len(str_cleaned)-1
        while end>st :
            if str_cleaned[st]!=str_cleaned[end]:
                return False
            else: 
                st += 1
                end -= 1

        return True                   
        