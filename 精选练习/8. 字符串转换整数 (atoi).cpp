class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i = 0, base = 0, sign = 1, n = str.size();
        while (i < n && str[i] == ' ')
            ++i;
        if (i < n && (str[i] == '+' || str[i] == '-'))
            sign = str[i++] == '+' ? 1 : -1;
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] > '7')) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = str[i++] - '0' +  base * 10;
        }
        return base * sign;
    }
};