class Solution {
  public:
    int bitonic(std::vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        std::vector<int> inc(n, 1);
        std::vector<int> dec(n, 1);

        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        int max_len = inc[0] + dec[0] - 1;
        for (int i = 1; i < n; i++) {
            int current_len = inc[i] + dec[i] - 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }

        return max_len;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna