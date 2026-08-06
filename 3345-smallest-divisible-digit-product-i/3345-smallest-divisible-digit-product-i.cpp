class Solution {
private:
    int prodOfDigits(int n){
        if(n == 0){
            return 0;
        }
        int prod = 1;
        while(n > 0){
            prod *= n%10;
            n /= 10;
            if(prod == 0){
                return 0;
            }
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
            if (prodOfDigits(n) % t == 0){
                return n;
            }
            else{
                n++;
            }
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna