class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        visited[r][c] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && mat[nr][nc] >= mat[r][c]) {
                dfs(nr, nc, visited, mat);
            }
        }
    }

public:
    int countCoordinates(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        
        for (int j = 0; j < m; ++j) {
            dfs(0, j, reachP, mat);
            dfs(n - 1, j, reachQ, mat);
        }
        
        for (int i = 0; i < n; ++i) {
            dfs(i, 0, reachP, mat);
            dfs(i, m - 1, reachQ, mat);
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (reachP[i][j] && reachQ[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna