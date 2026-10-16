class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int mask=0;
        int maxlength=0;
        for(int i=0;i<nums.size();i++){
            while((mask & nums[i]) != 0){
                mask ^= nums[left];
                left++;
            }
            mask |=nums[i];
            maxlength = max(maxlength,i-left+1);
        }
            
        return maxlength;

    }
};