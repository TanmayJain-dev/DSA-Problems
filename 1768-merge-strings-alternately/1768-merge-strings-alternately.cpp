class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        for(int i = 0; i < (word1+word2).length(); i++){
            if (i < word1.length()) { result += word1[i]; }
            if (i < word2.length()) { result += word2[i]; }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna