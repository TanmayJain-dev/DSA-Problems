class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int dom = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[i] >= nums[i+1]){
                    dom++;
                }
                continue;
            }
            if (i == n-1) {
                if (nums[i] >= nums[i-1]){
                    dom++;
                }
                continue;
            }
            
            
            if (nums[i] >= (nums[i-1] + nums[i+1])/2.0){
                dom++;
            }
        }
        return dom;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna