class Solution {
  public:
    int countWays(int n, int m) {
        vector<int> dp(n+1, 0);
        int MOD = 1e9 + 7;
        for (int i = 1; i <=n; i++){
            if (i == m){
                dp[i] = 2;
            }
            else if (i < m){
                dp[i] = 1;
            }
            else{
                dp[i] = (dp[i-1] + dp[i-m]) % MOD;
            }
        }
        return dp[n];
    }
};
        // if(n == m) {
        //     return 2;
        // }
        // else if (n < m) {
        //     return 1;
        // }
        // else {
        //     return countWays(n - 1,m) + countWays(n-m,m);
        // }

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna