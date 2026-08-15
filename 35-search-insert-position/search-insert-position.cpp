class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    auto ub = lower_bound(nums.begin(),nums.end(),target);
    int ubidx=distance(nums.begin(),ub);
    
    return ubidx;
    }
};