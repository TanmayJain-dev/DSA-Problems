#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstring(string& s) {
        int n = s.length();
        
        // Fenwick tree flat storage size (Range from -n to +n)
        int tree_size = 2 * n + 2;
        vector<int> bit(tree_size + 1, 0);
        
        // Lambda helper for Fenwick Tree Update
        auto update = [&](int idx, int delta) {
            while (idx <= tree_size) {
                bit[idx] += delta;
                idx += idx & (-idx);
            }
        };
        
        // Lambda helper for Fenwick Tree Query
        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };
        
        // Offset ensures all negative running prefix balances scale to positive tree indices
        int offset = n + 1;
        
        // Base Case: A prefix sum of 0 exists 1 time before processing any characters
        update(0 + offset, 1);
        
        long long total_substrings = 0;
        int current_prefix_sum = 0;
        
        for (char c : s) {
            if (c == '1') {
                current_prefix_sum += 1;
            } else {
                current_prefix_sum -= 1;
            }
            
            // Add all previous positions where prefix_sum < current_prefix_sum
            total_substrings += query(current_prefix_sum + offset - 1);
            
            // Record the current prefix sum state into the tree
            update(current_prefix_sum + offset, 1);
        }
        
        return static_cast<int>(total_substrings);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna