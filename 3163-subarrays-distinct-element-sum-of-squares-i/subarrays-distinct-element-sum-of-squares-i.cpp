class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int total=0;
        for (int i=0;i<nums.size();i++){
            unordered_set<int> uni;
            for(int j=i;j<nums.size();j++){
                uni.insert(nums[j]);
                int count = uni.size();
                total= total+count*count;
            }
        }
        return total;
    }
};