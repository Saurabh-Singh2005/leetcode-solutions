class Solution {
public:
#include <iostream>

int getLength(int x) {
    if (x == 0) return 1;
    
    int count = 0;
    while (x != 0) {
        x /= 10;
        count++;
    }
    return count;
}

    bool isPalindrome(int x) {
        int n=getLength(x);
        std::string s = std::to_string(x);
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