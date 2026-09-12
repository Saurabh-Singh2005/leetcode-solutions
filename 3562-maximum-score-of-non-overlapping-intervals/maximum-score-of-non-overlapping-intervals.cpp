#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        
        vector<vector<long long>> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
       
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const vector<long long>& a, const vector<long long>& b) {
            return a[1] < b[1];
        });
        
    
        vector<long long> rights(n);
        for (int i = 0; i < n; ++i) {
            rights[i] = sorted_intervals[i][1];
        }
        
        
        using State = pair<long long, vector<int>>;
        
        vector<State> prev(n + 1, {0, {}}); // k = 0
        
        for (int k = 1; k <= 4; ++k) {
            vector<State> cur(n + 1, {0, {}});
            for (int p = 1; p <= n; ++p) {
              
                cur[p] = cur[p - 1];
                
                
                long long l = sorted_intervals[p - 1][0];
                long long w = sorted_intervals[p - 1][2];
                int idx = sorted_intervals[p - 1][3];
                
                
                int j = lower_bound(rights.begin(), rights.end(), l) - rights.begin();
                
                long long candidate_score = prev[j].first + w;
                vector<int> candidate_indices = prev[j].second;
                candidate_indices.push_back(idx);
                sort(candidate_indices.begin(), candidate_indices.end());
                
                State candidate = {candidate_score, candidate_indices};
                
               
                if (candidate.first > cur[p].first) {
                    cur[p] = candidate;
                } else if (candidate.first == cur[p].first && !candidate.second.empty()) {
                    if (cur[p].second.empty() || candidate.second < cur[p].second) {
                        cur[p] = candidate;
                    }
                }
            }
            prev =std:: move(cur);
        }
        
        return prev[n].second;
    }
};