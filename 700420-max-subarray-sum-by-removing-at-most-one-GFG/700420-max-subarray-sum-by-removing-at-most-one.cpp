class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
    if (arr.empty()) return 0;
        
        int max_no_skip = arr[0];
        int max_one_skip = arr[0];
        int overall_max = arr[0];
        
        for (size_t i = 1; i < arr.size(); ++i) {
            // Option 1: Add current to a previous skip
            // Option 2: Skip the current element entirely
            max_one_skip = std::max(max_one_skip + arr[i], max_no_skip);
            
            // Standard Kadane's: Start new subarray here or extend previous
            max_no_skip = std::max(arr[i], max_no_skip + arr[i]);
            
            // Keep track of the absolute maximum found
            overall_max = std::max({overall_max, max_no_skip, max_one_skip});
        }
        
        return overall_max;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna