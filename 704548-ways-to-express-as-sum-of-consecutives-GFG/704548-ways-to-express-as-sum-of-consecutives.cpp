class Solution {
public:
    int getCount(int n) {
        while (n % 2 == 0) {
            n /= 2;
        }

        int odd_factors = 1;
        for (int i = 3; i * i <= n; i += 2) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            odd_factors *= (count + 1);
        }

        if (n > 1) {
            odd_factors *= 2;
        }

        return odd_factors - 1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna