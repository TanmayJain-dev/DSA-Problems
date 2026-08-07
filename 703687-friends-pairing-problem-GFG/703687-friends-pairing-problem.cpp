class Solution {
  public:
    int countFriendsPairings(int n) {
        if (n <= 2) {
            return n;
        }
        
        long long prev_2 = 1; // f(n-2)
        long long prev_1 = 2; // f(n-1)
        long long current = 0;
        
        for (int i = 3; i <= n; ++i) {
            current = prev_1 + (i - 1) * prev_2;
            prev_2 = prev_1;
            prev_1 = current;
        }
        
        return current;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna