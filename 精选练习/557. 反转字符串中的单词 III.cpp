class Solution {
public:
    string reverseWords(string s) {
        istringstream sin(s);
        string res = "";
        string t;
        sin >> t;
        reverse(t.begin(), t.end());
        res += t;
        while(sin >> t) {
            res += " ";
            reverse(t.begin(), t.end());
            res += t;
        }
        return res;
    }
};