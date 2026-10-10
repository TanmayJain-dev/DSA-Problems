class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1;
        int i = 0;

        while (i < n) {
            int r = (nums[i] % k + k) % k;
            int j = i;

            while (j < n && ((nums[j] % k + k) % k) == r) {
                j++;
            }

            int B = j - i;
            int curr_max = 1;

            if (r == 0){
                curr_max = B;
            } else {
                int M = k/gcd(r,k);
                curr_max = 1 + ((B-1) / M) * M;
            }

            max_len = max(max_len, curr_max);
            i = j;
        }

        return max_len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna