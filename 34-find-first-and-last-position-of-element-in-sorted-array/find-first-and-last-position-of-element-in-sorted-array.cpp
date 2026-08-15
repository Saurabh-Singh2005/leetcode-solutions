class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        auto lb = lower_bound(nums.begin(),nums.end(),target);
        auto ub = upper_bound(nums.begin(),nums.end(),target);
        int lbidx=distance(nums.begin(),lb);
        int ubidx=distance(nums.begin(),ub);
        if(lbidx==ubidx){
            return {-1,-1};
        }
        else{
            return {lbidx,ubidx-1};
        }
        
    }
};