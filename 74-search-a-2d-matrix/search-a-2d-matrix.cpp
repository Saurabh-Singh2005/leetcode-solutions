class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m= matrix.size();
       int n=matrix[0].size();
       int sr=0,er=m-1;
        while(sr<=er){
            int mid1=sr+(er-sr)/2;
            int l=0,r=n-1;
            if(matrix[mid1][0]<=target && target<=matrix[mid1][n-1]){
                int l=0,r=n-1;
                while(l<=r){
                    int mid2=l+(r-l)/2;
                    if(target==matrix[mid1][mid2]){
                        return true;
                    }
                else if(target<matrix[mid1][mid2]){
                    r=mid2-1;
                }
                else{
                    l=mid2+1;
                }
                }
                return false;
            }
            else if(target>=matrix[mid1][n-1]){
                sr=mid1+1;
            }
            else{
                er=mid1-1;
            }
        }
        return false;
    }
};