class Solution {
public:
    int minAddToMakeValid(string s) {
       
        int count=0;
        int mount=0;
        for(int i=0;i<=s.size()-1;i++){
            
            if(s[i] =='('){
               
                count++;
            }
            else {
               if(count>0){
                count--; }
                else{
                    mount++;
                }
            }
        }
        return count+mount;
    }
};