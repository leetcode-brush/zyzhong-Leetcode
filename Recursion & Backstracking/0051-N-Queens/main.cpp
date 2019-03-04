class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);
        vector<int> rows;
        putQueen(n, 0, rows);
        return res;
    }
private:
    vector<vector<string>> res;
    vector<bool> col;
    vector<bool> dia1;
    vector<bool> dia2;
    void putQueen (int n, int index, vector<int> &rows) {
        if (index == n) {
            res.push_back(generatedBoard(n, rows));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
                rows.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n -1] = true;
                putQueen(n, index + 1, rows);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                rows.pop_back();
            }
        }
    }
    
    vector<string> generatedBoard(int n, vector<int> &rows) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][rows[i]] = 'Q';
        }
        return board;        
    }
};