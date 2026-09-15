class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> m;
      for(int i=0;i<nums.size();i++){
        int first=nums[i];
        int sec=target-first;
        if(m.find(sec) != m.end()){
            return {i,m[sec]};
        }
        m[first]=i;
      } 
      return { }; 
    }
};