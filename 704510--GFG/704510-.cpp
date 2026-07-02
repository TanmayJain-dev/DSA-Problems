class Solution{
    public:   

        bool divisibleByK(vector<int>& arr, int k) {
            int n = arr.size();
            if (n >= k) return true;
            
            vector<bool> dp(k, false);
            dp[0] = true; // Base case: empty subset
            
            for (int x : arr) {
                int rem = x % k;
                if (rem == 0) return true;
                
                vector<bool> next_dp = dp;
                for (int i = 0; i < k; i++) {
                    if (dp[i]) {
                        int new_rem = (i + rem) % k;
                        if (new_rem == 0) return true;
                        next_dp[new_rem] = true;
                    }
                }
                dp = next_dp;
            }
            return false;
        }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna