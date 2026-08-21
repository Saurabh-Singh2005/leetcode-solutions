class Solution {
public:
#include <iostream>
    bool isPalindrome(int x) {
         std::string s = std::to_string(x);
        int n=s.size();
    
        int l=0;
        int r=n-1;
        while(l<=r){
             if(x<0){
                return 0;
            }
           else if(s[r]==s[l]){
            l++;
            r--;}
            
            else {
                return 0;
            }
        }
        return 1;
    }
};