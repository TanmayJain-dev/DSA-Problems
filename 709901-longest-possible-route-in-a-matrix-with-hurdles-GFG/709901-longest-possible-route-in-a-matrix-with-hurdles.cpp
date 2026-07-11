class Solution {
public:
    int max_len = -1;
    int n, m;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& mat, int r, int c, int xd, int yd, int curr_len) {
        if (r == xd && c == yd) {
            max_len = max(max_len, curr_len);
            return;
        }

        mat[r][c] = 0;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                dfs(mat, nr, nc, xd, yd, curr_len + 1);
            }
        }

        mat[r][c] = 1;
    }

    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        if (mat.empty() || mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
        
        n = mat.size();
        m = mat[0].size();
        max_len = -1;

        dfs(mat, xs, ys, xd, yd, 0);
        return max_len;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna