class Solution(object):
    def reverseWords(self, s):
        rev = reversed(s.strip().split())
        return " ".join(rev)