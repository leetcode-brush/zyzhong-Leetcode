class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int curd = 0, curx = 0, cury = 0;
        while (res.size() < m * n) {
            if (!visited[curx][cury]) {
                res.push_back(matrix[curx][cury]);
                visited[curx][cury] = true;
            }
            int nextx = curx + d[curd][0];
            int nexty = cury + d[curd][1];
            if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && !visited[nextx][nexty]) {
                curx = nextx;
                cury = nexty;
            } else {
                curd = (curd + 1) % 4;
            }
        }
        return res;
    }
};