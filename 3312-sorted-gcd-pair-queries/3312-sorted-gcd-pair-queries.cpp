class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxNum = *max_element(nums.begin(), nums.end());
        
        // Count frequencies of each number in nums
        vector<int> freq(maxNum + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // countGcdPair[g] will store the exact number of pairs with GCD equal to g
        vector<long long> countGcdPair(maxNum + 1, 0);
        
        // Step 1 & 2: Process from maxNum down to 1
        for (int g = maxNum; g >= 1; --g) {
            long long total_multiples = 0;
            
            // Count how many elements in nums are multiples of g
            for (int multiple = g; multiple <= maxNum; multiple += g) {
                total_multiples += freq[multiple];
            }
            
            // Maximum possible pairs that have a common divisor 'g'
            long long pairs = total_multiples * (total_multiples - 1) / 2;
            
            // Step 3: Subtract pairs whose actual GCD is a larger multiple of g
            for (int multiple = 2 * g; multiple <= maxNum; multiple += g) {
                pairs -= countGcdPair[multiple];
            }
            
            countGcdPair[g] = pairs;
        }
        
        // Step 4: Build prefix sum array of the pair frequencies
        vector<long long> prefixCount(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            prefixCount[i] = prefixCount[i - 1] + countGcdPair[i];
        }
        
        // Answer each query using binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first index where prefix sum is strictly greater than q
            auto it = upper_bound(prefixCount.begin(), prefixCount.end(), q);
            ans.push_back(distance(prefixCount.begin(), it));
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna