class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();

        int T = 0; 
        int R = m-1;
        int B = n-1;
        int L = 0;
        while (T<=B && L<=R) {
            for(int i = L; i<=R; i++) {
                result.push_back(matrix[T][i]);
            }
            T++;
            for(int i = T; i<=B; i++){
                result.push_back(matrix[i][R]);
            }
            R--;
            if(T<=B) {
                for(int i = R; i>=L; i--) {
                    result.push_back(matrix[B][i]);
                }
                B--;
            }
            if(L<=R) {
                for(int i = B; i>=T; i--){
                    result.push_back(matrix[i][L]);
                }
                L++;
            }

        }
        return result;
    }
};