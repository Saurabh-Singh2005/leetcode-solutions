class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int srow=0,erow=m-1;
        int scol=0,ecol=n-1;
        vector<int> vec;
        while(srow<=erow && scol<=ecol){
       for(int j=scol;j<=ecol;j++){
        vec.push_back(matrix[srow][j]);
         }
         srow++;
       for(int i=srow;i<=erow;i++){
        vec.push_back(matrix[i][ecol]);
       
       }
       ecol--;
       if(srow<=erow){
       for(int j=ecol;j>=scol;j--){
        vec.push_back(matrix[erow][j]);
        
       }
       erow--;}
    if(scol<=ecol){
       for(int i=erow;i>=srow;i--){
        vec.push_back(matrix[i][scol]);
        }
       scol++;
       }}
       return vec;
    }
};