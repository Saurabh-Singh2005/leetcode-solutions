class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> nonZero1, nonZero2;
        
       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) nonZero1.push_back({i, j});
                if (img2[i][j] == 1) nonZero2.push_back({i, j});
            }
        }
      
        map<pair<int, int>, int> shiftCount;
        int maxOverlap = 0;
        
        for (auto& p1 : nonZero1) {
            for (auto& p2 : nonZero2) {
                pair<int, int> shift = {p2.first - p1.first, p2.second - p1.second};
                shiftCount[shift]++;
                maxOverlap = max(maxOverlap, shiftCount[shift]);
            }
        }
        
        return maxOverlap;
    }
};