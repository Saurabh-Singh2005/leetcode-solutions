class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
     vector<int> ans;
     unordered_set<int> s;
     int n=grid.size();
     int a,b; 
     int  total=(n*n)*(n*n+1)/2; 
     int sum=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum=sum+grid[i][j];
            if(s.find(grid[i][j]) != s.end()){
                a=grid[i][j];
                ans.push_back(a);
               
            }
            s.insert(grid[i][j]);
        }}
        int miss=total-sum;
        
            ans.push_back(a+miss);
        
       
      
     return ans;
    }
};