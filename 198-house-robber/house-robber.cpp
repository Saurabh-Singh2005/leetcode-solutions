class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
       vector<int> dp(n);
      
       int pre1 = nums[0];
        int pre2 = max(nums[0],nums[1]);
        int result=pre2;

       for (int i=2;i<n;i++){
        result = max(pre2,pre1+nums[i]);
        pre1 = pre2;
        pre2 = result;

       }
       return pre2;
    }
};