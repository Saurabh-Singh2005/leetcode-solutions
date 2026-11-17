class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int changes = 0;
                        for (int rem = 0; rem < d; ++rem) {
                            int left = i + rem;
                            int right = j - (d - 1 - rem);
                            while (left < right) {
                                if (s[left] != s[right]) {
                                    ++changes;
                                }
                                left += d;
                                right -= d;
                            }
                        }
                        cost[i][j] = min(cost[i][j], changes);
                    }
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int parts = 1; parts <= k; ++parts) {
                for (int p = 0; p < i - 1; ++p) {
                    if (dp[p][parts - 1] != 1e9) {
                        dp[i][parts] = min(dp[i][parts], dp[p][parts - 1] + cost[p][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};