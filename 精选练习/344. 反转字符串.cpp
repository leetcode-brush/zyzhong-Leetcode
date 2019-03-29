class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if (len <= 0) return;
        for (int i = 0; i < len >> 1; i++)
            swap(s[i], s[len - i -1]);
    }
};