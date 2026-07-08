class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> sumD(n + 1, 0), cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0), pow10(n + 1, 1);
        
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i-1] * 10) % MOD;

        for (int i = 1; i <= n; ++i) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);
            p[i] = d ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int nz = cntN0[r + 1] - cntN0[l];
            int sum = sumD[r + 1] - sumD[l];
            long long x = (p[r + 1] - p[l] * pow10[nz] % MOD + MOD) % MOD;
            ans.push_back((x * sum) % MOD);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna