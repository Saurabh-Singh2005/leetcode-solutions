
class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        std::vector<int> dp(n, INT_MAX); 
        
        int minTotal = INT_MAX;
        int windowSum = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            windowSum += arr[r];

            while (windowSum > target) {
                windowSum -= arr[l];
                l++;
            }

        
            if (windowSum == target) {
                int currentLen = r - l + 1;

               
                if (l > 0 && dp[l - 1] != INT_MAX) {
                    minTotal = std::min(minTotal, currentLen + dp[l - 1]);
                }

              
                dp[r] = (r > 0) ? std::min(dp[r - 1], currentLen) : currentLen;
            } else {
          
                dp[r] = (r > 0) ? dp[r - 1] : INT_MAX;
            }
        }

        return (minTotal == INT_MAX) ? -1 : minTotal;
    }
};