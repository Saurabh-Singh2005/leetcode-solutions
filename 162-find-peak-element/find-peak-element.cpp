class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        auto big=max_element(nums.begin(),nums.end());
        int bigidx=distance(nums.begin(),big);
        return bigidx;

    }
};