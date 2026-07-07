class Solution {
public:

    int removeZeroes(int n){
        int x = 0, i = 1, d;
        if (n == 0) {
            return 0;
        }
        while(n != 0){
            d = n % 10;
            if(d != 0){
                x += d*i;
                i *= 10;
            }
            n /= 10;
        }
        return x;
    }
    int sumOfDigits(int n){
        int sum = 0;
        while (n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    long long sumAndMultiply(int n) {
        long long x = removeZeroes(n);
        
        return x * sumOfDigits(x);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna