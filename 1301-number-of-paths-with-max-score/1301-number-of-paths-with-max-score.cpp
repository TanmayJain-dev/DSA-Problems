class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        
        // DP table for max scores initialized to -1 (unreachable)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // DP table for path counts initialized to 0
        vector<vector<int>> count(n, vector<int>(n, 0));
        
        dp[n - 1][n - 1] = 0;
        count[n - 1][n - 1] = 1;
        
        // Directions to move: right, down, or diagonally down-right
        int dirs[3][2] = {{0, 1}, {1, 0}, {1, 1}};
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // If it's the start cell or an obstacle, we skip calculation
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }
                
                int max_score = -1;
                long long path_count = 0;
                
                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    if (ni < n && nj < n && dp[ni][nj] != -1) {
                        if (dp[ni][nj] > max_score) {
                            max_score = dp[ni][nj];
                            path_count = count[ni][nj];
                        } else if (dp[ni][nj] == max_score) {
                            path_count = (path_count + count[ni][nj]) % MOD;
                        }
                    }
                }
                
                if (max_score != -1) {
                    dp[i][j] = (max_score + (board[i][j] == 'E' ? 0 : board[i][j] - '0')) % MOD;
                    count[i][j] = path_count;
                }
            }
        }
        
        // If final top-left cell is unreachable, return {0, 0}
        if (dp[0][0] == -1) {
            return {0, 0};
        }
        
        return {dp[0][0], count[0][0]};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna