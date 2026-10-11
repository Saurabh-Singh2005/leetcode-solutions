class Solution {
public:
    int helper(vector<int>& nums, int st, int end){
       int n = nums.size();
        vector<int> dp(n);
       int pre1 = nums[st];
       int pre2 = max(nums[st],nums[st+1]);
       int result = pre2;
       for(int i=st+2;i<=end;i++){
            result = max(pre2,pre1+ nums[i]);
            pre1 = pre2;
            pre2 = result;
       } 
       return result;
}

    int rob(vector<int>& nums) {
      
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
      return max( helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));
    }
};