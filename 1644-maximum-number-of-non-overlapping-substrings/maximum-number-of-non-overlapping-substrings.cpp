class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, -1), end(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (start[c] == -1) start[c] = i;
            end[c] = i;
        }

       
        vector<pair<int, int>> valid_intervals; 

        for (int i = 0; i < 26; i++) {
            if (start[i] == -1) continue;

            int l = start[i], r = end[i];
            bool isValid = true;

            for (int j = l; j <= r; j++) {
                int c = s[j] - 'a';
               
                if (start[c] < l) {
                    isValid = false;
                    break;
                }
                r = max(r, end[c]); 
            }

            if (isValid) {
                valid_intervals.push_back({r, l});
            }
        }

       
        sort(valid_intervals.begin(), valid_intervals.end());

       
        vector<string> result;
        int last_end = -1;

        for (auto& interval : valid_intervals) {
            int r = interval.first;
            int l = interval.second;

            if (l > last_end) {
                result.push_back(s.substr(l, r - l + 1));
                last_end = r;
            }
        }

        return result;
    }
};