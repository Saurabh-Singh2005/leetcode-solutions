class Solution {
public:
    int reverse(int x) {
        long long rever=0;
     while(x!=0){
       int  digit=x%10;
       if(rever<INT_MIN/10 || rever>INT_MAX/10){
        return 0;
       }
        rever=rever*10+digit;
        x=x/10;
     }  
     return rever; 
    }
  
};