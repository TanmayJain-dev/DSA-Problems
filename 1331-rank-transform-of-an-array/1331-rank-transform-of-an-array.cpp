class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> num_to_rank;
        for (int num : arr) {
            num_to_rank[num] = 0;
        }

        int rank = 1;
        for (auto& pair : num_to_rank) {
            pair.second = rank++;
        }

        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = num_to_rank[arr[i]];
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna