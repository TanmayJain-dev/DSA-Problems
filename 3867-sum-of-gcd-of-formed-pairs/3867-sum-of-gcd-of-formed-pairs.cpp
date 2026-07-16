class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0], n = nums.size();
        long long sum = 0;
        for (int& num:nums){
            mx = max(mx, num);
            num = gcd(num, mx);
        }
        sort(nums.begin(), nums.end());

        for (int l = 0, r = n-1; l < r; l++, r--) {
            sum += gcd(nums[l], nums[r]);
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna