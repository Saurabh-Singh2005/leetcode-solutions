class Solution {
public:
    int maxArea(vector<int>& height) {
      int n=height.size();
      int l=0;
      int r=n-1;
      int maxwater=0;
      while(l<r){
       int  width=r-l;
       int high=min(height[l],height[r]);
       int area=width*high;
        maxwater=max(maxwater,area);
        height[l]>height[r]?r--:l++;
      }
      return maxwater;
    }
};