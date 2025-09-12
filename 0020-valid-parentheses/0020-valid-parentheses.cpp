class Solution {
public:
    bool isValid(string s) {
        map<char, char> mpp {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;
        int i = 0;
        while(i<s.size()){
            if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')) {
                return false;
            } else if(s[i]=='{' || s[i]=='('|| s[i]=='['){
                st.push(s[i]);
            } else if (!st.empty() && s[i]==')' || s[i]=='}' || s[i]==']') {
                if(st.top()!=mpp[s[i]]){
                    return false;
                } else {
                    st.pop();
                }
            }
            i++;

        }
        if (st.empty()){
            return true;
        } else return false;    
        
    }
};