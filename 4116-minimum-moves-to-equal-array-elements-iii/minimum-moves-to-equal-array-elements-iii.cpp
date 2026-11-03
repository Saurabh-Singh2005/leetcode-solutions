class Solution {
public:
    int minMoves(vector<int>& nums) {
      int n = nums.size();
      int sum = accumulate(nums.begin(),nums.end(),0);
      int max = *max_element(nums.begin(),nums.end());
      return n*max-sum;  
    }
};