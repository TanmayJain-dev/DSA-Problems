class Solution {
public:
    long long calculateGcdSum(vector<int>& prefixGcd) {
        int n = prefixGcd.size();
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            totalSum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return totalSum;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size(),mx = nums[0];
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        return calculateGcdSum(prefixGcd);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna