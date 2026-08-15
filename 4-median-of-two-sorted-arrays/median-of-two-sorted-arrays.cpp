class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
        vector<int> vec;
        for(int val:nums1)
        vec.push_back(val);
        for(int val:nums2)
        vec.push_back(val);
        sort(vec.begin(),vec.end());
        int s = vec.size();
        if(s%2!=0){
            return vec[s/2];
        }
        else{
            return (vec[(s/2)-1]+vec[s/2]) /2.0;
        }
        
    }
};