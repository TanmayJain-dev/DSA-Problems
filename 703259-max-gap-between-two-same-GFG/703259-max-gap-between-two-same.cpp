class Solution {
  public:
    int maxCharGap(string &s) {
        unordered_map<char, int> first_seen;
        int max_len = -1;
        for (int i = 0; i < s.length(); i++){
            char ch = s[i];
            if (first_seen.find(ch) != first_seen.end()) {
                max_len = max(max_len, i - first_seen[ch]-1);
            }   
            else{
                first_seen[ch] = i;
            }
        }
        return max_len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna