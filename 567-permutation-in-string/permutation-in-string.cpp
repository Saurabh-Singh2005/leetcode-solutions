class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int freq[26] = {0};
        
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        int wind = s1.size();

        for (int i = 0; i <= s2.size() - wind; i++) {
        
            int windfreq[26] = {0};
            int windidx = 0, idx = i;

          
            while (windidx < wind && idx < s2.length()) {
                windfreq[s2[idx] - 'a']++;
                windidx++;
                idx++;
            }

            if (isFreqSame(freq, windfreq)) {
                return true;
            }
        }

        return false;
    }
};