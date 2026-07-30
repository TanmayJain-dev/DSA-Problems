class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0, n = word.length();
        //for 1st 8 chars we add 1 push, for next 8 we add 2 pushes
        while(n > 0){
            if(n > 24){
                cnt += 4*(n-24);
                n = 24;
            }
            else if(n > 16){
                cnt += 3*(n-16);
                n = 16;
            }
            else if(n > 8){
                cnt += 2*(n-8);
                n = 8;
            }
            else{
                cnt += n;
                n = 0;
            }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna