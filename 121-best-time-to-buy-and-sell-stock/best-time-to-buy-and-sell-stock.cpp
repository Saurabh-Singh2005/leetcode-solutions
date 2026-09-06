class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int mp=0;
      int bestbuy=INT_MAX;
      int profit=INT_MIN;
      for(int i=0;i<n;i++){
        bestbuy=min(bestbuy,prices[i]);
        mp=prices[i]-bestbuy;
        profit=max(profit,mp);
      } 
      return profit; 
    }
};