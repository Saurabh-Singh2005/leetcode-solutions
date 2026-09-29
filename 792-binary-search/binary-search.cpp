class Solution {
public:
    int check(const vector<int>& nums,int target,int st,int end){
        if(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target) {return mid;}
            else if(nums[mid]<target){
                return check(nums,target,mid+1,end);
            }
            else{
                 return check(nums,target,st,mid-1);
            }
            
        }
    return -1;
    }
    int search(vector<int>& nums,int target) {
      
       return check(nums,target,0,nums.size()-1);
    }
};