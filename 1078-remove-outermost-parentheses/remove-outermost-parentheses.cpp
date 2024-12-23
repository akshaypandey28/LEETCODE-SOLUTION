class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int balance=0;
        for(char c:s){
            if(c=='('){
                balance++;
                if(balance>=2) ans.push_back(c);
            }
            else {
                balance--;
                if(balance>=1) ans.push_back(c);
            }
        }
        return ans;
    }
};