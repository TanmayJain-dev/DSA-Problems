class Solution {
  public:
    int find(vector<int>& arr) {
        long long x = 0; 
        
        for (int i = arr.size() - 1; i >= 0; --i) {
            x = (x + arr[i] + 1) / 2;
        }
        
        return x;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna