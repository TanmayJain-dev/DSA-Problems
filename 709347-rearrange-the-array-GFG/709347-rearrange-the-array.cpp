class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

  public:
    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> visited(n + 1, false);
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int curr = i;
                int cycle_length = 0;
                
                // Traverse the cycle
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr - 1];
                    cycle_length++;
                }
                
                // Update the LCM of all cycle lengths
                ans = lcm(ans, cycle_length);
            }
        }
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna