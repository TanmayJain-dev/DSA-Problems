class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1, sum = 0;
        sum = numbers[left] + numbers[right];
        while(left < right){
            if (sum == target) return {left+1, right+1};
            else if (sum > target) {sum -= numbers[right]; right--; sum+= numbers[right];}
            else {sum -= numbers[left]; left++; sum+= numbers[left];}
        }
        return {0,0};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna