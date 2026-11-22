class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return 0;
        }
        
        long long ans = LLONG_MAX;
        int a = 0;
        while (a < n) {
            int b = a;
            while (b + 1 < n && nums[b+1] == nums[a]) {
                b++;
            }

            if (a == 0 && b == n-1) {
                return 0;
            }

            long long v = nums[a];
            int p = max(a,1);
            int s = min(b, n-2);
            if (p <= s) {
                if (a == 0) {
                    ans = min (ans, 1LL * (n - 1 - s)*v);
                } else if (b == n-1) {
                    ans = min (ans, 1LL * p * v);
                } else {
                    ans = min (ans, 1LL * (p+(n-1-s))*v);
                }
            }

            a = b + 1;
        }
        return ans == LLONG_MAX ? -1:ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna