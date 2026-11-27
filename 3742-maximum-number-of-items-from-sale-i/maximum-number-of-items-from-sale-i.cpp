#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 0;
        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
        }

        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> multiples_count(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (freq[f] > 0) {
                for (int m = f; m <= max_factor; m += f) {
                    multiples_count[f] += freq[m];
                }
            }
        }

        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            if (p > budget) continue;

            int first_copy_gain = multiples_count[f];

            for (int b = budget; b >= p; --b) {
                dp[b] = max(dp[b], dp[b - p] + first_copy_gain);
            }

            for (int b = p; b <= budget; ++b) {
                dp[b] = max(dp[b], dp[b - p] + 1);
            }
        }

        return dp[budget];
    }
};