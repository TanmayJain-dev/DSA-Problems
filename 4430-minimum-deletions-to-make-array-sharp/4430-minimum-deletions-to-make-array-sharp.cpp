class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 0, n = nums.size();

        for (int i = 0; i < n-1; i++){
            if (nums[i] == nums[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna