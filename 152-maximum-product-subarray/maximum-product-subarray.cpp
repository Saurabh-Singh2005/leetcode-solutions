class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size(); 
      long long maxi = nums[0];
      long long mini = nums[0];
      long long result = nums[0];

      for(int i=1;i<n;i++){
            long long curr =nums[i];
            long long temp =maxi;
            maxi = max({curr,temp*curr,mini*curr});
            mini = min({curr,temp*curr,mini*curr});
            result = max(result,maxi);
      } 
      return result; 
    }
};