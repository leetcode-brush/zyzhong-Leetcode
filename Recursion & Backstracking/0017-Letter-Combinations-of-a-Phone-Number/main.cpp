class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if ( digits.empty())
            return res;
        findCombination(digits,  0, "");
        return res;
    }
private:
    const string letterMap[10] = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    
    void findCombination(const string &digits, int index, const string &s) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        string letters = letterMap[c - '0'];
        for (auto letter : letters)
            findCombination(digits, index + 1, s + letter);
        return;
    }
};