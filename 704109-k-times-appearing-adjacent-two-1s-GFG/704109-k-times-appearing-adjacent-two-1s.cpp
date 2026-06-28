class Solution {
  public:
    int countStrings(int n, int k) {
        // If required adjacent 1s exceed possible pairs, it is impossible
        if (k >= n) return 0;
        
        const int MOD = 1e9 + 7;
        
        // dp[j][b] stores counts for j adjacent 1s ending in bit b (0 or 1)
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        
        // Base case for string of length 1
        dp[0][0] = 1; // String "0"
        dp[0][1] = 1; // String "1"
        
        // Dynamic programming for lengths from 2 to n
        for (int i = 2; i <= n; ++i) {
            vector<vector<int>> next_dp(k + 1, vector<int>(2, 0));
            
            for (int j = 0; j <= k; ++j) {
                // Appending '0': total adjacent 1s remains 'j'
                next_dp[j][0] = (dp[j][0] + dp[j][1]) % MOD;
                
                // Appending '1': if previous was '0', count remains 'j'
                next_dp[j][1] = dp[j][0]; 
                
                // Appending '1': if previous was '1', count increases, so we look at 'j-1'
                if (j > 0) {
                    next_dp[j][1] = (next_dp[j][1] + dp[j - 1][1]) % MOD;
                }
            }
            // Move current layer data to previous layer buffer
            dp = move(next_dp);
        }
        
        // Total valid configurations of length n ending in either '0' or '1'
        return (dp[k][0] + dp[k][1]) % MOD;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna