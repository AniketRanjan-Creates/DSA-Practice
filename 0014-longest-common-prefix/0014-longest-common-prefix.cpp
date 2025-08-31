class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return " ";
        sort(strs.begin(), strs.end());
        string start = strs[0];
        string last = strs[strs.size()-1];
        int i = 0;
        while(i < start.size() && i<last.size() && start[i]==last[i]) {
            i++;
        }
        return strs[0].substr(0, i);
    }
};