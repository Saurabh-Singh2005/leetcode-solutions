class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                ans |= nums[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }
        return ans;
    }
};