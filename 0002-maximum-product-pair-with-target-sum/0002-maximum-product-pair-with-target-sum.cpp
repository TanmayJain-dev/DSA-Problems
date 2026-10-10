class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        long long max_product = LLONG_MIN;
        vector<int> best_pair={-1,-1};

        for (int i = 0; i < nums.size(); ++i){
            int complement = target-nums[i];
            if(mp.find(complement) != mp.end() && nums[i] != complement){
                int j = mp[complement];
                long long cproduct = (long long) nums[i] * complement;

                if (cproduct > max_product) {
                    max_product = cproduct;

                    if(nums[i] > complement) {
                        best_pair = {i, j};
                    } else{
                        best_pair = {j, i};
                    }
                }
            }
            mp[nums[i]] = i;
        }

        return best_pair;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna