class Solution {
public:
    bool checkValidString(string s) {
       stack<int> op;
       stack<int> st;
       for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            op.push(i);
        }
        else if(s[i] == '*'){
            st.push(i);
        }
        else{
            if(!op.empty()){
                op.pop();
            }else if(!st.empty()){
                st.pop();
            }else{
                return false;
            }
            }
        }
        while(!op.empty() &&  !st.empty()){
            if(op.top() > st.top()){
                return false;
            }
            op.pop();
            st.pop();
        }
            return op.empty();
       
    }
};