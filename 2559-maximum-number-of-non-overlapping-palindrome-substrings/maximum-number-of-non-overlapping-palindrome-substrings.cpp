class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1;

  
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
           
            int start1 = i - k + 1;
            if (start1 > last_end && isPalindrome(start1, i)) {
                count++;
                last_end = i;
                continue;
            }

            int start2 = i - k;
            if (start2 > last_end && isPalindrome(start2, i)) {
                count++;
                last_end = i;
            }
        }

        return count;
    }
};