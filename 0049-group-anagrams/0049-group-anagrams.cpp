class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for(string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagrams[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it: anagrams) {
            result.push_back(it.second);

        }
        return result;
    }
};