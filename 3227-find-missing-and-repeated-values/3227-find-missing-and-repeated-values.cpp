class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mpp;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) {
                mpp[grid[i][j]]++;
            }

        }
        int missing = -1;
        int d = -1;
        for(int i = 1; i<=n*m; i++){
            if(mpp[i]==2) d = i;
            if(mpp[i]==0) missing = i;
        }
        return {d, missing};
    }
};