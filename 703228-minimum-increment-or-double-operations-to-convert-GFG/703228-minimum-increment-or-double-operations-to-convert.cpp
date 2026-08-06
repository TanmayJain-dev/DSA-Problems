//Minimum Increment or Double Operations to Convert

class Solution {
  private:
    bool isZeroArr(vector<int>& arr){
        for (int x : arr) {
            if (x != 0) return false;
        }
        return true;

    }
  public:
    int countMinOperations(vector<int>& arr) {
        int cnt = 0;
        while(true){
            if(isZeroArr(arr)){
                return cnt;
            }
            for(int i = 0; i < arr.size(); i++){
                if(arr[i]%2 != 0){
                    arr[i]--;
                    cnt++;
                }
            }
            if(isZeroArr(arr)){
                return cnt;
            }
            for(int i = 0; i < arr.size(); i++){
                    arr[i]/=2;
            }
            cnt++;
            
            
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna