class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0) return result;
        result.push_back({1});
        for(int i = 1; i<numRows; i++) {
            vector<int> current;
            const vector<int>& prev = result[i-1];
            current.push_back(1);
            for(int j = 1; j<i; j++) {
                current.push_back(prev[j-1]+prev[j]);
            }
            current.push_back(1);
            result.push_back(current);
        } 
        return result;
        
    }
};