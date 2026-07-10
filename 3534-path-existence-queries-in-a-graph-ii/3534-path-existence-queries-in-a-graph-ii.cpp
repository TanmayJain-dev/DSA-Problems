class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        int max_jumps = log2(n) + 2;
        vector<vector<int>> up(n, vector<int>(max_jumps, -1));
        
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && nums[p[r]] - nums[p[l]] <= maxDiff) {
                r++;
            }
            up[p[l]][0] = p[r - 1];
        }

        for (int j = 1; j < max_jumps; ++j) {
            for (int i = 0; i < n; ++i) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (nums[u] > nums[v]) {
                swap(u, v);
            }

            int curr = u;
            int dist = 0;
            for (int j = max_jumps - 1; j >= 0; --j) {
                if (up[curr][j] != -1 && nums[up[curr][j]] < nums[v]) {
                    curr = up[curr][j];
                    dist += (1 << j);
                }
            }

            if (nums[up[curr][0]] >= nums[v] && nums[v] - nums[curr] <= maxDiff) {
                ans.push_back(dist + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna