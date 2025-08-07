class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s
        i = 0
        d = 1

        row = [[] for _ in range(numRows)]
        for char in s:
            row[i].append(char) 
            if i == 0:
                d = 1
            elif i == numRows-1:
                d = -1
            i = i + d
        ret = ''
        for i in range(numRows):
            ret = ret + "".join(row[i])
        return ret               
        
        