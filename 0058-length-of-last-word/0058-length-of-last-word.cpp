class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length()-1;
        while(i>=0 && isspace(s[i])){
            i--;
        }
        while (i>=0 && !isspace(s[i])) {
            length++;
            i--;
        }
        return length;
    }
};