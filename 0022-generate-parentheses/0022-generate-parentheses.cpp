class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        brackets("", 0, 0, n, result);
        return result;
    }
private:
    void brackets(string current, int open, int close, int n, vector<string>&result) {
        if(current.length()==2*n) {
            result.push_back(current);
            return;
        }
        if(open<n) {
            brackets(current + "(", open+1, close, n, result);
        }
        if(close<open) {
            brackets(current + ")", open, close+1, n, result);
        }


    }    
};