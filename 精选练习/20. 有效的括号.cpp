class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 0) return false;
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) return false;
                if (c == ')') {
                    if ('(' == st.top()) {
                        st.pop();
                    }
                    else return false;
                } else if (c == '}') {
                    if ('{' == st.top()) {
                        st.pop();
                    }
                    else return false;
                } else if (c == ']') {
                    if ('[' == st.top()) {
                        st.pop();
                    }
                    else return false;
                }
            }
        }
        return st.empty();
    }
};