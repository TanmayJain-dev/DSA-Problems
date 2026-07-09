class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        unordered_map<int, int> rem_count;
        int count = 0;

        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            int comp = (k - rem) % k;

            if (rem_count.count(comp)) {
                count += rem_count[comp];
            }
            rem_count[rem]++;
        }

        return count;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna