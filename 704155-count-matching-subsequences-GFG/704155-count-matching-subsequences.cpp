class Solution {
  public:
    int countWays(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        int MOD = 1e9 + 7;

        vector<int> dp(n + 1, 0);
        
        dp[0] = 1; 

        
        for (int i = 1; i <= m; i++) {
            
            for (int j = n; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
            }
        }

        return dp[n];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna