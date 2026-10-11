class Solution {
public:
 int helper(int n,vector<int>& f){
    if(n==1 || n==2) return n;
    if(f[n] != -1){
        return f[n];
    }

    return f[n]=helper(n-1,f) + helper(n-2,f);

 }
    int climbStairs(int n) {
        vector<int> f(n+1,-1);
       return helper(n,f);
    }
};