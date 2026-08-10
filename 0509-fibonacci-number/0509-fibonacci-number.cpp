class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c = a + b;
        if (n == 0) {
            return a;
        } else if (n == 1) {
            return b;
        }
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna