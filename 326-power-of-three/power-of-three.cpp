class Solution {
public:
    bool checkPow(int n){
        if(n<=0) return 0;
        while(n%3==0){
            n=n/3;
        }
        return n==1;
    }
    bool isPowerOfThree(int n) {
        return checkPow(n);
    }
};