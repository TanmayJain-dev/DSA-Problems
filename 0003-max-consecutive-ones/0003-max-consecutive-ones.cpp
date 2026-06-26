class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxc = 0, count = 0;
        for (int num:nums){
            if(num == 1){
                count++;
            }
            else{
                count = 0;
            }
            maxc = max(maxc, count);
        }
        return maxc;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna