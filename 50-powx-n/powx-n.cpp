class Solution {
public:
    double myPow(double x, int n) {
      long bin=n;
      
      if(n==0) return 1.0;
      if(x==0) return 0.0;
      if(n<0){
        x=1/x;
        bin=-bin;
      }
      double ans=1;
     
     while(bin>0){
        if(bin%2==1){
            ans=ans*x;
        }
        x=x*x;
        bin=bin/2;
     } 
     return ans;  
    }
};