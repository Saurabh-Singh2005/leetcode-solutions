class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n= nums.size();
        if(n==1)  return nums[0]*nums[0];
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                int num = nums[i-1];
                sum = sum + (num*num);
            }
        }
        return sum;
    }
};