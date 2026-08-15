class Solution {
public:
    bool checkPow(int n){
        if(n<=0) return 0;
        while(n%4==0){
            n=n/4;
        }
        return n==1;
            }
    bool isPowerOfFour(int n) {
        return checkPow(n);
    }
};