class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long start = 1000; 

        while (n >= start) {
          
            totalCommas += (n - start + 1);
            
           
            start *= 1000;
        }

        return totalCommas;
    }
};