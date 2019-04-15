class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m > 0 && n > 0);
        if (m == 1 || n == 1)
            return 1;
        return combination(min(m, n) - 1, m + n - 2);
    }
private:
    int com[100][100];
    int combination(int a, int b) {
        if (a == 0) return 1;
        if (a == b) return 1;
        return combination(a - 1, b - 1) + combination(a, b - 1);
    }
};