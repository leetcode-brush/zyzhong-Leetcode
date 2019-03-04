class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0)
            return 0;
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);
        vector<int> rows;
        putQueen(n, 0, rows);
        return res;
    }
private:
    int res = 0;
    vector<bool> col, dia1, dia2;
    void putQueen(int n, int index, vector<int> &rows) {
        if (index == n) {
            res += 1;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
                rows.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                putQueen(n, index + 1, rows);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                rows.pop_back();            
            }
        }
    }
};