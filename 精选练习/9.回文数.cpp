// 反转字符串
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        string tmp(s);
        reverse(s.begin(), s.end());
        if (tmp == s)
            return true;
        return false;
    }
};


//