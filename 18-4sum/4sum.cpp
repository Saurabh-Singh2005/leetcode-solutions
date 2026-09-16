class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;){
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r];
                    if(sum==target){
                     ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                     l++;r--;

                        while(l<r && nums[l] == nums[l-1]) l++;
                    }
                    else if(sum>target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
                j++;
                while(j<n && nums[j] ==nums[j-1]) j++;
            }
        }
        return ans;
    }
};