class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        if (n <= 0) return vector<vector<int>>{{}};
        vector<vector<int>> res(n, vector<int>(n, -1));
        int curd = 0, curx = 0, cury = 0, num = 1;
        while (num <= n * n) {
            if (res[curx][cury] == -1)
                res[curx][cury] = num++;
            int nextx = curx + d[curd][0];
            int nexty = cury + d[curd][1];
            if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && res[nextx][nexty] == -1) {
                curx = nextx;
                cury = nexty;
            } else {
                curd = (curd + 1) % 4;
            }
        }
        return res;
    }
};