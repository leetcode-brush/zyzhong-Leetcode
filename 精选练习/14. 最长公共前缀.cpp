class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int index = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][index];
            for (auto str : strs) {
                if (str.length() == i || c != str[index])
                    return str.substr(0, index);
            }
            index++;
        }
        return strs[0].substr(0, index);
    }
};